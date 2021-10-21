/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:54:42 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/19 20:15:37 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int		err_ctrl(char *reason, int fd)
{
	ft_putendl_fd(reason, fd);
	exit (0);
    return (1);
}

void    div_path (t_program *program, char **envp)
{
    int n = -1;
    int find_path;
    
    find_path = 0;
    while (envp[++n])
    {
        if (!ft_strncmp(envp[n], "PATH=", 5))
        {   
            program->path = ft_strdup(ft_strchr(envp[n], '/'));
            find_path = 1;
            break ;
        }
    }
    if (!find_path)
        err_ctrl("Error: couldn't find path", 1);
    //printf("%s\n", program->path);
    program->div_path = ft_split(program->path, ':');
    free(program->path);
}

void    split_argv(t_program *program, char **argv)
{
    /*this is for not bonus version*/
    program->fd_in = open(argv[1], O_RDONLY);
    if (program->fd_in == -1)
		err_ctrl("Error: No such file or directory", 1);
    program->command = ft_split(argv[2], ' ');
    program->fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (program->fd_out == -1)
		err_ctrl("Error: No have permission to open the file", 1);
}

void    parse_exists_cmd_path(t_program *program)
{
    char *aux_path;
    char *path_cmd;
    int n;
 
    n = -1;
    while (program->div_path[++n])
    {
        aux_path = ft_strjoin(program->div_path[n], "/");
        path_cmd = ft_strjoin(aux_path, program->command[0]);
        /*we need to know if the file contain in the path_cmd exists to execute them*/
        /*for this, we need to use de access command. These are de access command options*/
        /*F_OK:Test if file exists; R_OK:file can be read; W_OK:file can be write; X_OK:file can be execute*/
        if (!access(path_cmd, F_OK))
            {program->path_cmd = ft_strdup(path_cmd);
            break ;}
    }
    free (aux_path);
    free (path_cmd);
    //printf("ok path:%s\n", program->path_cmd);
}

void    child_process(t_program *program, char **envp)
{
    if (dup2(program->fd_in, STDIN_FILENO) == -1)
        err_ctrl("Error: dup2 c command failed", 1);
    close(program->fd_in);
     /*se queda después de esto y no se porque*/
    if (dup2(program->pipe[WRITE_END], STDOUT_FILENO) == -1)
        err_ctrl("Error: dup2 c command failed", 1);
    /*get path and execute with (execve)*/
    perror("Error");
    parse_exists_cmd_path(program);
    /*now execute the command. The execve only return if there is an error*/
    /*exceve has 3 arguments: path, argv, envp. argv and envp are the same as in main*/
    /*path contain de route path, and the file associate to the command*/
    if (execve(program->path_cmd, program->command, envp) == -1)
    {
        perror("Error");
        free (program->path_cmd);
        err_ctrl("Error: couldn't execute the command", 1);
    }
    perror("Error");
    /*if child process end, must close the write pipe for parent process can execute*/
    close(program->pipe[WRITE_END]);
}

void    parent_process(t_program *program, char **argv, char **envp)
{
    if (dup2(program->pipe[READ_END], STDIN_FILENO) == -1)
    err_ctrl("Error: dup2 c command failed", 1);
    close(program->pipe[READ_END]);
	if (dup2(program->fd_out, STDOUT_FILENO) == -1)
        err_ctrl("Error: dup2 c command failed", 1);
    close(program->fd_out);
    program->command = ft_split(argv[3], ' ');
    parse_exists_cmd_path(program);
    if (execve(program->path_cmd, program->command, envp) == -1)
    {
        free (program->path_cmd);
         err_ctrl("Error: couldn't execute the command", 1);
    }
}

void	pipex(t_program *program, char **argv, char **envp)
{
    pid_t	pid;

    if (pipe(program->pipe) == -1)
        err_ctrl("Error: Something went wrong with pipe(2)", 1);
    pid = fork();
    /*fork options*/
    if (pid < 0)
    {
        close(STDIN_FILENO);
		close(program->pipe[READ_END]);
		close(program->pipe[WRITE_END]);
        err_ctrl("Error: fork not work, couldn't create a child process", 1);
    }
    if (pid == 0)
    {
        /*close de read, because the begin of pipe is only write*/
        close(program->pipe[READ_END]);
        /*execute child process*/
        child_process(program, envp);
    }
    /*now could execute parent process*/
    //waitpid(pid, NULL, 0);
    //pid = fork();
	perror("Error");
    close(program->pipe[WRITE_END]);
    perror("Error");
    parent_process(program, argv, envp);
        

}

int main(int argc, char **argv, char **envp)
{
    t_program program;
    
    int n = -1;
    while (argv[++n])
        ++n;
    /*printf("%s\n", argv[n]);
    n = -1;
    while (envp[++n])
        printf("%s\n", envp[n]);*/
    if (argc != 5)
        return (err_ctrl("Error: more than valid arguments ; try like: ./pipex infile cmd1 cmd2 outfile", 1));
    else
    {
        div_path(&program, envp);
        split_argv(&program, argv);
        pipex(&program, argv, envp);
    }
    //system ("leaks pipex");
    return  (0);
}

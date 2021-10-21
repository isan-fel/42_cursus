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
    printf("%s\n", program->path);
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
        /*we need to know if the file contain en the path_cmd exists to execute them*/
        /*for this, we need to use de access command. These are de access command options*/
        /*F_OK:Test if file exists; R_OK:file can be read; W_OK:file can be write; X_OK:file can be execute*/
        perror("Error");
        if (access(path_cmd, F_OK) == 0)
            {program->path_cmd = ft_strdup(path_cmd);
            break ;
            }
    }
    free (aux_path);
        free (path_cmd);
        printf("ok path:%s\n", program->path_cmd);
}

void	pipex(t_program *program, char **envp)
{

  //waitpid(pid, NULL, 0);
        /*close de read, because the begin of pipe is only write*/
                /*execute child process*/
        /*if (dup2(program->fd_in, STDIN_FILENO) == -1)
            printf("error dup2\n");
        close(program->fd_in);*/
     /*se queda después de esto y no se porque*/
        /*if (dup2(program->fd_out, STDOUT_FILENO) == -1)
            printf("error dup2\n");
        close(program->fd_out);*/
        //parse_exists_cmd_path(program);
        perror("Error");
        program->path_cmd = ft_strdup("/usr/bin/ls");
        printf("ok path:%s\n", program->path_cmd);
        printf("f_OK:%d\n", access(program->path_cmd, F_OK));
        perror("Error");
        printf("r_OK:%d\n", access(program->path_cmd, R_OK));
        perror("Error");
        if (execve(program->path_cmd, program->command, envp) == -1)
         {
        free (program->path_cmd);
        perror("Error");
        //err_ctrl("Error: couldn't execute the command", 1);
        }      
        perror("Error");

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
        pipex(&program, envp);
    }
    return  (0);
}

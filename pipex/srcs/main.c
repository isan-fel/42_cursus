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

void    div_path (t_program *program, char **env)
{
    int n = -1;
    int find_path;
    
    find_path = 0;
    while (env[++n])
    {
        if (!ft_strncmp(env[n], "PATH=", 5))
        {   
            program->path = ft_strdup(ft_strchr(env[n], '/'));
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
    /*this is for not bonus verison*/
    program->fd_in = open(argv[1], O_RONLY);
    program->command_c = ft_split(argv[2], ' ');
    program->command_p = ft_split(argv[3], ' ');
    program->fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
}

void    child_process(t_program *program)
{
    dup2(program->fd_in, STDIN_FILENO);
    close(program->fd_in);
    dup2(program->pipe[WRITE_END], STDOUT_FILENO);
    close(program->pipe[WRITE_END]);
    /*get path and execute with (execve)*/
}

void	pipex(t_program *program)
{
    pid_t	pid;

    if (pipe(program->pipe) == -1)
        err_ctrl("Error: Something went wrong with pipe(2)", 1);
    pid = fork();
    program->command = ft_split(argv[2], ' ');
    /*fork options*/
    if (pid < 0)
    {
        close(STDIN_FILENO);
		close(program->pipe[READ_END]);
		close(program->pipe[WRITE_END]);
        err_ctrl("Error: fork not work, couldn't create a child process", 1);
    }
    waitpid(pid, NULL, 0);
    if (pid == 0)
    {
        close(program->pipe[READ_END]);
        child_process(program);
        /*execute child process*/
    }
    /*if child process end, must close the write pipe for parent process can execute*/
    close(pgm->pipe_fd[W_END]);
    /*now could execute parent process*/

        

}

int main(int argc, char **argv, char **env)
{
    t_program program;
    
    int n = -1;
    while (argv[++n])
        ++n;
    /*printf("%s\n", argv[n]);
    n = -1;
    while (env[++n])
        printf("%s\n", env[n]);*/
    if (argc != 5)
        return (err_ctrl("Error: more than valid arguments ; try like: ./pipex infile cmd1 cmd2 outfile", 1));
    else
    {
        div_path(&program, env);
        split_argv(&program, argv);
        pipex(&program);
    }
    return  (0);
}

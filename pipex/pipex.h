/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:50:43 by isan-fel          #+#    #+#             */
/*   Updated: 2021/10/19 20:05:21 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_program
{
    char *path;
    char **div_path;
    char **command;
    int  pipe[2];
    int  fd_in;
    int  fd_out;
} t_program;

void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t nbyte);
void	*ft_calloc (size_t num, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
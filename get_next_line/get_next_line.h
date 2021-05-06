/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:54:11 by isan-fel          #+#    #+#             */
/*   Updated: 2021/05/06 17:47:23 by isan-fel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>

# define BUFFER_SIZE 10

size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t nbyte);
void	*ft_calloc (size_t num, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_intchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int	get_next_line(int fd, char **line);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcat(char *dest, char *src);

#endif

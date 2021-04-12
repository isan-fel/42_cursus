# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 18:36:07 by isan-fel          #+#    #+#              #
#    Updated: 2021/04/12 12:50:42 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c \
					ft_bzero.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putnbr.c \
					ft_putstr.c \
					ft_strcat.c \
					ft_strchr.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strdup.c \
					ft_strlen.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strrchr.c \
					ft_strstr.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_itoa.c \
					ft_putchar.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c


OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				ranlib $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 18:36:07 by isan-fel          #+#    #+#              #
#    Updated: 2021/04/29 18:18:29 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c \
					get_next_line.c \
					get_next_line_utils.c \#
					
LIB				=	get_next_line.h


OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= nextline

all:			
			$(CC) $(CFLAGS) $(SRCS) $(LIB)

so:
			$(CC) $(CFLAGS) $(SRCS)
			gcc -shared -o libft.so $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re 

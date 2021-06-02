# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:43:00 by isan-fel          #+#    #+#              #
#    Updated: 2021/05/27 18:16:53 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

SRCS 	= 	ft_printf.c \
			ft_flags_conditions.c

LIBFT 	= 	libft/libft.a

OBJS 	= 	$(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -fPIC

GREEN 			= \033[0;32m
NO_COLOR 		= \033[0m

all: 		$(NAME)

$(LIBFT): 
			$(MAKE) -C ./libft

$(NAME): 	$(LIBFT) $(OBJS)
			cp $(LIBFT) $(NAME)
			ar -rcs $(NAME) $(OBJS)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

so:			$(LIBFT) $(OBJS)
			cp $(LIBFT) libftprintf.so
			ar -rcs libftprintf.so $(OBJS)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

clean:
			$(RM) $(OBJS)
			$(MAKE) fclean -C ./libft

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.SILENT:

.PHONY: 	all clean fclean re

test:		$(NAME)
			$(CC) -g3 -fsanitize=address $(CFLAGS) $(SRCS) libftprintf.so
			./a.out
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:43:00 by isan-fel          #+#    #+#              #
#    Updated: 2021/08/05 17:49:57 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	push_swap

SOURCES 	= 	main.c

DIR_S 		= 	srcs

SRCS 		= 	$(addprefix $(DIR_S)/, $(SOURCES))

LIBFT 		= 	libft/libft.a

OBJS 		= 	$(SRCS:.c=.o)

CC			= 	gcc
RM			= 	rm -f
CFLAGS		= 	-Wall -Werror -Wextra -fPIC

GREEN 		= 	\033[0;32m
YELLOW		=	\033[0;33m
NO_COLOR 	= 	\033[0m

all: 		$(NAME)

$(LIBFT): 
			$(MAKE) -C ./libft

$(NAME): 	$(OBJS) $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

so:			$(OBJS) $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) libft/libft.so -o $(NAME)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

test:		so
			./push_swap 2 3

clean:
			$(RM) $(OBJS)
			$(MAKE) fclean -C ./libft

fclean: 	clean
			$(RM) $(NAME)
			echo "$(YELLOW)---->> SUSCCESSFULLY CLEAN <<---- $(NO_COLOR)"

re: 		fclean all

.SILENT:

.PHONY: 	all clean fclean re test

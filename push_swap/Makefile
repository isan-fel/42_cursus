# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:43:00 by isan-fel          #+#    #+#              #
#    Updated: 2021/10/27 10:56:01 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	push_swap

SOURCES 	= 	main.c utils.c swap_and_rotate.c stack_less_hundred.c prueba.c

DIR_S 		= 	srcs

SRCS 		= 	$(addprefix $(DIR_S)/, $(SOURCES))

LIBFT 		= 	libft/libft.a

OBJS 		= 	$(SRCS:.c=.o)

CC			= 	gcc
RM			= 	rm -f
#CFLAGS		= 	-Wall -Werror -Wextra -fPIC
DEBUG       =       -g3 -fsanitize=address

GREEN 		= 	\033[0;32m
YELLOW		=	\033[0;33m
NO_COLOR 	= 	\033[0m

all: 		$(NAME)

$(LIBFT): 
			$(MAKE) -C ./libft

$(NAME): 	$(OBJS) $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) $(DEBUG) $(LIBFT) -o $(NAME)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

so:			$(OBJS) $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) libft/libft.so -o $(NAME)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

test:		so
			./push_swap 1 5 2 4 3

clean:
			$(RM) $(OBJS)
			$(MAKE) fclean -C ./libft

fclean: 	clean
			$(RM) $(NAME)
			echo "$(YELLOW)---->> SUSCCESSFULLY CLEAN <<---- $(NO_COLOR)"

re: 		fclean all

.SILENT:

.PHONY: 	all clean fclean re test

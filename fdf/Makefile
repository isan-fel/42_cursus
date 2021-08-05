# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:43:00 by isan-fel          #+#    #+#              #
#    Updated: 2021/08/05 17:57:23 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fdf

SOURCES 	= 	main.c \
				window.c \
				image.c \
				color.c \
				hooks.c

DIR_S 		= 	srcs

SRCS 		= 	$(addprefix $(DIR_S)/, $(SOURCES))

OBJS 		= 	$(SRCS:.c=.o)

CC			= 	gcc
RM			= 	rm -f
CFLAGS		= 	-Wall -Werror -Wextra -fPIC

LINKS 		= -lmlx -framework OpenGL -framework AppKit

GREEN 		= 	\033[0;32m
YELLOW		=	\033[0;33m
NO_COLOR 	= 	\033[0m

all: 		$(NAME)

$(NAME): 	$(OBJS)
			gcc $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

so:			$(OBJS)
			gcc $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)
			echo "$(YELLOW)---->> SUSCCESSFULLY CLEAN <<---- $(NO_COLOR)"

re: 		fclean all

.SILENT:

.PHONY: 	all clean fclean re

exe: 	all
		@echo "     - Executing $(NAME)... \n"
		@./$(NAME)
		@echo "\n     - Done -"

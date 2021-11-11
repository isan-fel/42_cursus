# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:43:00 by isan-fel          #+#    #+#              #
#    Updated: 2021/11/11 18:24:14 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fdf

SRCS 	= 	main.c \
			get_next_line.c \
			reader.c \
			map.c \
			hex_color.c

OBJS 		= 	$(SRCS:.c=.o)

RM			= 	rm -f
FLAGS		= 	-Wall -Werror -Wextra
#DEBUG		=	-g3 -fsanitize=address
#Links for compile minilibx on MACOS
LINKS 		=	-lmlx -framework OpenGL -framework AppKit
#Links for compile minilibx on Linux
LINKS_so		=	-lmlx -lXext -lX11
LEAKS 			=  valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all -s -q

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJS) $(DEBUG) libft/libft.a $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"
	@rm $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

so: $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@clang $(FLAGS) $(OBJS) $(DEBUG) libft/libft.so $(LINKS_so) -o $(NAME)
	@echo $(GREEN)"- Compiled -"
	@rm $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)


$(OBJS): $(SRCS)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRCS)

test: all
	@echo "     - Executing $(NAME)... \n"
	./$(NAME) maps/test_maps/42.fdf
	@echo "\n     - Done -"

testso: so
	@echo "     - Executing $(NAME)... \n"
	$(LEAKS) ./$(NAME) maps/test_maps/prueba2.fdf 
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all
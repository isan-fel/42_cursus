# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 15:39:03 by isan-fel          #+#    #+#              #
#    Updated: 2021/10/19 18:36:41 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	pipex

SOURCES 		= 	main.c 
UTILS_SOURCES	=	ft_putendl_fd.c ft_strlen.c ft_strdup.c ft_strncmp.c ft_strchr.c ft_substr.c ft_split.c ft_strjoin.c

DIR_S 			= 	srcs
DIR_UTILS_S 	= 	srcs/utils

SRCS 			= 	$(addprefix $(DIR_S)/, $(SOURCES))
SRCS_UTILS 		= 	$(addprefix $(DIR_UTILS_S)/, $(UTILS_SOURCES))

OBJS 			= 	$(SRCS:.c=.o)
OBJS_UTILS		= 	$(SRCS_UTILS:.c=.o)

CC			= 	gcc
RM			= 	rm -f
CFLAGS		= 	-Wall -Werror -Wextra
DEBUG		=	-g3 -fsanitize=address

GREEN 		= 	\033[0;32m
YELLOW		=	\033[0;33m
GREY 		=	\033[2;37m
CURSIVE 	=	\033[3m
NO_COLOR 	=	\033[0m

all: 		$(NAME)

$(NAME): 	$(OBJS) $(OBJS_UTILS)
			$(CC) $(FLAGS) $(DEBUG) $(OBJS) $(OBJS_UTILS) -o $(NAME)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

so:			$(OBJS) $(OBJS_UTILS)
			$(CC) $(FLAGS) $(OBJS) $(OBJS_UTILS) -o $(NAME)
			echo "$(GREEN)---->> SUSCCESSFULLY COMPILED <<---- $(NO_COLOR)"

test:		all
			@echo "$(GREY) **** Running test Pipex **** $(NO_COLOR)"
			@echo "$(GREY) **** ./pipex pru "cat -e" "grep hello" out **** $(NO_COLOR)"
			@./pipex pru "cat -e" "grep hello" out

clean:
			$(RM) $(OBJS) $(OBJS_UTILS)
			@echo "$(RED) **** Objects files removed **** $(NO_COLOR)"
			
fclean: 	clean
			$(RM) $(NAME)
			echo "$(YELLOW)---->> SUSCCESSFULLY CLEAN <<---- $(NO_COLOR)"

re: 		fclean all

.PHONY: 	all clean fclean re test

.SILENT:	$(OBJS) $(OBJS_UTILS)


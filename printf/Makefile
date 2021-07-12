# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isan-fel <isan-fel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:43:00 by isan-fel          #+#    #+#              #
#    Updated: 2021/07/12 17:27:35 by isan-fel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

SRCS 	= 	main.c \
			ft_printf.c \
			ft_utils.c \
			ft_save_flags.c \
			ft_save_flags_2.c \
			ft_write_int_flags.c \
			ft_int_preclen.c \
			ft_neg_prec_int.c \
			ft_write_char_flags.c \
			ft_write_string_flags.c \
			ft_write_hexa_flags.c \
			ft_uint_itoa.c

LIBFT 	= 	libft/libft.a

OBJS 	= 	$(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -fPIC

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
			$(CC) -g3 -fsanitize=address $(CFLAGS) $(SRCS) libftprintf.a
			./a.out
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 17:32:03 by jinoh             #+#    #+#              #
#    Updated: 2022/02/01 01:56:09 by jinoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libftprintf.a
LIBFT					= ./libft
LIBFT_LIB				= libft.a

SRCS					= ft_printf.c \
						  ft_printf_parse.c \
						  ft_printf_utils.c

BNS_SRCS				= ft_printf_bonus.c \
						ft_printf_char_bonus.c \
						ft_printf_int_bonus.c \
						ft_printf_uint_bonus.c \
						ft_printf_diu_utils_bonus.c \
						ft_printf_hexa_bonus.c \
						ft_printf_utils_bonus.c

OBJS					= $(SRCS:.c=.o)
BNS_OBJS				= $(BNS_SRCS:.c=.o)

FLAGS					= -Wall -Wextra -Werror

ifdef WITH_BNS
	OBJ_FILES = $(BNS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

$(NAME)		:	$(OBJ_FILES)
	@make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar -rcs $@ $^

all	:	$(NAME)

bonus	:
	@make WITH_BNS=1 $(NAME)

%.o	: %.c
	gcc $(FLAGS) -c $< -o $@ -I./

clean	:
	rm -f $(OBJS) $(BNS_OBJS)
	make clean -C $(LIBFT)

fclean	:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re	:	fclean all

.PHONY	:	all clean fclean re bonus

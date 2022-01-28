# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 17:32:03 by jinoh             #+#    #+#              #
#    Updated: 2022/01/28 21:35:11 by jinoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAN_NAME				= push_swap

BNS_NAME				= checker

LIBFT					= ./libft

LIBFT_LIB				= libft.a

SRCS					= push_swap.c \
						  push_swap_check_input.c \
						  push_swap_enqueue.c \
						  push_swap_enqueue_utils.c \
						  push_swap_lis.c \
						  push_swap_op_basic.c \
						  push_swap_operations_1.c \
						  push_swap_operations_2.c \
						  push_swap_operations_3.c \
						  push_swap_sort.c \
						  push_swap_sort_2.c \
						  push_swap_sort_utils.c \
						  push_swap_utils.c \

BNS_SRCS				= checker.c \

OBJS					= $(SRCS:.c=.o)
BNS_OBJS				= $(BNS_SRCS:.c=.o)

FLAGS					= -Wall -Wextra -Werror

ifdef WITH_BNS
	OBJ_FILES = $(BNS_OBJS)
	NAME = $(BNS_NAME)
else
	OBJ_FILES = $(OBJS)
	NAME = $(MAN_NAME)
endif

$(NAME)		:	$(OBJ_FILES)
	gcc $(FLAGS) -o $@ $^ -L $(LIBFT) -lft

all	:	$(NAME) $(LIBFT_LIB)

$(LIBFT_LIB) :
	@make -C $(LIBFT)

bonus	:
	@make WITH_BNS=1 $(NAME)

*.o	: *.c
	gcc $(FLAGS) -c $< -o $@ -I./

clean	:
	rm -f $(OBJS) $(BNS_OBJS)
	@make clean -C $(LIBFT)

fclean	:	clean
	rm -f $(MAN_NAME) $(BNS_NAME)

re	:	fclean all

.PHONY	:	all clean fclean re bonus

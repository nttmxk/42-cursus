# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 13:07:26 by jinoh             #+#    #+#              #
#    Updated: 2022/02/03 13:18:40 by jinoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1					= server
NAME_2					= client

SRCS_1					= server.c

SRCS_2					= client.c \
						client_utils.c

BNS_OBJS_1				= server_bonus.c

BNS_OBJS_2				= client_bonus.c \
						client_utils_bonus.c

OBJS_1					= $(SRCS_1:.c=.o)
OBJS_2					= $(SRCS_2:.c=.o)

BNS_OBJS_1				= $(BNS_SRCS_1:.c=.o)
BNS_OBJS_2				= $(BNS_SRCS_2:.c=.o)

FLAGS					= -Wall -Wextra -Werror

ifdef WITH_BNS
	OBJ_FILES_1 = $(BNS_OBJS_1)
	OBJ_FILES_2 = $(BNS_OBJS_2)
else
	OBJ_FILES_1 = $(OBJS_1)
	OBJ_FILES_2 = $(OBJS_2)
endif


$(NAME_1)	:	$(OBJ_FILES_1)
	gcc $(FLAGS) -o $@ $^

$(NAME_2)	:	$(OBJ_FILES_2)
	gcc $(FLAGS) -o $@ $^

all		:	$(NAME_1) $(NAME_2)

bonus	:
	make WITH_BNS=1 all

%.o	: %.c
	gcc $(FLAGS) -c $< -o $@ -I./

clean	:
	rm -f $(OBJS_1) $(OBJS_2) $(BNS_OBJS_1) $(BNS_OBJS_2)

fclean	:	clean
	rm -f $(NAME_1) $(NAME_2)

re	:	fclean all

.PHONY	:	all clean fclean re bonus

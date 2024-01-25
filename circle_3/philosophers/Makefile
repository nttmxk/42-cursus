# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 15:48:08 by jinoh             #+#    #+#              #
#    Updated: 2022/07/27 17:14:40 by jinoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= philo

SRCS					= philo.c \
						  philo_input.c \
						  philo_lifecycle.c \
						  philo_lifecycle2.c \
						  philo_lifecycle_utils.c \
						  philo_utils.c \

OBJS					= $(SRCS:.c=.o)

FLAGS					= -Wall -Wextra -Werror 

OBJ_FILES				= $(OBJS)


$(NAME)	:	$(OBJ_FILES)
	gcc $(FLAGS) -lpthread -o $@ $^

all		:	$(NAME)

%.o	: %.c
	gcc $(FLAGS) -Imlx -c $< -o $@ -I./

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

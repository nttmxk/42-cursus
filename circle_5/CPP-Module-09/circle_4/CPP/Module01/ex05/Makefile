NAME = harl_2
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	Harl.cpp \
		main.cpp

OBJS = $(SRCS:%.cpp=%.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
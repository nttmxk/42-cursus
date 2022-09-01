NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	Contact.cpp \
		PhoneBook.cpp \
		main.cpp

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re

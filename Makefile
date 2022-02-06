NAME					= fractal

SRCS					= main.c

BNS_SRCS				= test.c

OBJS					= $(SRCS:.c=.o)

BNS_OBJS				= $(BNS_SRCS:.c=.o)

#FLAGS					= -Wall -Wextra -Werror 
FLAGS					= -lmlx -framework OpenGL -framework Appkit

ifdef WITH_BNS
	OBJ_FILES = $(BNS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif


$(NAME)	:	$(OBJ_FILES)
	gcc $(FLAGS) -o $@ $^

all		:	$(NAME)

bonus	:
	make WITH_BNS=1 all

%.o	: %.c
	gcc $(FLAGS) -c $< -o $@ -I./

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re bonus

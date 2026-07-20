NAME = push_swap

SRC = push_swap.c operation.c list_utils.c sort_utils.c algorithm.c input_handling.c parser.c cost_analysis.c
OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

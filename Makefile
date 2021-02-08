.PHONY: all clean fclean 

SRCS		= ${wildcard srcs/*.c}

OBJS		= ${SRCS:.c=.o}

NAME		= bsq 

CC			= gcc

RM			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

.SILENT:

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

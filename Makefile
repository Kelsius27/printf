
SRCS	= ft_printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= clang
AR		= ar
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror
AFLAGS	= rc

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${AR} ${AFLAGS} ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJSBONUS}
			${AR} ${AFLAGS} ${NAME} ${OBJSBONUS}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

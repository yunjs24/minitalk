SRCS =		./utils/ft_putnbr_di.c \
			./utils/ft_putnbr_p.c \
			./utils/ft_putnbr_base.c \
			./utils/ft_putchar.c \
			./utils/ft_putstr.c \
			./utils/ft_strlen.c \
			./utils/ft_intlen.c \
			ft_printf.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc
RM			= rm -f
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:			
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			
			make fclean
			make all

.PHONY:		all clean fclean bonus re


CC = cc

CFLAGS =  -Wall -Werror -Wextra 

NAME = fractol

SRC	=  fractol.c additional_tools.c more_tools.c utils.c
			 

OBJS = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -fsanitize=address -lmlx -framework OpenGL -framework  AppKit -O3 -o $(NAME)
  
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
CC= cc

CFLAGS= -Wall -Wextra -Werror

HDR = fractol.h

SRC = fractol.c mandelbrot.c julia.c burningship.c hooks.c zoom.c outils.c

OBJ = $(SRC:.c=.o)

NAME = fractol

all: fractol

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf  $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
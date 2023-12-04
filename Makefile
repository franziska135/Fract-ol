NAME	=	fractol
INC		=	fractol.h
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
MLXFLAG	=	-lmlx -lXext -lX11 -g -lm
AR		=	ar rc
RM		=	rm -f

SRC		=	main.c setup.c events.c libft.c image.c mandelbrot.c \
			color.c julia.c

OBJ		=	$(SRC:.c=.o)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)	$(MLXFLAG)

%.o: %.c	$(INC)
#			$(CC) -c $< -o $@
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			clean all
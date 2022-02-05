NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar rc $(NAME) $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

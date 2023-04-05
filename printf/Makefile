NAME = libftprintf.a
SRC = ft_printf.c is_type.c print_lst.c put_lx.c put_sx.c put_u.c\
		libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_strchr.c libft/ft_strlen.c
OBJ = $(SRC:.c=.o)
HEAD = include/
ARFLAG = -rcs
CFLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -I$(HEAD) -o $@

clean :
	rm -f *.o libft/*.o

fclean : clean
	rm -f $(NAME)

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re
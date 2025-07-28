
NAME	=	libft.a
CC = gcc
CFLAGS	=	-Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

SRC	=	ft_atoi.c \
		ft_print_x_printf.c \
		ft_printf.c \
		ft_printstr_printf.c \
		ft_putchar_printf.c \
		ft_split.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strlen.c \
		print_char_printf.c \
		print_digits_printf.c \
		print_point_printf.c \
		print_u_printf.c

OBJ = $(SRC:.c=.o)

INCLUDE = libft.h

all: $(NAME)


$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

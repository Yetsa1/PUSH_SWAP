
NAME = push_swap

SRCS = initialice_and_print_stacks.c \
		movement_functions.c \
		parse.c \
		free.c \
		movement_functions2.c \
		movement_functions3.c \
		sort.c \
		index_stack.c \
		ksort.c \
		main.c

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

CFLAGS = -Wall -Wextra -Werror -g3

CC = gcc

$(NAME): $(SRCS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)
	make -C $(LIBFT_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) push_swap.h $(LIBFT_PATH)

.PHONY: all clean fclean re
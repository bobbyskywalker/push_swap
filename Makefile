CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS = src/list_operations/dll_lib.c src/list_operations/free_stack.c \
      src/stack_operations/rotate.c src/stack_operations/push.c src/stack_operations/swap.c \
      src/parser/parse_stack.c src/parser/sort_stack.c \
	  src/input_validation/format.c src/input_validation/validation.c \
	  src/input_validation/error_handler.c \
	  src/push_swap.c src/main.c

OBJS = $(SRCS:.c=.o)

LIBFT = lib/libft
LIBFT_LIB = $(LIBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean  # Clean libft too

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)
	make -C $(LIBFT) fclean  # Clean libft completely

re: fclean all

.PHONY: all clean fclean re

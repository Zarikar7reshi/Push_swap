CFLAGS = -Wall -Wextra -Werror -I. -g

NAME = push_swap

DEPS = push_swap.h stack.h

SRC = push_swap.c a.c b.c c.c is_num.c \
atoi_checked.c parse_args.c push_swap_utils.c \
sorting_utils.c stack.c stack_utils.c \
sorting.c stack_nodes.c small_sort.c

OBJS = $(SRC:.c=.o)

FT_PRINTF_LIB = ./printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_LIB)
	cc $(CFLAGS) $(OBJS) -Lprintf -lftprintf -o $(NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C ./printf

%.o: %.c $(DEPS)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./printf fclean

re: fclean all

.PHONY: all clean fclean re

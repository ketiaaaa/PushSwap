NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= push_swap.c \
			  adaptive_sort.c \
			  sort_small.c \
			  turk_cost.c \
			  turk_move.c \
			  turk_sort.c \
			  more_stack_utils.c \
			  operations_push.c \
			  operations_reverse.c \
			  operations_rotate.c \
			  operations_swap.c \
			  parse.c \
			  parse_utils.c \
			  stack_utils.c \
			  utils.c \
			  ft_strcmp.c \
			  bench_setup.c \
			  bench_ops.c \
			  bench_print.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

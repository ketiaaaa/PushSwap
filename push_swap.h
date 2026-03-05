/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:45:19 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 21:03:19 by krusha           ###   ########.fr
		      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_bench
{
	int		mode;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disorder;
	char	*strategy;
}	t_bench;

/* helper for incrementing counters */
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

/* Stack operations - push */
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

/* Stack operations - rotate */
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

/* Stack operations - reverse rotate */
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

/* Stack utils */
t_stack		*stack_new(int value);
t_stack		*stack_last(t_stack *stack);
void		stack_add_back(t_stack **stack, t_stack *new);
void		stack_free(t_stack **stack);
int			stack_size(t_stack *stack);
int			is_sorted(t_stack *stack);

/* Stack helpers */
int			find_min(t_stack *stack);
int			find_max(t_stack *stack);

/* Parsing */
t_stack		*parse_arguments(int argc, char **argv);
int			is_valid_number(char *str);
int			has_duplicates(t_stack *stack);
void		normalize_stack(t_stack *stack);

/* Bench tracking */
t_bench		*bench_ptr(void);
void		setup_bench(int mode, char *strategy);
int			bench_mode(void);
void		inc_op(t_op op);
void		calc_disorder(t_stack *stack);
void		print_bench(void);
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		sort_five(t_stack **a, t_stack **b);

/* Turk sort - cost */
int			get_position(t_stack *stack, int value);
int			get_target(t_stack *a, int b_val);
int			get_cost(t_stack *a, t_stack *b, int b_val);
void		set_costs(t_stack *a, t_stack *b);
t_stack		*get_cheapest(t_stack *b);

/* Turk sort - move */
void		move_a_to_top(t_stack **a, int target);
void		move_b_to_top(t_stack **b, int val);
void		do_move(t_stack **a, t_stack **b, t_stack *cheapest);

/* Turk sort - main */
void		turk_sort(t_stack **a, t_stack **b);

/* Adaptive sort entry point */
void		adaptive_sort(t_stack **a, t_stack **b);

/* Utility functions */
long		ft_atol(const char *str);
int			ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);

#endif

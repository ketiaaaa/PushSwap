/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:51:53 by krusha            #+#    #+#             */
/*   Updated: 2026/03/03 20:54:44 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_forward(t_stack **a, t_stack **b, int val)
{
	int	target;

	target = get_target(*a, val);
	while ((*a)->value != target && (*b)->value != val)
		rr(a, b);
}

static void	rotate_both_backward(t_stack **a, t_stack **b, int val)
{
	int	target;

	target = get_target(*a, val);
	while ((*a)->value != target && (*b)->value != val)
		rrr(a, b);
}

void	move_a_to_top(t_stack **a, int target)
{
	int	size;
	int	pos;

	size = stack_size(*a);
	pos = get_position(*a, target);
	if (pos <= size / 2)
	{
		while ((*a)->value != target)
			ra(a);
	}
	else
	{
		while ((*a)->value != target)
			rra(a);
	}
}

void	move_b_to_top(t_stack **b, int val)
{
	int	size;
	int	pos;

	size = stack_size(*b);
	pos = get_position(*b, val);
	if (pos <= size / 2)
	{
		while ((*b)->value != val)
			rb(b);
	}
	else
	{
		while ((*b)->value != val)
			rrb(b);
	}
}

void	do_move(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	val;
	int	target;
	int	pos_a;
	int	pos_b;

	val = cheapest->value;
	target = get_target(*a, val);
	pos_a = get_position(*a, target);
	pos_b = get_position(*b, val);
	if (pos_a <= stack_size(*a) / 2 && pos_b <= stack_size(*b) / 2)
		rotate_both_forward(a, b, val);
	else if (pos_a > stack_size(*a) / 2 && pos_b > stack_size(*b) / 2)
		rotate_both_backward(a, b, val);
	move_b_to_top(b, val);
	move_a_to_top(a, target);
	pa(a, b);
}

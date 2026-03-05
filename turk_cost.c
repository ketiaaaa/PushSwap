/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:51:47 by krusha            #+#    #+#             */
/*   Updated: 2026/03/03 18:51:48 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	get_target(t_stack *a, int b_val)
{
	t_stack	*tmp;
	int		best;
	int		target;

	best = INT_MAX;
	target = find_min(a);
	tmp = a;
	while (tmp)
	{
		if (tmp->value > b_val && tmp->value < best)
		{
			best = tmp->value;
			target = tmp->value;
		}
		tmp = tmp->next;
	}
	return (target);
}

int	get_cost(t_stack *a, t_stack *b, int b_val)
{
	int	pos_a;
	int	pos_b;
	int	ca;
	int	cb;

	pos_a = get_position(a, get_target(a, b_val));
	pos_b = get_position(b, b_val);
	if (pos_a <= stack_size(a) / 2)
		ca = pos_a;
	else
		ca = stack_size(a) - pos_a;
	if (pos_b <= stack_size(b) / 2)
		cb = pos_b;
	else
		cb = stack_size(b) - pos_b;
	if ((pos_a <= stack_size(a) / 2) == (pos_b <= stack_size(b) / 2))
	{
		if (ca > cb)
			return (ca);
		return (cb);
	}
	return (ca + cb);
}

void	set_costs(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = b;
	while (tmp)
	{
		tmp->index = get_cost(a, b, tmp->value);
		tmp = tmp->next;
	}
}

t_stack	*get_cheapest(t_stack *b)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	tmp = b;
	cheapest = b;
	while (tmp)
	{
		if (tmp->index < cheapest->index)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

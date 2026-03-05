/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:51:58 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 22:31:22 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smart_push(t_stack **a, t_stack **b)
{
	int	median;
	int	size;
	int	pushed;

	size = stack_size(*a);
	median = size / 2;
	pushed = 0;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index <= median)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if ((*a)->index < size - 1)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

static void	final_rotate_a(t_stack **a)
{
	int	min;
	int	size;
	int	pos;

	min = find_min(*a);
	size = stack_size(*a);
	pos = get_position(*a, min);
	if (pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	normalize_stack(*a);
	smart_push(a, b);
	sort_three(a);
	while (*b)
	{
		set_costs(*a, *b);
		do_move(a, b, get_cheapest(*b));
	}
	final_rotate_a(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:31:33 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 21:31:52 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inc_op(t_op op)
{
	t_bench	*bb;

	bb = bench_ptr();
	if (op == OP_SA)
		bb->sa++;
	else if (op == OP_SB)
		bb->sb++;
	else if (op == OP_SS)
		bb->ss++;
	else if (op == OP_PA)
		bb->pa++;
	else if (op == OP_PB)
		bb->pb++;
	else if (op == OP_RA)
		bb->ra++;
	else if (op == OP_RB)
		bb->rb++;
	else if (op == OP_RR)
		bb->rr++;
	else if (op == OP_RRA)
		bb->rra++;
	else if (op == OP_RRB)
		bb->rrb++;
	else if (op == OP_RRR)
		bb->rrr++;
}

void	calc_disorder(t_stack *stack)
{
	t_stack	*current;
	int		inversions;
	int		size;
	t_bench	*bb;

	bb = bench_ptr();
	inversions = 0;
	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			inversions++;
		current = current->next;
	}
	bb->disorder = ((double)inversions / (size - 1)) * 100;
}

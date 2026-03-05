/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:49:49 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 22:14:45 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*a || !(*a)->next)
		return ;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	inc_op(OP_RRA);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*b || !(*b)->next)
		return ;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	inc_op(OP_RRB);
	write(1, "rrb\n", 4);
}

static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	inc_op(OP_RRR);
	write(1, "rrr\n", 4);
}

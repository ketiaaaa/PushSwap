/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:50:42 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 22:14:58 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = stack_last(*a);
	*a = first->next;
	first->next = NULL;
	last->next = first;
	inc_op(OP_RA);
	write(1, "ra\n", 3);
}

void	rb(t_stack	**b)
{
	t_stack	*first;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = stack_last(*b);
	*b = first->next;
	first->next = NULL;
	last->next = first;
	inc_op(OP_RB);
	write(1, "rb\n", 3);
}

static void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	rr(t_stack	**a, t_stack	**b)
{
	rotate_stack(a);
	rotate_stack(b);
	inc_op(OP_RR);
	write(1, "rr\n", 3);
}

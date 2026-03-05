/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:32:25 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 22:53:09 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_ops1(t_bench *bb)
{
	dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		bb->sa, bb->sb, bb->ss, bb->pa, bb->pb);
}

static void	print_ops2(t_bench *bb)
{
	dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bb->ra, bb->rb, bb->rr, bb->rra, bb->rrb, bb->rrr);
}

void	print_bench(void)
{
	int		total;
	t_bench	*bb;

	bb = bench_ptr();
	if (!bb->mode)
		return ;
	total = bb->sa + bb->sb + bb->ss + bb->pa + bb->pb
		+ bb->ra + bb->rb + bb->rr + bb->rra + bb->rrb + bb->rrr;
	dprintf(2, "[bench] disorder: %.2f%%\n", bb->disorder);
	dprintf(2, "[bench] strategy: %s\n", bb->strategy);
	dprintf(2, "[bench] total_ops: %d\n", total);
	print_ops1(bb);
	print_ops2(bb);
}

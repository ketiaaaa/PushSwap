/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:30:56 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 22:08:59 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*bench_ptr(void)
{
	static t_bench	b;

	return (&b);
}

void	setup_bench(int mode, char *strategy)
{
	t_bench	*bb;

	bb = bench_ptr();
	bb->mode = mode;
	bb->strategy = strategy;
}

int	bench_mode(void)
{
	return (bench_ptr()->mode);
}

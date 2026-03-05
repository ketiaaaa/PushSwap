/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:51:21 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 21:16:54 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	handle_bench_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			setup_bench(1, "Adaptive / O(n√n)");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	handle_bench_flags(argc, argv);
	a = parse_arguments(argc, argv);
	b = NULL;
	if (bench_mode())
		calc_disorder(a);
	if (!is_sorted(a))
		adaptive_sort(&a, &b);
	print_bench();
	stack_free(&a);
	stack_free(&b);
	return (0);
}

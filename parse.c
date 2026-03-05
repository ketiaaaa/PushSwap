/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:51:12 by krusha            #+#    #+#             */
/*   Updated: 2026/03/05 21:14:48 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;

	current = stack;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}

static void	error_and_exit(t_stack **a)
{
	write(2, "Error\n", 6);
	stack_free(a);
	exit(1);
}

static void	add_number_to_stack(t_stack **a, char *str)
{
	t_stack	*new;
	int		value;

	if (!is_valid_number(str))
		error_and_exit(a);
	value = ft_atoi(str);
	new = stack_new(value);
	if (!new)
	{
		stack_free(a);
		exit(1);
	}
	stack_add_back(a, new);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i++;
			continue ;
		}
		add_number_to_stack(&a, argv[i]);
		i++;
	}
	if (has_duplicates(a))
		error_and_exit(&a);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusha <krusha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:52:03 by krusha            #+#    #+#             */
/*   Updated: 2026/03/03 20:47:22 by krusha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	parse_sign(const char *str, int *i, int *sign)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (str[*i] < '0' || str[*i] > '9')
		return (0);
	return (1);
}

static int	check_overflow(long result, int sign)
{
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!parse_sign(str, &i, &sign))
		return ((long)INT_MAX + 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (check_overflow(result, sign))
			return ((long)INT_MAX + 1);
		i++;
	}
	if (str[i] != '\0')
		return ((long)INT_MAX + 1);
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}

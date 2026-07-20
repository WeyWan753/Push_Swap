/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:43:35 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/21 00:32:50 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_input_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] && argv[i][j] != '-' && argv[i][j] != '+'
				&& !('0' <= argv[i][j] && argv[i][j] <= '9'))
				return (0);
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& !('0' <= argv[i][j + 1] && argv[i][j + 1] <= '9'))
				return (0);
			if ('0' <= argv[i][j] && argv[i][j] <= '9'
				&& (argv[i][j + 1] == '+' || argv[i][j + 1] == '-'))
				return (0);
		}
	}
	return (1);
}

int	is_num_out_of_bounds(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > 3000000000LL)
			return (1);
		str++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
		return (1);
	return (0);
}

int	is_input_out_of_bounds(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (('0' <= argv[i][j] && argv[i][j] <= '9')
				|| argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (is_num_out_of_bounds(&argv[i][j]) == 1)
					return (1);
				while ((('0' <= argv[i][j] && argv[i][j] <= '9')
					|| argv[i][j] == '+' || argv[i][j] == '-'))
					j++;
				if (argv[i][j] == 0)
					break ;
			}
		}
	}
	return (0);
}

int	has_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*checker;

	if (!stack)
		return (1);
	while (stack->prev)
		stack = stack->prev;
	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->data == checker->data)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

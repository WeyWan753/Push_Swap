/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:37:00 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/15 12:37:16 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_helper(int i, int j, int argc, char **argv)
{
	if (!('0' <= argv[i][j] && argv[i][j] <= '9') && argv[i][j] != '-'
		&& argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j])
		return (-1);
	if ((argv[i][j] == '-' || argv[i][j] == '+')
		&& !('0' <= argv[i][j + 1] && argv[i][j + 1] <= '9'))
		return (-1);
	if ('0' <= argv[i][j] && argv[i][j] <= '9'
		&& !('0' <= argv[i][j + 1] && argv[i][j + 1] <= '9')
		&& argv[i][j + 1] != ' ' && argv[i][j + 1])
		return (-1);
	return (1);
}

int	valid_input(int argc, char **argv)
{
	int	i;
	int	j;
	int	have_digit;

	have_digit = -1;
	if (argc == 1)
		return (0);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (input_helper(i, j, argc, argv) == -1)
				return (-1);
			if ('0' <= argv[i][j] && argv[i][j] <= '9')
				have_digit = 1;
		}
	}
	return (have_digit);
}

int	is_sorted(t_node *stack)
{
	while (stack)
	{
		if (stack->next)
			if (stack->data > stack->next->data)
				return (0);
		stack = stack->next;
	}
	return (1);
}

void	create_node(int data, t_node **stack)
{
	t_node	*temp;

	if (*stack == 0)
	{
		*stack = (t_node *)malloc(1 * sizeof(t_node));
		(*stack)-> data = data;
		(*stack)-> next = 0;
		(*stack)-> prev = 0;
	}
	else
	{
		temp = *stack;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = (t_node *)malloc(1 * sizeof(t_node));
		temp -> next -> prev = temp;
		temp -> next -> next = 0;
		temp -> next -> data = data;
	}
	fix_index(*stack);
}

int	is_out_of_bounds(const char *str)
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

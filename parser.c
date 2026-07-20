/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 21:00:35 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/21 00:33:12 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

void	create_node(int data, t_node **stack)
{
	t_node	*temp;

	if (*stack == 0)
	{
		*stack = (t_node *)malloc(1 * sizeof(t_node));
		(*stack)->data = data;
		(*stack)->next = 0;
		(*stack)->prev = 0;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = (t_node *)malloc(1 * sizeof(t_node));
		temp->next->prev = temp;
		temp->next->next = 0;
		temp->next->data = data;
	}
	fix_index(*stack);
}

void	init_input(int argc, char **argv, t_node **stack)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (('0' <= argv[i][j] && argv[i][j] <= '9') ||
				argv[i][j] == '-' || argv[i][j] == '+')
			{
				create_node(ft_atoi(&argv[i][j]), stack);
				while (('0' <= argv[i][j] && argv[i][j] <= '9') ||
					argv[i][j] == '-' || argv[i][j] == '+')
					j++;
				if (argv[i][j] == 0)
					break ;
			}
		}
	}
	fix_index(*stack);
}

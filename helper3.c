/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:40:39 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/15 14:15:30 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_input(int argc, char **argv, t_node **stack)
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
				if (is_out_of_bounds(&argv[i][j]))
					return (-1);
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
	return (1);
}

int	find_index(int data, t_node *stack)
{
	t_node	*best;
	t_node	*min;

	best = 0;
	min = 0;
	if (stack == 0)
		return (0);
	while (stack)
	{
		if (stack-> data > data && (best == 0 || stack-> data < best -> data))
			best = stack;
		if (min == 0 || stack-> data < min -> data)
			min = stack;
		stack = stack-> next;
	}
	if (best)
		return (best->index);
	else
		return (min->index);
}

void	calculate_cost(t_node *stackA, t_node *stackB)
{
	if (stackA == 0)
		return ;
	stackB->cost11 = stackB->index - 1;
	stackB->cost12 = stackB->target_index - 1;
	stackB->cost1 = max(2, stackB->cost11, stackB->cost12);
	stackB->cost21 = (stackB->size - stackB->index + 1) % stackB->size;
	stackB->cost22 = (stackA->size - stackB->target_index + 1) % stackA->size;
	stackB->cost2 = max(2, stackB->cost21, stackB->cost22);
	stackB->cost31 = min(2, stackB->cost11, stackB->cost21);
	stackB->cost32 = min(2, stackB->cost12, stackB->cost22);
	stackB->cost3 = stackB->cost31 + stackB->cost32;
	if (stackB->cost21 < stackB->cost11)
		stackB->cost31 = -(stackB->cost31);
	if (stackB->cost22 < stackB->cost12)
		stackB->cost32 = -(stackB->cost32);
	stackB->cost = min(3, stackB->cost1, stackB->cost2, stackB->cost3);
	if (min(3, stackB->cost1, stackB->cost2, stackB->cost3) == stackB->cost3)
		stackB->method = 3;
	if (min(3, stackB->cost1, stackB->cost2, stackB->cost3) == stackB->cost2)
		stackB->method = 2;
	if (min(3, stackB->cost1, stackB->cost2, stackB->cost3) == stackB->cost1)
		stackB->method = 1;
}

void	final_rotation(t_node **stack)
{
	t_node	*curr;
	t_node	*min;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	min = curr;
	while (curr)
	{
		if (curr->data < min->data)
			min = curr;
		curr = curr->next;
	}
	while (*stack != min)
	{
		if (min->index <= ((*stack)->size / 2) + 1)
			rotate(stack, "ra\n");
		else
			reverse_rotate(stack, "rra\n");
	}
}

t_node	*min_cost_node(t_node *stack)
{
	t_node	*best;

	best = 0;
	while (stack)
	{
		if (best == 0 || stack -> cost < best -> cost)
			best = stack;
		stack = stack->next;
	}
	return (best);
}

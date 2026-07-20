/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:42:40 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/21 00:32:34 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	method_1(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (++i <= min(2, temp->cost_1_b, temp->cost_1_a))
	{
		rotate(stack_a, "");
		rotate(stack_b, "");
		ft_putstr("rr\n");
	}
	if (max(2, temp->cost_1_b, temp->cost_1_a) == temp->cost_1_b)
		while (++i <= max(2, temp->cost_1_b, temp->cost_1_a) + 1)
			rotate(stack_b, "rb\n");
	else
		while (++i <= max(2, temp->cost_1_b, temp->cost_1_a) + 1)
			rotate(stack_a, "ra\n");
}

void	method_2(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (++i <= min(2, temp->cost_2_b, temp->cost_2_a))
	{
		reverse_rotate(stack_a, "");
		reverse_rotate(stack_b, "");
		ft_putstr("rrr\n");
	}
	if (max(2, temp->cost_2_b, temp->cost_2_a) == temp->cost_2_b)
		while (++i <= max(2, temp->cost_2_b, temp->cost_2_a) + 1)
			reverse_rotate(stack_b, "rrb\n");
	else
		while (++i <= max(2, temp->cost_2_b, temp->cost_2_a) + 1)
			reverse_rotate(stack_a, "rra\n");
}

void	method_3(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	if (temp->cost_3_b > 0)
		while (++i <= temp->cost_3_b)
			rotate(stack_b, "rb\n");
	else
		while (++i <= -(temp->cost_3_b))
			reverse_rotate(stack_b, "rrb\n");
	i = 0;
	if (temp->cost_3_a > 0)
		while (++i <= temp->cost_3_a)
			rotate(stack_a, "ra\n");
	else
		while (++i <= -(temp->cost_3_a))
			reverse_rotate(stack_a, "rra\n");
}

void	method(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	if (temp->method == 1)
		method_1(temp, stack_a, stack_b);
	else if (temp->method == 2)
		method_2(temp, stack_a, stack_b);
	else
		method_3(temp, stack_a, stack_b);
}

void	smart_push(t_node **stack_a, t_node **stack_b)
{
	long long	average;
	t_node		*temp;

	temp = *stack_a;
	average = 0;
	while (temp)
	{
		average += temp->data;
		temp = temp->next;
	}
	average /= (*stack_a)->size;
	while ((*stack_a)->size > 3)
	{
		push(stack_a, stack_b, "pb\n");
		if ((*stack_b)->data < average)
			rotate(stack_b, "rb\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:42:40 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/20 15:15:40 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	method1(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (++i <= min(2, temp->cost11, temp->cost12))
	{
		rotate(stack_a, "");
		rotate(stack_b, "");
		ft_putstr("rr\n");
	}
	if (max(2, temp->cost11, temp->cost12) == temp->cost11)
		while (++i <= max(2, temp->cost11, temp->cost12) + 1)
			rotate(stack_b, "rb\n");
	else
		while (++i <= max(2, temp->cost11, temp->cost12) + 1)
			rotate(stack_a, "ra\n");
}

void	method2(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (++i <= min(2, temp->cost21, temp->cost22))
	{
		reverse_rotate(stack_a, "");
		reverse_rotate(stack_b, "");
		ft_putstr("rrr\n");
	}
	if (max(2, temp->cost21, temp->cost22) == temp->cost21)
		while (++i <= max(2, temp->cost21, temp->cost22) + 1)
			reverse_rotate(stack_b, "rrb\n");
	else
		while (++i <= max(2, temp->cost21, temp->cost22) + 1)
			reverse_rotate(stack_a, "rra\n");
}

void	method3(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	if (temp->cost31 > 0)
		while (++i <= temp->cost31)
			rotate(stack_b, "rb\n");
	else
		while (++i <= -(temp->cost31))
			reverse_rotate(stack_b, "rrb\n");
	i = 0;
	if (temp->cost32 > 0)
		while (++i <= temp->cost32)
			rotate(stack_a, "ra\n");
	else
		while (++i <= -(temp->cost32))
			reverse_rotate(stack_a, "rra\n");
}

void	method(t_node *temp, t_node **stack_a, t_node **stack_b)
{
	if (temp->method == 1)
		method1(temp, stack_a, stack_b);
	else if (temp->method == 2)
		method2(temp, stack_a, stack_b);
	else
		method3(temp, stack_a, stack_b);
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

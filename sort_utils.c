/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:40:39 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/20 21:24:54 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	small_sort(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	if ((*stack)->size == 3)
	{
		a = (*stack)->data;
		b = (*stack)->next->data;
		c = (*stack)->next->next->data;
		if (a > b && a > c)
			rotate(stack, "ra\n");
		else if (b > a && b > c)
			reverse_rotate(stack, "rra\n");
	}
	if ((*stack)->data > (*stack)->next->data)
		swap(stack, "sa\n");
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (*stack_a == 0 || (*stack_a)->next == 0 || is_sorted(*stack_a))
		return ;
	smart_push(stack_a, stack_b);
	small_sort(stack_a);
	while (*stack_b)
	{
		temp = *stack_b;
		while (temp)
		{
			temp -> target_index = find_index(temp->data, *stack_a);
			calculate_cost(*stack_a, temp);
			temp = temp->next;
		}
		temp = min_cost_node(*stack_b);
		method(temp, stack_a, stack_b);
		push(stack_b, stack_a, "pa\n");
	}
	final_rotation(stack_a);
}

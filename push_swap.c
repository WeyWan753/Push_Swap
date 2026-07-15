/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:44:28 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/15 17:37:22 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(t_node *stack)
{
	t_node	*temp;

	temp = 0;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	check_duplicates(t_node *stack)
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
				return (-1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}

void	solve2or3(t_node **stack)
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

void	sort(t_node **stackA, t_node **stackB)
{
	t_node	*temp;

	if (*stackA == 0 || (*stackA)->next == 0 || is_sorted(*stackA))
		return ;
	smart_push(stackA, stackB);
	solve2or3(stackA);
	while (*stackB)
	{
		temp = *stackB;
		while (temp)
		{
			temp -> target_index = find_index(temp->data, *stackA);
			calculate_cost(*stackA, temp);
			temp = temp->next;
		}
		temp = min_cost_node(*stackB);
		method(temp, stackA, stackB);
		push(stackB, stackA, "pa\n");
	}
	final_rotation(stackA);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		x;

	stack_a = 0;
	stack_b = 0;
	x = init_input(argc, argv, &stack_a);
	if (x != 1 || valid_input(argc, argv) != 1
		|| check_duplicates(stack_a) != 1)
	{
		if (valid_input(argc, argv) == -1
			|| check_duplicates(stack_a) == -1 || x == -1)
			write(2, "Error\n", 6);
		free_mem(stack_a);
		free_mem(stack_b);
		return (0);
	}
	sort(&stack_a, &stack_b);
	free_mem(stack_a);
	free_mem(stack_b);
	return (0);
}

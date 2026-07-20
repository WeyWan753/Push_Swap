/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 21:15:15 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/20 21:15:26 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_node *stack_a, t_node *stack_b)
{
	if (stack_a == 0)
		return ;
	stack_b->cost11 = stack_b->index - 1;
	stack_b->cost12 = stack_b->target_index - 1;
	stack_b->cost1 = max(2, stack_b->cost11, stack_b->cost12);
	stack_b->cost21 = (stack_b->size - stack_b->index + 1) % stack_b->size;
	stack_b->cost22 = (stack_a->size - stack_b->target_index + 1) % stack_a->size;
	stack_b->cost2 = max(2, stack_b->cost21, stack_b->cost22);
	stack_b->cost31 = min(2, stack_b->cost11, stack_b->cost21);
	stack_b->cost32 = min(2, stack_b->cost12, stack_b->cost22);
	stack_b->cost3 = stack_b->cost31 + stack_b->cost32;
	if (stack_b->cost21 < stack_b->cost11)
		stack_b->cost31 = -(stack_b->cost31);
	if (stack_b->cost22 < stack_b->cost12)
		stack_b->cost32 = -(stack_b->cost32);
	stack_b->cost = min(3, stack_b->cost1, stack_b->cost2, stack_b->cost3);
	if (min(3, stack_b->cost1, stack_b->cost2, stack_b->cost3) == stack_b->cost3)
		stack_b->method = 3;
	if (min(3, stack_b->cost1, stack_b->cost2, stack_b->cost3) == stack_b->cost2)
		stack_b->method = 2;
	if (min(3, stack_b->cost1, stack_b->cost2, stack_b->cost3) == stack_b->cost1)
		stack_b->method = 1;
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

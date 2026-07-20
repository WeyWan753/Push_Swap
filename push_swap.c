/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:44:28 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/20 21:25:19 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = 0;
	stack_b = 0;
	if (is_input_valid(argc, argv) == 0
		|| is_input_out_of_bounds(argc, argv) == 1)
	{
		write(2, "Error\n", 6);
		free_mem(stack_a);
		return (1);
	}
	init_input(argc, argv, &stack_a);
	if (has_duplicates(stack_a) == 1)
	{
		write(2, "Error\n", 6);
		free_mem(stack_a);
		return (1);
	}
	sort(&stack_a, &stack_b);
	free_mem(stack_a);
	return (0);
}

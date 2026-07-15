/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:42:40 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/15 14:11:52 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	method1(t_node *temp, t_node **stackA, t_node **stackB)
{
	int	i;

	i = 0;
	while (++i <= min(2, temp->cost11, temp->cost12))
	{
		rotate(stackA, "");
		rotate(stackB, "");
		ft_putstr("rr\n");
	}
	if (max(2, temp->cost11, temp->cost12) == temp->cost11)
		while (++i <= max(2, temp->cost11, temp->cost12) + 1)
			rotate(stackB, "rb\n");
	else
		while (++i <= max(2, temp->cost11, temp->cost12) + 1)
			rotate(stackA, "ra\n");
}

void	method2(t_node *temp, t_node **stackA, t_node **stackB)
{
	int	i;

	i = 0;
	while (++i <= min(2, temp->cost21, temp->cost22))
	{
		reverse_rotate(stackA, "");
		reverse_rotate(stackB, "");
		ft_putstr("rrr\n");
	}
	if (max(2, temp->cost21, temp->cost22) == temp->cost21)
		while (++i <= max(2, temp->cost21, temp->cost22) + 1)
			reverse_rotate(stackB, "rrb\n");
	else
		while (++i <= max(2, temp->cost21, temp->cost22) + 1)
			reverse_rotate(stackA, "rra\n");
}

void	method3(t_node *temp, t_node **stackA, t_node **stackB)
{
	int	i;

	i = 0;
	if (temp->cost31 > 0)
		while (++i <= temp->cost31)
			rotate(stackB, "rb\n");
	else
		while (++i <= -(temp->cost31))
			reverse_rotate(stackB, "rrb\n");
	i = 0;
	if (temp->cost32 > 0)
		while (++i <= temp->cost32)
			rotate(stackA, "ra\n");
	else
		while (++i <= -(temp->cost32))
			reverse_rotate(stackA, "rra\n");
}

void	method(t_node *temp, t_node **stackA, t_node **stackB)
{
	if (temp->method == 1)
		method1(temp, stackA, stackB);
	else if (temp->method == 2)
		method2(temp, stackA, stackB);
	else
		method3(temp, stackA, stackB);
}

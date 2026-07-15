/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:30:17 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/15 14:04:39 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	push(t_node **src, t_node **dest, char *str)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = temp->next;
	if (*src)
		(*src)->prev = 0;
	temp->prev = 0;
	if (!*dest)
	{
		temp->next = 0;
		*dest = temp;
	}
	else
	{
		temp->next = *dest;
		(*dest)->prev = temp;
		*dest = temp;
	}
	fix_index(*src);
	fix_index(*dest);
	if (*str)
		ft_putstr(str);
}

void	swap(t_node **stack, char *str)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	second->prev = 0;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*stack = second;
	fix_index(*stack);
	if (*str)
		ft_putstr(str);
}

void	rotate(t_node **stack, char *str)
{
	t_node	*head;
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	while (head->prev)
		head = head->prev;
	tail = head;
	while (tail->next)
		tail = tail->next;
	*stack = head->next;
	(*stack)->prev = 0;
	tail->next = head;
	head->prev = tail;
	head->next = 0;
	fix_index(*stack);
	if (*str)
		ft_putstr(str);
}

void	reverse_rotate(t_node **stack, char *str)
{
	t_node	*head;
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	while (head->prev)
		head = head->prev;
	tail = head;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = 0;
	tail->prev = 0;
	tail->next = head;
	head->prev = tail;
	*stack = tail;
	fix_index(*stack);
	if (*str)
		ft_putstr(str);
}

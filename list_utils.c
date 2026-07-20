/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:30:26 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/20 20:07:42 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_index(t_node *stack)
{
	int	i;

	i = 0;
	if (stack)
		while (stack -> prev)
			stack = stack->prev;
	while (stack)
	{
		stack -> index = ++i;
		if (stack->next == 0)
			break ;
		stack = stack -> next;
	}
	while (stack)
	{
		stack -> size = i;
		stack = stack->prev;
	}
}

int	min(int count, ...)
{
	va_list	ap;
	int		m;
	int		x;

	va_start(ap, count);
	m = va_arg(ap, int);
	while (--count)
	{
		x = va_arg(ap, int);
		if (x < m)
			m = x;
	}
	va_end(ap);
	return (m);
}

int	max(int count, ...)
{
	va_list	ap;
	int		m;
	int		x;

	va_start(ap, count);
	m = va_arg(ap, int);
	while (--count)
	{
		x = va_arg(ap, int);
		if (x > m)
			m = x;
	}
	va_end(ap);
	return (m);
}

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

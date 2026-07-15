/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:30:26 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/15 12:36:19 by pola             ###   ########.fr       */
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

int	is_valid(long long result, int sign, const char *nptr)
{
	if (sign == 1 && (result > 922337203685477580L
			|| (result == 922337203685477580L && (*nptr - '0') > 7)))
		return (0);
	if (sign == -1 && (result > 922337203685477580L
			|| (result == 922337203685477580L && (*nptr - '0') > 8)))
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if ((*nptr != '-' && *nptr != '+' && (*nptr < '0' || *nptr > '9'))
		|| ((*(nptr + 1) < '0' || *(nptr + 1) > '9')
			&& (*nptr == '-' || *nptr == '+')))
		return (0);
	if (*nptr == '-')
		sign = -1;
	while (*nptr < '0' || *nptr > '9')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (!is_valid(result, sign, nptr))
			return (-(sign == 1));
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * result);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:31:03 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/14 23:24:05 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
	int				target_index;
	int				cost;
	int				size;
	int				method;
	int				cost1;
	int				cost11;
	int				cost12;
	int				cost2;
	int				cost21;
	int				cost22;
	int				cost3;
	int				cost31;
	int				cost32;
}	t_node;

void	print_stack(t_node *stack);
void	print_stackB(t_node *stack);
void	push(t_node **stackA, t_node **stackB, char *str);
void	swap(t_node **stack, char *str);
void	rotate(t_node **stack, char *str);
void	reverse_rotate(t_node **stack, char *str);
void	fix_index(t_node *stack);
int		ft_atoi(const char *nptr);
void	calculate_cost(t_node *stackA, t_node *stackB);
int		min(int count, ...);
int		max(int count, ...);
t_node	*min_node_cost(t_node *stack);
void	solve3(t_node **stack_a, t_node **stack_b);

#endif

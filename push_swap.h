/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:31:03 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/20 21:23:36 by wabin-wa         ###   ########.fr       */
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
void	print_stack_b(t_node *stack);
void	push(t_node **stack_a, t_node **stack_b, char *str);
void	swap(t_node **stack, char *str);
void	rotate(t_node **stack, char *str);
void	reverse_rotate(t_node **stack, char *str);
void	fix_index(t_node *stack);
long	ft_atoi(const char *nptr);
void	calculate_cost(t_node *stack_a, t_node *stack_b);
int		min(int count, ...);
int		max(int count, ...);
t_node	*min_node_cost(t_node *stack);
void	solve3(t_node **stack_a, t_node **stack_b);
int		input_helper(int i, int j, char **argv);
int		is_input_valid(int argc, char **argv);
int		is_sorted(t_node *stack);
void	create_node(int data, t_node **stack);
int		is_out_of_bounds(const char *str);
void	init_input(int argc, char **argv, t_node **stack);
int		find_index(int data, t_node *stack);
void	calculate_cost(t_node *stack_a, t_node *stack_b);
void	final_rotation(t_node **stack);
t_node	*min_cost_node(t_node *stack);
void	method1(t_node *temp, t_node **stack_a, t_node **stack_b);
void	method2(t_node *temp, t_node **stack_a, t_node **stack_b);
void	method3(t_node *temp, t_node **stack_a, t_node **stack_b);
void	method(t_node *temp, t_node **stack_a, t_node **stack_b);
void	ft_putstr(char *str);
void	smart_push(t_node **stack_a, t_node **stack_b);
int		has_duplicates(t_node *stack);
int		is_input_out_of_bounds(int argc, char **argv);
void	free_mem(t_node *stack);
void	sort(t_node **stack_a, t_node **stack_b);

#endif

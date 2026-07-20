/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:31:03 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/21 00:33:28 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
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
	int				cost_1;
	int				cost_1_b;
	int				cost_1_a;
	int				cost_2;
	int				cost_2_b;
	int				cost_2_a;
	int				cost_3;
	int				cost_3_b;
	int				cost_3_a;
}	t_node;

void	push(t_node **stack_a, t_node **stack_b, char *str);
void	swap(t_node **stack, char *str);
void	rotate(t_node **stack, char *str);
void	reverse_rotate(t_node **stack, char *str);
void	fix_index(t_node *stack);
long	ft_atoi(const char *nptr);
void	calculate_cost(t_node *stack_a, t_node *stack_b);
int		min(int count, ...);
int		max(int count, ...);
int		is_input_valid(int argc, char **argv);
int		is_sorted(t_node *stack);
void	create_node(int data, t_node **stack);
void	init_input(int argc, char **argv, t_node **stack);
int		find_index(int data, t_node *stack);
void	final_rotation(t_node **stack);
t_node	*min_cost_node(t_node *stack);
void	method_1(t_node *temp, t_node **stack_a, t_node **stack_b);
void	method_2(t_node *temp, t_node **stack_a, t_node **stack_b);
void	method_3(t_node *temp, t_node **stack_a, t_node **stack_b);
void	method(t_node *temp, t_node **stack_a, t_node **stack_b);
void	ft_putstr(char *str);
void	smart_push(t_node **stack_a, t_node **stack_b);
int		has_duplicates(t_node *stack);
int		is_input_out_of_bounds(int argc, char **argv);
void	free_mem(t_node *stack);
void	sort(t_node **stack_a, t_node **stack_b);

#endif

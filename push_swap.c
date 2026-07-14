/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <wabin-wa@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:44:28 by wabin-wa          #+#    #+#             */
/*   Updated: 2026/07/15 02:08:48 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(int argc, char **argv)
{
	int	i;
	int	j;
	int have_digit;

	have_digit = -1;
	if (argc == 1)
		return (0);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!('0' <= argv[i][j] && argv[i][j] <= '9') && argv[i][j] != '-' && argv[i][j] != ' ' && argv[i][j] != '+' && argv[i][j])
				return -1;
			if ((argv[i][j] == '-' || argv[i][j] == '+') && !('0' <= argv[i][j+1] && argv[i][j+1] <= '9'))
				return -1;
			if ('0' <= argv[i][j] && argv[i][j] <= '9' && !('0' <= argv[i][j+1] && argv[i][j+1] <= '9') && argv[i][j+1] != ' ' && argv[i][j+1])
				return -1;
			if ('0' <= argv[i][j] && argv[i][j] <= '9')
				have_digit = 1;
		}
	}

	return (have_digit);
}


int is_sorted(t_node *stack)
{
	while (stack)
	{
		if (stack->next)
			if (stack->data > stack->next->data)
				return 0;

		stack = stack->next;
	}
	return 1;


}


void	create_node(int data, t_node **stack)
{
	t_node	*temp;

	if (*stack == 0)
	{
		*stack = (t_node *)malloc(1 * sizeof(t_node));
		(*stack)-> data = data;
		(*stack)-> next = 0;
		(*stack)-> prev = 0;
	}
	else
	{
		temp = *stack;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = (t_node *)malloc(1 * sizeof(t_node));
		temp -> next -> prev = temp;
		temp -> next -> next = 0;
		temp -> next -> data = data;
	}
	fix_index(*stack);
}

int	is_out_of_bounds(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > 3000000000LL)
			return (1);
		str++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
		return (1);
	return (0);
}

int	init_input(int argc, char **argv, t_node **stack)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (('0' <= argv[i][j] && argv[i][j] <= '9') ||
				argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (is_out_of_bounds(&argv[i][j]))
					return (-1);
				create_node(ft_atoi(&argv[i][j]), stack);
				while (('0' <= argv[i][j] && argv[i][j] <= '9') ||
					argv[i][j] == '-' || argv[i][j] == '+')
					j++;
				if (argv[i][j] == 0)
					break ;
			}
		}
	}
	fix_index(*stack);
	return (1);
}

int	find_index(int data, t_node *stack)
{
	t_node	*best;
	t_node	*min;

	best = 0;
	min = 0;
	if (stack == 0)
		return (0);
	while (stack)
	{
		if (stack-> data > data && (best == 0 || stack-> data < best -> data))
			best = stack;
		if (min == 0 || stack-> data < min -> data)
			min = stack;
		stack = stack-> next;
	}
	if (best)
		return (best->index);
	else
		return (min->index);
}

void	calculate_cost(t_node *stackA, t_node *stackB)
{
	if (stackA == 0)
		return;
	stackB->cost11 = stackB->index - 1;
	stackB->cost12 = stackB->target_index - 1;
	stackB->cost1 = max(2, stackB->cost11, stackB->cost12);
	stackB->cost21 = stackB->size - stackB->index + 1;
	stackB->cost22 = stackA->size - stackB->target_index + 1;
	stackB->cost2 = max(2, stackB->cost21, stackB->cost22);
	stackB->cost31 = min(2, stackB->index - 1, stackB->size - stackB->index + 1);
	stackB->cost32 = min(2, stackB->target_index - 1, stackA->size - stackB->target_index + 1);
	stackB->cost3 = stackB->cost31 + stackB->cost32;
	if (stackB->size - stackB->index + 1 < stackB->index - 1)
		stackB->cost31 = -(stackB->cost31);
	if (stackA->size - stackB->target_index + 1 < stackB->target_index - 1)
		stackB->cost32 = -(stackB->cost32);
	stackB->cost = min(3, stackB->cost1, stackB->cost2, stackB->cost3);
	if (min(3, stackB->cost1, stackB->cost2, stackB->cost3) == stackB->cost3)
		stackB->method = 3;
	if (min(3, stackB->cost1, stackB->cost2, stackB->cost3) == stackB->cost2)
		stackB->method = 2;
	if (min(3, stackB->cost1, stackB->cost2, stackB->cost3) == stackB->cost1)
		stackB->method = 1;
}






void	final_rotation(t_node **stack)
{
	t_node	*curr;
	t_node	*min;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	min = curr;
	while (curr)
	{
		if (curr->data < min->data)
			min = curr;
		curr = curr->next;
	}
	while (*stack != min)
	{
		if (min->index <= ((*stack)->size / 2) + 1)
			rotate(stack, "ra");
		else
			reverse_rotate(stack, "rra");
	}
}


t_node *min_cost_node(t_node *stack)
{
	t_node *best;

	best = 0;
	while (stack)
	{
		if (best == 0 || stack -> cost < best -> cost)
			best = stack;
		stack = stack->next;
	}
	return (best);
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
			rotate(stack, "ra");
		else if (b > a && b > c)
			reverse_rotate(stack, "rra");
	}
	if ((*stack)->data > (*stack)->next->data)
		swap(stack, "sa");
}


void	method1(t_node *temp, t_node **stackA, t_node **stackB)
{
	int	i;

	i = 0;
	while (++i <= min(2, temp->cost11, temp->cost12))
	{
		rotate(stackA,"");
		rotate(stackB,"");
		printf("rr\n");
	}
	if (max(2, temp->cost11, temp->cost12) == temp->cost11)
		while (++i <= max(2, temp->cost11, temp->cost12) + 1)
			rotate(stackB, "rb");
	else// (max(2, temp->cost11, temp->cost12) == temp->cost11)
		while (++i <= max(2, temp->cost11, temp->cost12) + 1)
			rotate(stackA, "ra");

}

void	method2(t_node *temp, t_node **stackA, t_node **stackB)
{
	int	i;

	i = 0;
	while (++i <= min(2, temp->cost21, temp->cost22))
	{
		reverse_rotate(stackA,"");
		reverse_rotate(stackB,"");
		printf("rrr\n");
	}
	if (max(2, temp->cost21, temp->cost22) == temp->cost21)
		while (++i <= max(2, temp->cost21, temp->cost22) + 1)
			reverse_rotate(stackB, "rrb");
	else// (max(2, temp->cost11, temp->cost12) == temp->cost11)
		while (++i <= max(2, temp->cost21, temp->cost22) + 1)
			reverse_rotate(stackA, "rra");
}

	
	






void	method3(t_node *temp, t_node **stackA, t_node **stackB)
{
	int	i;

	i = 0;
	if (temp->cost31 > 0)
		while (++i <= temp->cost31)
			rotate(stackB, "rb");
	else
		while (++i <= -(temp->cost31))
			reverse_rotate(stackB, "rrb");
	i = 0;
	if (temp->cost32 > 0)
		while (++i <= temp->cost32)
			rotate(stackA, "ra");
	else
		while (++i <= -(temp->cost32))
			reverse_rotate(stackA, "rra");



}
void	sort(t_node **stackA, t_node **stackB)
{
	t_node *temp;
	int i;
	if (*stackA == 0 || (*stackA)->next == 0 || is_sorted(*stackA))
		return;
	while ((*stackA)->size > 3)
		push(stackA, stackB, "pb");
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
		if (temp->method == 1)
			method1(temp, stackA, stackB);
		else if (temp->method == 2)
			method2(temp, stackA, stackB);
		else
			method3(temp, stackA, stackB);
		push(stackB, stackA, "pa");
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
	//print_stack(stack_a);
	free_mem(stack_a);
	free_mem(stack_b);

	return (0);
}





/*


int	main(int argc, char **argv)
{
	t_node	*stack_a = 0;
	t_node	*stack_b = 0;
	char	op[100];
	t_node	*temp;
	int		x;

	// 1. Initialize Stack A
	x = init_input(argc, argv, &stack_a);
	if (x != 1 || valid_input(argc, argv) != 1 || check_duplicates(stack_a) != 1)
	{
		printf("Error initializing stacks.\n");
		free_mem(stack_a);
		return (0);
	}

	// 2. Main Debug Loop
	while (1)
	{
		// Recalculate all metrics dynamically after every move
		temp = stack_b;
		while (temp)
		{
			temp->target_index = find_index(temp->data, stack_a);
			calculate_cost(stack_a, temp);
			temp = temp->next;
		}

		// --- PRINT STATE ---
		printf("\n================================= CURRENT STATE =================================\n");
		printf("STACK A (Size: %d):\n", stack_a ? stack_a->size : 0);
		temp = stack_a;
		while (temp)
		{
			printf("  [Idx: %d] Data: %d\n", temp->index, temp->data);
			temp = temp->next;
		}

		printf("\nSTACK B (Size: %d):\n", stack_b ? stack_b->size : 0);
		temp = stack_b;
		while (temp)
		{
			printf("  [Idx: %d] Data: %d | Target_Idx: %d | Cost21: %d, Cost22: %d | Cost2: %d (Method %d)\n",
				temp->index, temp->data, temp->target_index, temp->cost21, temp->cost22, temp->cost2, temp->method);
			temp = temp->next;
		}
		printf("=================================================================================\n");

		// Get the next operation from the user
		printf("Enter operation (e.g. pb, pa, ra, rb, rr, rra, rrb, rrr, or 'exit'): ");
		if (scanf("%99s", op) <= 0 || strcmp(op, "exit") == 0)
			break;

		// Apply the chosen operation manually
		if (strcmp(op, "sa") == 0) swap(&stack_a, "");
		else if (strcmp(op, "sb") == 0) swap(&stack_b, "");
		else if (strcmp(op, "pa") == 0) push(&stack_b, &stack_a, "");
		else if (strcmp(op, "pb") == 0) push(&stack_a, &stack_b, "");
		else if (strcmp(op, "ra") == 0) rotate(&stack_a, "");
		else if (strcmp(op, "rb") == 0) rotate(&stack_b, "");
		else if (strcmp(op, "rr") == 0) { rotate(&stack_a, ""); rotate(&stack_b, ""); }
		else if (strcmp(op, "rra") == 0) reverse_rotate(&stack_a, "");
		else if (strcmp(op, "rrb") == 0) reverse_rotate(&stack_b, "");
		else if (strcmp(op, "rrr") == 0) { reverse_rotate(&stack_a, ""); reverse_rotate(&stack_b, ""); }
		else printf("Invalid operation!\n");
	}

	free_mem(stack_a);
	free_mem(stack_b);
	return (0);
}*/

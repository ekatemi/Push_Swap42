/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:48:47 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 20:18:43 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_max_node(t_stack_node *stack)
{
	long			max;
	t_stack_node	*node;

	max = 0;
	node = NULL;
	if (stack->next == NULL)
		return (stack);
	while (stack != NULL)
	{
		if (stack->index > max)
		{
			max = stack->index;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	int				min;
	t_stack_node	*node;

	min = INT_MAX;
	node = NULL;
	if (stack->next == NULL)
		return (stack);
	while (stack != NULL)
	{
		if (stack->index < min)
		{
			min = stack->index;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

//function to define direction of rotation, 1 ra, 2 rra;
int	dir_rotate(t_stack_node *stack, t_stack_node *target_node)
{
	long	i;
	long	mid;
	int		dir;

	i = 0;
	dir = 0;
	mid = list_len(stack) / 2;
	while (stack != NULL)
	{
		if (stack == target_node && i <= mid)
			dir = 1;
		else if (stack == target_node && i > mid)
			dir = 2;
		i++;
		stack = stack->next;
	}
	return (dir);
}

long int	list_len(t_stack_node *stack)
{
	long int		len;
	t_stack_node	*current;

	if (!stack)
		return (0);
	current = stack;
	len = 0;
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}

int	stack_sorted(t_stack_node *head)
{
	t_stack_node	*curr;

	curr = head;
	if (head == NULL)
		return (-1);
	while (curr->next != NULL)
	{
		if (curr->num > curr->next->num)
			return (0);
		curr = curr->next;
	}
	return (1);
}

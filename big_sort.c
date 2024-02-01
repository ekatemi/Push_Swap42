/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:27:53 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 22:19:35 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves node on top of the stack, ra or rra
void	on_top_a(t_stack_node **stack, t_stack_node *target)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		if (*stack && dir_rotate(*stack, target) == 1)
		{
			while (target != *stack)
				ra(stack);
		}
		else if (*stack && dir_rotate(*stack, target) == 2)
		{
			while (target != *stack)
				rra(stack);
		}
		current = current->next;
	}
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b, int chunk) //chunk = 5
{
	int	chunk_size;
	int	idx;
	int	moved;

	chunk_size = list_len(*a) / chunk;
	idx = chunk_size;
	moved = 0;
	while (chunk)
	{
		moved = 0;
		while (moved < chunk_size)
		{
			if ((*a)->index <= idx)
			{
				pb(b, a);
				moved++;
			}
			else
				ra(a);
		}
		chunk--;
		idx = idx + chunk_size;
	}
	while (list_len(*a))
		pb(b, a);
}

void	on_top_b(t_stack_node **stack, t_stack_node *target)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		if (*stack && dir_rotate(*stack, target) == 1)
		{
			while (target != *stack)
				rb(stack);
		}
		else if (*stack && dir_rotate(*stack, target) == 2)
		{
			while (target != *stack)
				rrb(stack);
		}
		current = current->next;
	}
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	int	to_move;

	to_move = list_len(*b);
	while (to_move)
	{
		on_top_b(b, find_max_node(*b));
		pa(a, b);
		to_move--;
	}
}

void	sort_alg(t_stack_node **a, t_stack_node **b)
{
	int	chunk;

	chunk = chunk_num(*a);
	move_a_to_b(a, b, chunk);
	move_b_to_a(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:53:33 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 21:49:26 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max_node(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sort_4(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;

	min = find_min_node(*a);
	if (list_len(*a) == 3)
		sort_three(a);
	else if (list_len(*a) == 4)
	{
		on_top_a(a, min);
		pb(b, a);
		sort_three(a);
		pa(a, b);
	}
}

static	t_stack_node	*find_closest_bigger(t_stack_node *a, int target)
{
	t_stack_node	*closest;
	t_stack_node	*min_node;

	closest = NULL;
	min_node = find_min_node(a);
	while (a != NULL)
	{
		if (a->index > target)
		{
			if (closest == NULL || a->index < closest->index)
			{
				closest = a;
			}
		}
		a = a->next;
	}
	if (closest == NULL)
		closest = min_node;
	return (closest);
}

void	sort_5(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*target;
	t_stack_node	*min;

	if (list_len(*a) == 2)
		sa(a);
	else if (list_len(*a) <= 4)
		sort_4(a, b);
	else if (list_len(*a) == 5)
	{
		pb(b, a);
		pb(b, a);
		sort_three(a);
		if ((*b)->index < (*b)->next->index)
			sb(b);
		while (*b)
		{
			target = find_closest_bigger(*a, (*b)->index);
			on_top_a(a, target);
			pa(a, b);
		}
		min = find_min_node(*a);
		on_top_a(a, min);
	}
	else
		push_swap(a, b);
}

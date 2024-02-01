/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:53:29 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 20:57:08 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;
	t_stack_node	*new_last;

	last_node = find_last_node(*head);
	new_last = find_prev_last_node(*head);
	new_last->next = NULL;
	last_node->next = *head;
	*head = last_node;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

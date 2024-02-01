/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:39:26 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 19:46:44 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **head)
{
	t_stack_node	*last_node;
	t_stack_node	*first;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last_node = find_last_node(*head);
	first = *head;
	*head = first->next;
	last_node->next = first;
	first->next = NULL;
}

void	ra(t_stack_node **a)
{
	if (!*a || (*a)->next == NULL)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

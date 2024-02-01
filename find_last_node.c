/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:50:09 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 20:50:13 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

t_stack_node	*find_prev_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next->next != NULL)
		head = head->next;
	return (head);
}

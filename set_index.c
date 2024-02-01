/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:46:28 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 18:51:36 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_node_index(t_stack_node *stack, t_stack_node *node)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (node->num > stack->num)
			index++;
		stack = stack->next;
	}
	node->index = index;
}

void	set_list_index(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current != NULL)
	{
		set_node_index(stack, current);
		current = current->next;
	}
}

int	chunk_num(t_stack_node *stack)
{
	int	len;
	int	res;

	len = list_len(stack);
	res = 0;
	if (len > 5 && len < 10)
		res = 1;
	else if (len > 20 && len <= 100)
		res = 5;
	else if (len > 100 && len <= 500)
		res = 10;
	else
		res = 21;
	return (res);
}

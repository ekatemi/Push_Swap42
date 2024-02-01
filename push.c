/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:32:53 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 19:37:26 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*to_push;

	if (*src == NULL)
		return ;
	to_push = *src;
	*src = to_push->next;
	if (*dest == NULL)
	{
		*dest = to_push;
		(*dest)->next = NULL;
	}
	else
	{
		to_push->next = *dest;
		*dest = to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	if (!*b)
		return ;
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	if (!*a)
		return ;
	push(b, a);
	write(1, "pb\n", 3);
}

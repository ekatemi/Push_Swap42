/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:37:42 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 19:38:48 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first_node = *head;
	second_node = (*head)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*head = second_node;
}

//Swap the first two nodes of stack `a` and print the instruction
void	sa(t_stack_node	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

//Swap the first two nodes of stack `b` and print the instruction
void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

//Stimutaneously swap the first two nodes of the stack 
//and print the instruction (never used)
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

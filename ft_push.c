/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:37:42 by emikhayl          #+#    #+#             */
/*   Updated: 2024/01/08 21:37:47 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int count_nodes(t_stack_node *stack)
{
    int i;

    i = 0;
    while (stack != NULL)
        {
            stack = stack->next;
            i++;
        }
    return(i);
}*/

void ft_swap(t_stack_node **head)
{
    if (*head == NULL || (*head)->next == NULL) //chech if there at least 2 nodes
        return ;
    t_stack_node *first_node = *head;
    t_stack_node *second_node = first_node->next;

    // Adjusting links for the swap
    first_node->next = second_node->next;
    second_node->prev = first_node->prev;
    second_node->next = first_node;
    first_node->prev = second_node;

    // Update the previous of the node after the swapped nodes
    if (first_node->next != NULL) {
        first_node->next->prev = first_node;
    }

    // Update the head to point to the new first node
    *head = second_node;

}

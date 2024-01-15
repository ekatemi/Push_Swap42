/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:30:50 by emikhayl          #+#    #+#             */
/*   Updated: 2024/01/15 19:30:54 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_index_and_above_med(t_stack_node *stack)
{
    t_stack_node *current;
    size_t i;
    long int median;

    i = 0;
    median = list_len(stack) / 2;
    current = stack;
    while (current != NULL)
    {
        current->index = i;
        if (current->index <= median) //check this, maybe < median
            current->above_median = 1;
        else
            current->above_median = 0;
        current = current->next;
        i++; //maybe ++i
    }
}
/*
void    set_push_cost(t_stack_node *stack)
{
    t_stack_node *current;
    size_t i;

    i = 0;
    current = stack;
    while (current != NULL)
    {
        current->index = i;
        current = current->next;
        i++;
    }
}*/

t_stack_node set_target_node(t_stack_node *a, t_stack_node *b)
{
    //closest smaller value
    //if no closest smaller, bigger
}

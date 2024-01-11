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


void ft_swap(t_stack_node **head)
{
    if (*head == NULL || (*head)->next == NULL) //check if there at least 2 nodes
        return ;
    t_stack_node *first_node = *head;
    t_stack_node *second_node = first_node->next;
    
    // Adjusting links for the swap
    first_node->next = second_node->next;
    second_node->prev = first_node->prev;
    second_node->next = first_node;
    first_node->prev = second_node;

    // Update the previous of the node after the swapped nodes
    if (first_node->next != NULL)
        first_node->next->prev = first_node;
    // Update the head to point to the new first node
    *head = second_node;
}

void sa(t_stack_node **stack)
{
    ft_swap(&stack);
    ft_putstr("sa\n");
}

t_stack_node *find_biggest(t_stack_node *stack)
{
    if (stack == NULL)
        return NULL;
    
    t_stack_node *biggest = stack;
    t_stack_node *current = stack;
    
    
    while (current != NULL)
    {
        if (current->num > biggest->num)
        {
            biggest = current;
        }
        current = current->next;
    }
    return(biggest);
}

//before use it check if the stack has 3 nodes
void sort_three(t_stack_node **stack)
{
    t_stack_node *biggest = find_biggest(*stack);
    
    if (count_nodes(*stack) != 3)
        return; 
    if (biggest == *stack)
        ra(stack);
    else if (biggest == (*stack)->next)
        rra(stack);
    
    if (!stack_sorted(stack))
        sa(stack);
}

void ra(t_stack_node **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return; // Nothing to rotate
    t_stack_node *tail = find_last(*stack);
    t_stack_node *head = *stack;
    t_stack_node *second = head->next;

    tail->next = head;
    head->next = NULL;
    head->prev = tail;
    second->prev = NULL;
    *stack = second;
}

//here I need ra rra and rotate.
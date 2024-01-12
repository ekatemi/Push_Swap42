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
    if (*head == NULL || (*head)->next == NULL) {
        // Not enough elements to swap
        return;
    }

    t_stack_node *first_node = *head;
    t_stack_node *second_node = first_node->next;

    // Adjusting links for the swap
    first_node->next = second_node->next;
    first_node->prev = second_node;
    second_node->next = first_node;
    second_node->prev = NULL;

    // Update the previous of the node after the swapped nodes
    if (first_node->next != NULL) {
        first_node->next->prev = first_node;
    }

    // Update the head to point to the new first node
    *head = second_node;
}

void sa(t_stack_node **stack, int print)
{
    ft_swap(stack);
    if (1 == print)
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
    
    if (biggest == *stack)
        ra(stack, 1);
    else if (biggest == (*stack)->next)
        rra(stack, 1);
    else if (biggest == (*stack)->next->next)
        sa(stack, 1);
}

void ra(t_stack_node **stack, int print)
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
    if (1 == print)
        write(1, "ra\n", 3);
}

void rra(t_stack_node **stack, int print)
{
    t_stack_node *tail = find_last(*stack);
    t_stack_node *head = *stack;

    tail->prev->next = NULL;
    head->prev = tail;
    tail->next = head;
    tail->prev = NULL;
    *stack = tail;

    if (1 == print)
        write(1, "rra\n", 4);
}

//void swap(t_stack_node **a, t_stack_node **b);
/*function to upate stack
    find above/below median
    for ss
    for rrr, rr
    find target node
*/
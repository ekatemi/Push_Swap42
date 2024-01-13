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

t_stack_node *find_biggest(t_stack_node *head)
{
    if (head == NULL)
        return NULL;
    
    t_stack_node *biggest = head;
    t_stack_node *current = head;
    
    
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
void sort_three(t_stack_node **head, t_stack_node **tail)
{
    t_stack_node *biggest = find_biggest(*head);
    
    if (biggest == *head)
        ra(head, tail, 1);
    else if (biggest == (*head)->next)
        rra(head, tail, 1);
    else if (biggest == *tail)
        sa(head, 1);
}

void ra(t_stack_node **head, t_stack_node **tail, int print)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // Nothing to rotate

    t_stack_node *second = (*head)->next;

    (*tail)->next = *head;
    (*tail)->next->next = NULL;
    second->prev = NULL;
    *head = second;
    *tail = (*tail)->next;
    if (1 == print)
        write(1, "ra\n", 3);
}

void rra(t_stack_node **head, t_stack_node **tail, int print)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // Nothing to rotate
    t_stack_node *previous = (*tail)->prev;
    
    previous->next = NULL;
    (*head)->prev = *tail;
    (*tail)->prev = NULL;
    (*tail)->next = *head;
    *head = *tail;
    *tail = previous;
      
    if (1 == print)
        write(1, "rra\n", 4);
}

void push_ab(t_stack_node **dest_head, t_stack_node **src_head)
{
    if (*src_head == NULL) //stack is empty nothing to push
        return ;
    
    t_stack_node *pushed = *src_head;
    pushed->prev = NULL;
    pushed->next = *dest_head;
    //stackdest is empty
    if (*dest_head != NULL)
    {
        (*dest_head)->prev = pushed;
    }    
    *dest_head = pushed;

}
/*function to upate stack
    find above/below median
    for ss
    for rrr, rr
    find target node
*/

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
    t_stack_node *second_node = (*head)->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    *head = second_node;
}

void sa(t_stack_node **stack, int print, char stack_name)
{
    ft_swap(stack);
    if (1 == print && stack_name == 'a')
        ft_putstr("sa\n");
    else if (1 == print && stack_name == 'b')
        ft_putstr("sb\n");
}

void ss(t_stack_node **a, t_stack_node **b, int print)
{
    sa(a, 0, 'a');
    sa(b, 0, 'b');
    if (1 == print)
        write(1, "ss\n", 3);
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
void sort_three(t_stack_node **head)
{
    t_stack_node *biggest = find_biggest(*head);
    
    if (biggest == *head)
        ra(head, 1, 'a');
    else if (biggest == (*head)->next)
        rra(head, 1, 'a');
    else if (biggest == (*head)->next->next)
        sa(head, 1, 'a');
}

void ra(t_stack_node **head, int print, char stack_name)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // Nothing to rotate
    t_stack_node *last_node = find_last_node(*head);
    t_stack_node *first = *head;

    *head = first->next;
    last_node->next = first;
    first->next = NULL;
    if (1 == print && stack_name == 'a')
        write(1, "ra\n", 3);
    else if (1 == print && stack_name == 'b')
        write(1, "rb\n", 3);
}

void rra(t_stack_node **head, int print, char stack_name)
{
    if (list_len(*head) < 3)
        return; // Nothing to rotate, better swap
    t_stack_node *last_node = find_last_node(*head);
    t_stack_node *new_last = find_prev_last_node(*head);
    new_last->next = NULL;
    last_node->next = *head;
    *head = last_node;
    if (1 == print && stack_name == 'a')
        write(1, "rra\n", 4);
    else if (1 == print && stack_name == 'b')
        write(1, "rrb\n", 4);
}

void rr(t_stack_node **head_a, t_stack_node **head_b, int print)
{
    if (*head_a == NULL || (*head_a)->next == NULL || *head_b == NULL || (*head_b)->next == NULL)
        return; // Nothing to rotate (not shure abut this check)
    ra(head_a, 0, 'a');
    ra(head_b, 0, 'b');
    if (1 == print)
        write(1, "rr\n", 4);
}

void rrr(t_stack_node **head_a, t_stack_node **head_b, int print)
{
    if (*head_a == NULL || (*head_a)->next == NULL || *head_b == NULL || (*head_b)->next == NULL)
        return;
    rra(head_a, 0, 'a');
    rra(head_b, 0, 'b');
    if (1 == print)
        write(1, "rrr\n", 5);
}


void push_ab(t_stack_node **dest, t_stack_node **src)
{
    if (*src == NULL) // stack is empty, nothing to push
        return;

    t_stack_node *to_push = *src;
    *src = to_push->next;

    // stack dest is empty
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



/*function to upate stack
    find above/below median
    for ss
    for rrr, rr
    find target node
*/

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
//swap ad print sa or sp, optionally to print(I use it in ss so print = 0)
void sa(t_stack_node **stack, int print, char stack_name)
{
    ft_swap(stack);
    if (1 == print && stack_name == 'a')
        ft_putstr("sa\n");
    else if (1 == print && stack_name == 'b')
        ft_putstr("sb\n");
}
//if I use it I always print
void ss(t_stack_node **a, t_stack_node **b)
{
    sa(a, 0, 'a');
    sa(b, 0, 'b');
    write(1, "ss\n", 3);
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
//rotate forward, first goes to the end, optionally print
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

//reverse rotate, last became first, optionally print
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
//rotate a and b, always print
void rr(t_stack_node **head_a, t_stack_node **head_b)
{
    if (*head_a == NULL || (*head_a)->next == NULL || *head_b == NULL || (*head_b)->next == NULL)
        return; // Nothing to rotate (not shure abut this check)
    ra(head_a, 0, 'a');
    ra(head_b, 0, 'b');
    write(1, "rr\n", 4);
}
//how many times to repeat, rep = smaller push price
void repeat_rr(t_stack_node **head_a, t_stack_node **head_b, int rep)
{
    while (rep)
    {
        rr(head_a, head_b);
        rep--;
    }
}
//reverse rotate a and b, always print
void rrr(t_stack_node **head_a, t_stack_node **head_b)
{
    if (*head_a == NULL || (*head_a)->next == NULL || *head_b == NULL || (*head_b)->next == NULL)
        return;
    rra(head_a, 0, 'a');
    rra(head_b, 0, 'b');
    write(1, "rrr\n", 5);
}
//how many times to repeat, rep = smaller push price
void repeat_rrr(t_stack_node **head_a, t_stack_node **head_b, int rep)
{
    while (rep)
    {
        rrr(head_a, head_b);
        rep--;
    }
}

void push_ab(t_stack_node **dest, t_stack_node **src, int print, char stack_name)
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

    if (1 == print && stack_name == 'a')
        write(1, "pa\n", 4);
    else if (1 == print && stack_name == 'b')
        write(1, "pb\n", 4);
}

void push_swap(t_stack_node **a, t_stack_node **b)
{
    refresh_stacks(a, b);
    t_stack_node *current_a = *a;
    
    //push a to b, sorting b
    while (list_len(a) > 3 && list_len(b) >= 2)
    {
        while(current_a != NULL)
        {
            //we fount the cheapest node and it target node
            if (current_a->cheapest == 1)
            {
                //take nodes to the top if needed
                if (current_a->index == 0 && current_a->target_node->index == 0)
                    push_ab(b, a, 1, 'b');
                
                //both are above median so I can use rr
                if (current_a->above_median == 1 && current_a->target_node->above_median == 1)
                {
                    if (current_a->push_cost < current_a->target_node->push_cost)
                    {
                        repeat_rr(a, b, current_a->push_cost);
                        refresh_stacks(a, b);
                    }
                    else
                        repeat_rr(a, b, current_a->target_node->push_cost);
                        refresh_stacks(a, b);
                }
                //move node a or b to the top (other is o top)
                /// here to write how to push the a or b on top
        
                //now node and target node are on top so I just push a on top of b
                

            }
            current_a = current_a->next; //for searching for the cheapest node iterating list
        }
    }
}

/*
void push_swap(t_stack_node **a, t_stack_node **b)
{
    if (list_len(a) > 3)
    {
        push_ab(b, a, 1, 'b');
        push_ab(b, a, 1, 'b');
//push swap until stack a == 3
//sort three
//push all b to a
//smallest number on top
    }
    else 
}*/

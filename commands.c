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

void repeat_ra(t_stack_node **stack, char stack_name, int rep)
{
    while(rep)
    {
        ra(stack, 1, stack_name);
        rep--;
    }
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

void repeat_rra(t_stack_node **stack, char stack_name, int rep)
{
    while (rep)
    {
        rra(stack, 1, stack_name);
        rep--;
    }
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

void push_ab(t_stack_node **dest, t_stack_node **src, char stack_name)
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

    if (stack_name == 'a')
        write(1, "pa\n", 4);
    else if (stack_name == 'b')
        write(1, "pb\n", 4);
}

void push_swap(t_stack_node *a, t_stack_node *b)
{
    if (list_len(a) >= 5)
    {
        push_ab(b, a, 'b');
        push_ab(b, a, 'b');
    }
}

void sort_b(t_stack_node **a, t_stack_node **b)
{
    while (list_len(*a) > 3)
    {
        t_stack_node *cheapest_node = find_cheapest(a);

        if (cheapest_node->index == 0 && cheapest_node->target_node->index == 0)
            push_ab(b, a, 'b');
        else if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
        {
            int rep = 0;
            if (cheapest_node->push_cost < cheapest_node->target_node->push_cost)
            {
                rep = cheapest_node->target_node->push_cost - cheapest_node->push_cost;
                repeat_rr(a, b, cheapest_node->push_cost);
                repeat_ra(a, 'b', rep); ///here to check!!!
            }
            else
            {
                rep = cheapest_node->push_cost - cheapest_node->target_node->push_cost;
                repeat_rr(a, b, cheapest_node->target_node->push_cost);
                repeat_ra(a, 'a', rep);
            }
        }
        else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
        {
            int rep = 0;
            if (cheapest_node->push_cost < cheapest_node->target_node->push_cost)
            {
                rep = cheapest_node->target_node->push_cost - cheapest_node->push_cost;
                repeat_rrr(a, b, cheapest_node->push_cost);
                repeat_rra(a, 'a', rep);
            }
            else
            {
                rep = cheapest_node->push_cost - cheapest_node->target_node->push_cost;
                repeat_rrr(a, b, cheapest_node->target_node->push_cost);
                repeat_rra(a, 'a', rep);
            }
        }

        refresh_stacks(a, b);
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

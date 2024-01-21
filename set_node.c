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
//FUNCTIONS TO SET STACKS
void    set_index_and_above_med(t_stack_node *stack)
{
    if (!stack)
        return;
    size_t i;
    long int median;

    i = 0;
    median = list_len(stack) / 2;

    while (stack != NULL)
    {
        stack->index = i;
        if (stack->index <= median) //check this, maybe < median
            stack->above_median = 1;
        else
            stack->above_median = 0;
        stack = stack->next;
        i++; //maybe ++i
    }
}

void set_target_for_a(t_stack_node *a, t_stack_node *b)
{
    //t_stack_node *target_node;
    t_stack_node *current_b;
    long temp;
    //target_node = NULL;
    while (a != NULL)
    {
        current_b = b;
        temp = LONG_MIN;  
            while (current_b != NULL)
            {
                if (current_b->num < a->num 
                    && current_b->num > temp)
                {
                    temp = current_b->num;
                    a->target_node = current_b;
                }
                current_b = current_b->next;
            }
            if (a->target_node == NULL) //i inicialize nodes wirth target set to NULL
                a->target_node = find_biggest(b);
        a = a->next;
    }
    //closest smaller value
    //if no closest smaller, bigger
}

void set_target_for_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current_a;
    //t_stack_node *target_node;
    long temp;
    
    //target_node = NULL;
    while (b != NULL)
    {
        temp = LONG_MAX;
        current_a = a;
        while (current_a != NULL)
        {
            if (current_a->num > b->num && current_a->num < temp)
            {
            temp = current_a->num;
            b->target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (b->target_node == NULL)
            b->target_node = find_smallest(a);
    b = b->next;
    }
}
    //closest bigger value
    //if no closest bigger, smaller

//how many moves to move node to the top
void    set_push_cost(t_stack_node *stack)
{
    long len = list_len(stack);
    while (stack != NULL)
    {
        if (stack->above_median == 1)
            stack->push_cost = stack->index;
        else if (stack->above_median == 0)
            stack->push_cost = len - stack->index;
        stack = stack->next;
    }
}
//how minimum moves to move nodes to the top
int push_price_opt(t_stack_node *a)
{  
    int price;
    price = 0;
        
    if (a->above_median == a->target_node->above_median)
    {
        if (a->target_node->push_cost >= a->push_cost)
            price = a->target_node->push_cost;
        else if (a->target_node->push_cost < a->push_cost)
                price = a->push_cost;
        }
        else
            price = a->push_cost + a->target_node->push_cost;   
    return (price);
}

void set_cheapest_a(t_stack_node *a, t_stack_node *b) 
{

    long price = LONG_MAX;
    t_stack_node *cheapest_node = NULL;
    refresh_stack_a(a, b);
    // Find the cheapest node
    while (a != NULL) 
    {
        int current_price = push_price_opt(a);
        if (current_price < price) 
            {
                price = current_price;
                cheapest_node = a;
            }
        a = a->next;
    }
    if (cheapest_node != NULL)
        cheapest_node->cheapest = 1;
}
//checks all nodes in a and if a->cheapest set to 1 it is the cheapest node.
t_stack_node *find_cheapest(t_stack_node *a) 
{
    t_stack_node *cheapest;
    t_stack_node *current = a;

    cheapest = NULL;
    while (current != NULL) 
    {
        if (current->cheapest == 1) 
        {
            cheapest = current;
        }
        current = current->next;
    }
    return cheapest;
}

void refresh_stack_a(t_stack_node *a, t_stack_node *b) //HERE THE PROBLEM
{
    set_index_and_above_med(a);
    set_index_and_above_med(b);
    set_push_cost(a);
    set_push_cost(b);
    set_target_for_a(a, b);
    set_cheapest_a(a, b);

    //ot shure about a and b, maybe only a
}
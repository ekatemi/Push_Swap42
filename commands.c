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

static void swap(t_stack_node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;
    t_stack_node *first_node = *head;
    t_stack_node *second_node = (*head)->next;
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
//Stimutaneously swap the first two nodes of the stack and print the instruction (never used)
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

//Function to rotate forward each stack
static void rotate(t_stack_node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // Nothing to rotate
    t_stack_node *last_node = find_last_node(*head);
    t_stack_node *first = *head;

    *head = first->next;
    last_node->next = first;
    first->next = NULL;
}

//Rotate the top `a` node to the bottom of the stack, and print the instruction
void	ra(t_stack_node **a) 
{
	if (!*a || (*a)->next == NULL)
        return ;
    rotate(a);
	write(1, "ra\n", 3);
}

//Rotate the top `b` node to the bottom of the stack, and print the instruction
void	rb(t_stack_node **b) 
{
	rotate(b);
	write(1, "rb\n", 3);
}
//Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the instruction
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

static void rev_rotate(t_stack_node **head)
{
    t_stack_node *last_node = find_last_node(*head);
    t_stack_node *new_last = find_prev_last_node(*head);
    new_last->next = NULL;
    last_node->next = *head;
    *head = last_node;
}

void	rra(t_stack_node **a) //Rotate the bottom of `a` to the top of the stack and print the instruction
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

static void push(t_stack_node **dest, t_stack_node **src)
{
    if (*src == NULL)
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

void	pa(t_stack_node **a, t_stack_node **b) //Push on top of `b`, the top `a` and print the instruction
{
	if (!*b)
        return ;
    push(a, b); 
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a) //Push on top of `a`, the top `b` and print the instruction
{
	if (!*a)
        return ;
    push(b, a);
	write(1, "pb\n", 3);
}
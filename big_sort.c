#include "push_swap.h"

int chunk_num(t_stack_node *stack)
{
    int len = list_len(stack);
    int res = 0;
    
    if (len > 5 && len < 10)
        res = 1;
    else if (len > 20 && len <= 100)
        res = 5;
    else if (len > 100 && len <= 500)
        res = 10;
    else
        res = 21;
    return res;
}


//moves node on top of the stack, ra or rra
void on_top_a(t_stack_node **stack, t_stack_node *target)
{
    t_stack_node *current = *stack;
    while (current)
    {
        if (*stack && dir_rotate(*stack, target) == 1)
        {
            while(target != *stack)
                ra(stack);
        }
        else if (*stack && dir_rotate(*stack, target) == 2)
        {
            while(target != *stack)
                rra(stack);
        }
    current = current->next;
    }
}

void move_a_to_b(t_stack_node **a, t_stack_node **b, int chunk) //chunk = 5
{
    int chunk_size;

    chunk_size = list_len(*a) / chunk;
    int idx = chunk_size;
    int moved = 0;
    while (chunk)
    {
        moved = 0;
        while(moved < chunk_size)
        {
            if((*a)->index <= idx)
            {
                pb(b, a);
                moved++;
            }
            else
                ra(a);
        }
        chunk--;
        idx = idx + chunk_size;
    }
    while(list_len(*a))
        pb(b, a);
}

void on_top_b(t_stack_node **stack, t_stack_node *target)
{
    t_stack_node *current = *stack;
    while (current)
    {
        if (*stack && dir_rotate(*stack, target) == 1)
        {
            while(target != *stack)
                rb(stack);
        }
        else if (*stack && dir_rotate(*stack, target) == 2)
        {
            while(target != *stack)
                rrb(stack);
        }
    current = current->next;
    }
}

void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    int to_move;
    
    to_move = list_len(*b);
    
    while(to_move)
    {
        on_top_b(b, find_max_node(*b));
        //print_stack(*b);
        pa(a, b);
        to_move--;
    }
}

void push_swap(t_stack_node **a, t_stack_node **b)
{
    int chunk = chunk_num(*a);
    move_a_to_b(a, b, chunk);
    move_b_to_a(a, b);
}

#include "push_swap.h"

t_stack_node *find_max_node(t_stack_node *stack)
{
    long max = 0;
    t_stack_node *node = NULL;
    if (stack->next == NULL)
        return stack;
    while (stack != NULL)
    {
        if (stack->index > max)
        {
            max = stack->index;
            node = stack;
        }
        stack = stack->next;
    }
    return node;
}

t_stack_node *find_min_node(t_stack_node *stack)
{
    int min = INT_MAX;
    t_stack_node *node = NULL;
    if (stack->next == NULL)
        return stack;
    while (stack != NULL)
    {
        if (stack->index < min)
        {
            min = stack->index;
            node = stack;
        }
        stack = stack->next;
    }
    return node;
}

//function to define direction of rotation, 1 ra, 2 rra;
int dir_rotate(t_stack_node *stack, t_stack_node *target_node)
{
    long i;
    long mid;
    int dir;

    i = 0;
    dir = 0;
    mid = list_len(stack) / 2;
    
    while (stack != NULL)
    {
        
        if (stack == target_node && i <= mid)
            dir = 1;
        else if (stack == target_node && i > mid)
            dir = 2;
        i++;    
        stack = stack->next;
    }
    return (dir);
}

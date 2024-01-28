#include "push_swap.h"

static void set_node_index(t_stack_node *stack, t_stack_node *node) 
{
    int index = 0;
    while(stack)
    {
        if (node->num > stack->num)
            index++;
        stack = stack->next;
    }
    node->index = index;
}

void set_list_index(t_stack_node *stack) 
{
    t_stack_node *current = stack;

    while (current != NULL) 
    {
        set_node_index(stack, current);
        current = current->next;
    }
}



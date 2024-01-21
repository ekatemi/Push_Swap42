#include "push_swap.h"

void push(t_stack_node **dest, t_stack_node **src)
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
	push(a, b); 
	write(1, "pa\n", 4);
}

void	pb(t_stack_node **b, t_stack_node **a) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	write(1, "pb\n", 4);
}

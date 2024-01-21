#include "push_swap.h"

void rev_rotate(t_stack_node **head)
{
    t_stack_node *last_node = find_last_node(*head);
    t_stack_node *new_last = find_prev_last_node(*head);
    new_last->next = NULL;
    last_node->next = *head;
    *head = last_node;
}

void	rra(t_stack_node **a, int print) //Rotate the bottom of `a` to the top of the stack and print the instruction
{
	rev_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, int print) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	rev_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, int print) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}
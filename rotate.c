#include "push_swap.h"

void rotate(t_stack_node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // Nothing to rotate
    t_stack_node *last_node = find_last_node(*head);
    t_stack_node *first = *head;

    *head = first->next;
    last_node->next = first;
    first->next = NULL;
}

void	ra(t_stack_node **a, int print) //Rotate the top `a` node to the bottom of the stack, and print the instruction
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, int print) //Rotate the top `b` node to the bottom of the stack, and print the instruction
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, int print) //Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the instruction
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
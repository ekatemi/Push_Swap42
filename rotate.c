#include "push_swap.h"

//Function to rotate forward each stack
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

//Rotate the top `a` node to the bottom of the stack, and print the instruction
void	ra(t_stack_node **a) 
{
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
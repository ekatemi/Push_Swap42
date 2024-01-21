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

void	sa(t_stack_node	**a, int print) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, int print) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, int print) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
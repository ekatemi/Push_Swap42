#include "push_swap.h"

int count_nodes(t_stack_node *stack)
{
    int i;

    i = 0;
    while (stack != NULL)
        {
            i++;
            stack = stack->next;
        }
    return(i);
}

void lst_dealloc(t_stack_node **head)
{
    if (*head == NULL)
        return ;
    t_stack_node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
        free(current->prev);
    }
    free(current);
    *head = NULL;
}

void init_stack_a(t_stack_node **head, char **argv)
{
    int n;
    int i = 1;

    while(argv[i])
    {
        n = ft_atoi(argv[i]);
        append_node(head, n);
        i++;
    }
}

t_stack_node *new_node(int *n)
{
    t_stack_node *node;
    node = malloc(sizeof(t_stack_node));
    if (node == NULL)
        return NULL;
    node->num = *n;
    node->index = 0;
    node->push_cost = 0;
    node->above_median = 0;
    node->cheapest = 0;
    node->target_node = NULL;
    //node->prev = NULL; //not shure
    node->next = NULL;
    return (node);
}

void append_node(t_stack_node **stack,  int n)
{
    t_stack_node *node = new_node(&n);
    t_stack_node *last_node;
    
    if (!node)
    {
        lst_dealloc(stack);
        exit(1);
    }
    
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else 
    {
        last_node = find_last(*stack);
        last_node->next = node;
        node->prev = last_node;
        last_node = node;
    }
}

t_stack_node *find_last(t_stack_node *stack) 
{
    if (stack == NULL)
        return NULL;  // Return NULL if the stack is empty without * because *stack and not **stack
    // Traverse the list until the last node is reached
    while (stack->next != NULL)
        stack = stack->next;
    return stack;
}

//****************************************
int stack_sorted(t_stack_node *stack)
{
    if(!stack)
        return (-1);
    while (stack->next != NULL)
    {
        if(stack->num > stack->next->num)
            return(0);
        stack = stack->next;
    }
    return(1);
}
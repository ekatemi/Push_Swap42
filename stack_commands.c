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

void lst_dealloc(t_stack_node **head, t_stack_node **tail)
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
    *tail = NULL;
}

void append_node(t_stack_node **head, t_stack_node **tail,  int n)
{
    t_stack_node *new_node;
    new_node = malloc(sizeof(t_stack_node));
    if (new_node == NULL)
    {
        lst_dealloc(head, tail);
        exit(1);
    }
    //init_new_node(new_node, n);
    new_node->num = n;
    new_node->index = 0;
    new_node->push_cost = 0;
    new_node->above_median = 0;
    new_node->cheapest = 0;
    new_node->target_node = NULL;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}

void init_stack_a(t_stack_node **head, t_stack_node **tail, char **argv)
{
    int n;
    int i = 1;

    while(argv[i])
    {
        n = ft_atoi(argv[i]);
        append_node(head, tail, n);
        i++;
    }
}

//****************************************
int stack_sorted(t_stack_node *head)
{
    t_stack_node *curr;
    curr = head;
    if(head == NULL)
        return (-1);
    while (curr->next != NULL)
    {
        if(curr->num > curr->next->num)
            return(0);
        curr = curr->next;
    }
    return(1);
}
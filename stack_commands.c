#include "push_swap.h"

long int list_len(t_stack_node *stack)
{
    t_stack_node *current;
    long int len;

    current = stack;
    len = 0;
    while (current != NULL)
    {
        current = current->next;
        len++;
    }
    return (len);
}

t_stack_node    *find_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

t_stack_node    *find_prev_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next->next != NULL)
		head = head->next;
	return (head);
}

void lst_dealloc(t_stack_node **head)
{
    if (*head == NULL)
        return ;
    t_stack_node *current = *head;
    while (current != NULL)
    {
        t_stack_node *aux = current;
        current = current->next;
        free(aux);
    }
    *head = NULL;
}

void init_new_node(t_stack_node *new_node, int n)
{
    new_node->num = n;
    new_node->index = 0;
    new_node->push_cost = 0;
    new_node->above_median = 0;
    new_node->cheapest = 0;
    new_node->target_node = NULL;
    new_node->next = NULL;
}

void append_node(t_stack_node **head,  int n)
{
    t_stack_node *new_node;
    t_stack_node *last_node = find_last_node(*head);
    new_node = malloc(sizeof(t_stack_node));
    if (new_node == NULL)
    {
        lst_dealloc(head);
        exit(1);
    }
    init_new_node(new_node, n);
    
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        last_node->next = new_node;
    }
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

t_stack_node *find_biggest(t_stack_node *head)
{
    if (head == NULL)
        return NULL;
    
    t_stack_node *biggest = head;
    t_stack_node *current = head;
    
    while (current != NULL)
    {
        if (current->num > biggest->num)
        {
            biggest = current;
        }
        current = current->next;
    }
    return(biggest);
}

t_stack_node *find_smallest(t_stack_node *head)
{
    if (head == NULL)
        return NULL;
    
    t_stack_node *smallest = head;
    t_stack_node *current = head;

    while (current != NULL)
    {
        if (current->num < smallest->num)
            smallest = current;
        current = current->next;
    }
    return(smallest);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:57:15 by emikhayl          #+#    #+#             */
/*   Updated: 2023/12/15 19:57:24 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        //t_stack_node *temp = *lst;
        current = current->next;
        free(current->prev);
    }
    free(current);
    *head = NULL;
}

void init_stack_a(t_stack_node **stack, char **argv)
{
    int n;
    int i = 1;

    while(argv[i])
    {
        n = ft_atoi(argv[i]);
        append_node(stack, n);
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
    node->prev = NULL; //not shure
    node->next = NULL;
    return (node);
}

void append_node(t_stack_node **stack, int n)
{
    t_stack_node *node = new_node(&n);
    t_stack_node *last_node;
    
    if (!node)
    {
        lst_dealloc(*stack);
        exit(1);
    }
    
    if (!(*stack))
    {
        *stack = node;
        //node->prev = NULL;
    }
    else 
    {
        last_node = find_last(*stack);
        last_node->next = node;
        node->prev = last_node;
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
//helper to visualize stack only for me
void print_stack(t_stack_node *stack)
{
    while (stack != NULL) {
        printf("%d\n", stack->num);
        stack = stack->next;
    }
    printf("\n");
}
void print_stack_rev(t_stack_node *stack)
{
    while (stack != NULL) {
        printf("%d\n", stack->num);
        stack = stack->prev;
    }
    printf("\n");
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


int main(int  argc, char  **argv)
{
    
    t_stack_node *a;
    //t_stack_node *b;

    int i;

    i = 1;
    a = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    //to check if the arguments are int
    while (i < argc) 
    {
        if ((!ft_atoi(argv[i]) && ft_strcmp(argv[i],"0")) || ft_checkdup(argv, i))
        {
            write(2,"Error\n", 6);
            return (1);
        }
        i++;
    }
   
    init_stack_a(&a, argv);


    printf("before swap\n");
    //t_stack_node *tail = find_last(a);
    print_stack(a);
    //print_stack_rev(tail);
    t_stack_node *biggest = find_biggest(a);
    printf("\nbiggest %d\n", biggest->num);
    /*ft_swap(&a);
    printf("after swap\n");
    print_stack(a);
    
    if (stack_sorted(a))
        printf("Sorted");
    else 
        printf("not sorted");*/
    //lst_dealloc(&a);
    //printf("deallocation check");
    //print_stack(a);
    
    return (0);
}


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

//helper to visualize stack only for me
static void print_stack(t_stack_node *stack)
{
    while (stack != NULL) {
        printf("%d\n", stack->num);
        stack = stack->next;
    }
    printf("\n");
}
static void print_stack_rev(t_stack_node *tail)
{
    t_stack_node *curr;

    curr = tail;
    while (curr != NULL) {
        printf("%d\n", curr->num);
        curr = curr->prev;
    }
    printf("\n");
}


int main(int  argc, char  **argv)
{
    
    t_stack_node *head_a;
    t_stack_node *tail_a;

    int i;

    i = 1;
    head_a = NULL;
    tail_a = NULL;
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
    init_stack_a(&head_a, &tail_a, argv);
    printf("Stack input------>\n");
    print_stack(head_a);
    printf("Commands------>\n");
    while (!stack_sorted(head_a))
    {
        if (count_nodes(head_a) == 2)
            sa(&head_a, 1);
        else if (count_nodes(head_a) == 3)
            sort_three(&head_a, &tail_a);
    }
    printf("sorted------>\n");
    print_stack(head_a);
    printf("Reversed------>\n");
    print_stack_rev(tail_a);
    lst_dealloc(&head_a, &tail_a);
    printf("deallocation check------>\n");
    print_stack(head_a);
    print_stack_rev(head_a);
    
    return (0);
}


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


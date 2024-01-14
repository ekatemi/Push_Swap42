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

int main(int  argc, char  **argv)
{
    
    t_stack_node *a;  
    t_stack_node *b;
    
    int i;
    i = 1;
    a = NULL;
    b = NULL;
    
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
    printf("Stack input------>\n");
    print_stack(a);

    printf("Commands------>\n");
    while (!stack_sorted(a))
    {
        if (count_nodes(a) == 2)
        {
            sa(&a, 1, 'a');
        }
        else if (count_nodes(a) == 3)
        {
            sort_three(&a);
            //countloops++;
        }
        else
            return 1;
    }

    //here code doesnt go because of return statement above
    printf("A------>\n");
    print_stack(a);
    printf("B------>\n");
    print_stack(b);
    
    lst_dealloc(&a);
    printf("deallocation check------>\n");
    print_stack(a);
    
    return (0);
}


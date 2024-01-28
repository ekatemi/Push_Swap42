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
//  static void print_stack(t_stack_node *stack)
//  {
//      while (stack != NULL) {
//          printf("num -- %d, index -- %d\n", stack->num, stack->index);
//          stack = stack->next;
//      }
//      //printf("\n");
//  }

int main(int  argc, char  **argv)
{
    
    t_stack_node *a;  
    t_stack_node *b;
    int i;
    int chunk;

    i = 1;
    a = NULL;
    b = NULL;
    chunk = 1;
    
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
    set_list_index(a);
    /*
    printf("Stack input------>\n");
    print_stack(a);
    set_list_index(a);
    print_stack(a);
    printf("Commands------>\n");*/
    if (!stack_sorted(a))
    {
        if (list_len(a) == 2)
        {
            sa(&a);
        }
        else if (list_len(a) == 3)
        {
            sort_three(&a);
        }
        else if (list_len(a) == 4)
        {
            sort_4(&a, &b);
        }
        else if (list_len(a) == 5)
            sort_5(&a, &b);
        else
        {
            chunk = chunk_num(a);
            //printf("chunk size %d\n", chunk);
            move_a_to_b(&a, &b, chunk);
            move_b_to_a(&a, &b);
        }
    }     
    //here code doesnt go because of return statement above
    // printf("A after------>\n");
    // print_stack(a);
    // printf("B after------>\n");
    // print_stack(b);
    lst_dealloc(&a);

    // printf("deallocation check------>\n");
    // print_stack(a);
    
    return (0);
}


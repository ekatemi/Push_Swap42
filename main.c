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
    while (!stack_sorted(a) && b == NULL)
    {
        if (list_len(a) == 2)
        {
            sa(&a, 1, 'a');
        }
        else if (list_len(a) == 3)
        {
            sort_three(&a);
        }
        else //if list is longer than 5
        {
            long len_a = list_len(a);
            if (len_a-- > 3 && !stack_sorted(a))
                push_ab(&b, &a, 'b');
            if (len_a-- > 3 && !stack_sorted(a))
                push_ab(&b, &a, 'b');
            
            while (len_a > 3 && !stack_sorted(a))
            {
                push_ab(&b, &a, 'b');
                set_index_and_above_med(a);
                set_index_and_above_med(b);
                
                set_push_cost(a);
                set_push_cost(b);
                set_target_for_a(a, b);
                set_cheapest_a(a);//HERE THE ISSUE!!!

                //refresh_stack_a(a, b);
                //sort_b(&a, &b);
                t_stack_node *curr = a;
                while (curr)
                    {
                        printf("index %d -- value %d -- above med %d -- push_cost %d -- cheapest %d -- val target %d\n", curr->index, curr->num, curr->above_median, curr->push_cost, curr->cheapest, curr->target_node->num);
                        curr = curr->next;
                    }

                curr = b;
                while (curr)
                    {
                        printf("index %d -- value %d -- above med %d -- push_cost %d -- cheapest %d\n", curr->index, curr->num, curr->above_median, curr->push_cost, curr->cheapest);
                        curr = curr->next;
                    }
                len_a = list_len(a);
            }
            
            //printf("too many args");
            //return(0);
            //push_swap(&a, &b);
        }
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


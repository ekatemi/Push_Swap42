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
    
    if (argc >= 2)
    {
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
                push_swap(&a, &b);
                // chunk = chunk_num(a);
                // move_a_to_b(&a, &b, chunk);
                // move_b_to_a(&a, &b);
            }
        }     
    lst_dealloc(&a);
} 
    // printf("deallocation check------>\n");
    // print_stack(a);
    
    return (0);
}


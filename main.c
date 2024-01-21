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
 	if (!stack_sorted(a)) //Check if the stack is not sorted
	{
		if (stack_len(a) == 2) //If not, and there are two numbers, swap the first two nodes
			sa(&a);
		else if (stack_len(a) == 3) //If not, and there are three numbers, call the sort three algorithm
			sort_three(&a);
		else
			sort_stacks(&a, &b); //If not, and there are more than three numbers, call the sort stacks algorithm
	}
    printf("A------>\n");
    print_stack(a);
    printf("B------>\n");
    print_stack(b);
    
    lst_dealloc(&a);
    printf("deallocation check------>\n");
    print_stack(a);
    
    return (0);
}


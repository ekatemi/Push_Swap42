/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:34:48 by emikhayl          #+#    #+#             */
/*   Updated: 2023/12/27 18:34:53 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack_node
{
    int num;
    int index;
    int push_cost;
    int above_median;
    int cheapest;

    struct s_stack_node *next;
    struct s_stack_node *prev;
    struct s_stack_node *target_node;
} t_stack_node;

//functions to check input

int ft_isnum(char *str);
int ft_atoi(char *str);
int ft_strcmp(char *str1, char *str2);
int ft_checkdup(char  **argv, int current);

//functions to init the stack
void init_stack_a(t_stack_node **a, char **argv);
void append_node(t_stack_node **stack, int n);
t_stack_node* find_last(t_stack_node* stack);
void print_stack(t_stack_node *stack);

#endif
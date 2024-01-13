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

//etc
void ft_putstr(char *str);

//functions to init the stack
int count_nodes(t_stack_node *stack);
void init_stack_a(t_stack_node **head, t_stack_node **tail, char **argv);
void append_node(t_stack_node **head, t_stack_node **tail,  int n);
void ft_swap(t_stack_node **head);
int count_nodes(t_stack_node *stack);
void lst_dealloc(t_stack_node **head, t_stack_node **tail);
int stack_sorted(t_stack_node *stack);



//functions commands
void ft_swap(t_stack_node **head);
t_stack_node *find_biggest(t_stack_node *head);
void sort_three(t_stack_node **head, t_stack_node **tail);
void ra(t_stack_node **head, t_stack_node **tail, int print);
void rra(t_stack_node **head, t_stack_node **tail, int print);
void sa(t_stack_node **stack, int print);


#endif
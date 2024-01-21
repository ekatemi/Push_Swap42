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
#include <limits.h>

//define struct
typedef struct s_stack_node
{
    int num;
    int index;
    int push_cost;
    int above_median; //1 yes 0 not
    int cheapest; //1 yes 0 not

    struct s_stack_node *next;
    struct s_stack_node *target_node; //for b - closer smallest, for a - closest bigger
} t_stack_node;

//check input
int ft_isnum(char *str);
int ft_atoi(char *str);
int ft_strcmp(char *str1, char *str2);
int ft_checkdup(char  **argv, int current);

//etc
void ft_putstr(char *str);

//functions to init the stack
long int list_len(t_stack_node *stack);
t_stack_node    *find_last_node(t_stack_node *head);
t_stack_node    *find_prev_last_node(t_stack_node *head);
void lst_dealloc(t_stack_node **head);
void append_node(t_stack_node **head,  int n);
void init_stack_a(t_stack_node **head, char **argv);
int stack_sorted(t_stack_node *head);
void    init_new_node(t_stack_node *new_node, int n);

//functionas to update stacks
void set_target_for_a(t_stack_node *a, t_stack_node *b);
void    set_target_for_b(t_stack_node *a, t_stack_node *b);
void    set_push_cost(t_stack_node *stack);
void    set_index_and_above_med(t_stack_node *stack);

void set_cheapest_a(t_stack_node *a);
void refresh_stack_a(t_stack_node *a, t_stack_node *b);
t_stack_node *find_cheapest(t_stack_node *a);


//functions for sorting
void ft_swap(t_stack_node **head);
t_stack_node *find_biggest(t_stack_node *head);
t_stack_node *find_smallest(t_stack_node *head);
void sa(t_stack_node **stack, int print, char stack_name);
void ra(t_stack_node **head, int print, char stack_name);
void repeat_ra(t_stack_node **stack, char stack_name, int rep);
void rra(t_stack_node **head, int print, char stack_name);
void repeat_rra(t_stack_node **stack, char stack_name, int rep);
void sort_three(t_stack_node **head);
//void sort_five(t_stack_node **a,t_stack_node **b);
void push_ab(t_stack_node **dest, t_stack_node **src, char stack_name);
void ss(t_stack_node **a, t_stack_node **b);
void rr(t_stack_node **a, t_stack_node **b);
void repeat_rr(t_stack_node **head_a, t_stack_node **head_b, int rep);
void rrr (t_stack_node **a, t_stack_node **b);
void repeat_rrr(t_stack_node **head_a, t_stack_node **head_b, int rep);
void push_swap(t_stack_node **a, t_stack_node **b);
void smallest_ontop(t_stack_node **a);

void opt_above_median(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void opt_below_median(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void sort_b(t_stack_node **a, t_stack_node **b);
void sort_a(t_stack_node **a, t_stack_node **b);

#endif
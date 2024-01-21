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
    int findex;
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


//functions to init the stack
long int stack_len(t_stack_node *stack);
t_stack_node    *find_last_node(t_stack_node *head);
t_stack_node    *find_prev_last_node(t_stack_node *head);
void lst_dealloc(t_stack_node **head);
void append_node(t_stack_node **head,  int n);
void init_stack_a(t_stack_node **head, char **argv);
int stack_sorted(t_stack_node *head);
void    init_new_node(t_stack_node *new_node, int n);
t_stack_node	*get_cheapest(t_stack_node *stack);
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
t_stack_node *find_min(t_stack_node *stack);
t_stack_node *find_max(t_stack_node *head);
void	current_index(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);

//COMMANDS
void push(t_stack_node **dest, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);
void rev_rotate(t_stack_node **head);
void	rra(t_stack_node **a, int print);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);
void rotate(t_stack_node **head);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	sa(t_stack_node	**a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

//SORTING
void sort_three(t_stack_node **head);
void	sort_stacks(t_stack_node **a, t_stack_node **b);


#endif
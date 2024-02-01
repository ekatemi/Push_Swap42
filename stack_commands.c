/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:01:34 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 21:50:06 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_dealloc(t_stack_node **head)
{
	t_stack_node	*current;
	t_stack_node	*aux;

	if (*head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		aux = current;
		current = current->next;
		free(aux);
	}
	*head = NULL;
}

void	init_new_node(t_stack_node *new_node, int n)
{
	new_node->num = n;
	new_node->index = 0;
	new_node->next = NULL;
}

void	append_node(t_stack_node **head, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	last_node = find_last_node(*head);
	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
	{
		lst_dealloc(head);
		exit (1);
	}
	init_new_node(new_node, n);
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		last_node->next = new_node;
	}
}

void	init_stack_a(t_stack_node **head, char **argv)
{
	int	n;
	int	i;

	i = 1;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		append_node(head, n);
		i++;
	}
	set_list_index(*head);
}

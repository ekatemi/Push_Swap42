/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:57:15 by emikhayl          #+#    #+#             */
/*   Updated: 2024/02/01 21:47:41 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				i;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		while (i < argc)
		{
			if ((!ft_atoi(argv[i]) && ft_strcmp (argv[i], "0"))
				|| ft_checkdup(argv, i))
			{
				write (2, "Error\n", 6);
				return (1);
			}
			i++;
		}
		init_stack_a(&a, argv);
		if (!stack_sorted(a))
			push_swap(&a, &b);
		lst_dealloc(&a);
	}
	return (0);
}

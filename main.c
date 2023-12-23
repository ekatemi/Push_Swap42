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

#include <stdio.h>
#include <stdlib.h>

//-2,147,483,648 to 2,147,483,647
int ft_isnum(char *str)
{
    if (*str == '-')
        str++;
    while(*str)
    {
        if (*str < '0' || *str > '9')
            return(0);
        str++;
    }
    return (1);
}

int ft_isint(long num)
{
    
}



int main(int  argc, char  *argv[])
{
    int i;

    i = 1;
    if (argc < 2)
        return (1);
    while (i < argc) 
    {
        char *str = argv[i];
        
        i++;
    }
    return (0);
}


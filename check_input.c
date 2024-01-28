/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:29:37 by emikhayl          #+#    #+#             */
/*   Updated: 2023/12/27 16:29:44 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FUNCTIONS TO CHECK IF INPUT IS VALID

#include "push_swap.h"

void ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
     write(1, "\n", 1);
}
//check if string contains only numbers and optionally - at start
int ft_isnum(char *str)
{
    if (*str == '-')
        str++;
    if (*str == '\0')
        return(0);
    while(*str)
    {
        if (*str < '0' || *str > '9')
            return(0);
        str++;
    }
    return (1);
}
//convert str to int, if it is not int return 0;
int ft_atoi(char *str)
{
    if (!ft_isnum(str)) 
        return (0);
    int sign = 1;
    long res = 0;
    while(*str)
    {
        if (*str == '-')
        {
            sign = -1;
            str++;
        }
        if (*str == '0' && *(str + 1) != '\0')
            str++;
        res = res * 10 + (*str - '0');
        str++;
    }
    res = res * sign;
    if (res < INT_MIN || res > INT_MAX) 
        return (0);
   return (res);
}


// function to check if 2 strings are equal
int ft_strcmp(char *str1, char *str2)
{
    while (*str1 || *str2)
    {
        if (*str1 != *str2)
            return(1);
        str1++;
        str2++;
    }
    return(0);
}



//function to check if input args are not duplicated (1 dup, 0 not)
int ft_checkdup(char  **argv, int current)
{
    int i;

    i = 1;
    while (i < current)
    {
        if (ft_atoi(argv[i]) == ft_atoi(argv[current]))
                return(1);
        i++;    
    }
    return(0);
}

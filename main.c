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
#include <unistd.h>
#include <stdlib.h>
//check if string contains only numbers and optionally - at start
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
        res = res * 10 + (*str - '0');
        str++;
   }
   res = res * sign;
   if (res < -2147483648 || res > 2147483647) 
   {
    return (0);
   }
   return ((int)res);
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
        if (ft_strcmp(argv[i], argv[current]) == 0)
                return(1);
        i++;    
    }
    return(0);
}

int main(int  argc, char  **argv)
{
    int i;

    i = 1;
    if (argc < 2)
        return (1);
    while (i < argc) 
    {
        if ((!ft_atoi(argv[i]) && ft_strcmp(argv[i],"0")) || ft_checkdup(argv, i))
        {
            write(2,"wrong input\n", 11);
            return(0);
        }
        // code to process input
        i++;
    }
    return (0);
}


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

int main(int  argc, char  *argv[])
{
    int i;
    
    i = 1;
    if (argc < 2)
        return (1);
    while (argc > i) 
    {
        char *str = argv[i];  // Replace this with your actual char array
        char *endptr;  // Pointer to the first character not converted
        long num = strtol(str, &endptr, 10);  // C
        if (*endptr != '\0') {
            printf("Error: Invalid number format: %s\n", str);
            return 1;  // Exit with an error code
        }
        printf("%ld\n", num);
        i++;
    }
    return (0);
}


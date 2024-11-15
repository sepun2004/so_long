/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2024/11/06 10:53:05 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h> 
#include "../include/so_long.h"

int main(int argc, char **argv)
{
    int result;
    
    if (argc <= 2)
    {
        ft_printf("Error");
    }
    // else
    // {
    //     /* code */
    // }
    result = ft_check_map(argv);
    printf("ft_check_map es %d", result);
    return (0);
} 

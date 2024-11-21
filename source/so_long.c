/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2024/11/21 20:11:31 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h> 
#include "../Include/so_long.h"

int main(int argc, char **argv)
{
    int result;
	t_data *data;
    
    if (argc < 2)
    {
        ft_printf("Error\n");
    }
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
    result = ft_check_map(data, argv);
    printf("ft_check_map es %d\n", result);
    return (0);
} 

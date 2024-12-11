/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2024/12/11 21:51:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h> 
#include "../Include/so_long.h"

int main(int argc, char **argv)
{
	t_map *map;
	// t_data *data;
	
	// map = NULL;
	if (argc > 2)
	{
		ft_printf("Error\n");
		return (-1);
	} 
	if (argc == 2 && ft_check_ber(argv) == -1)
	{
		ft_printf("No es un archivo .ber\n");
		return(-1);
	}
	map = ft_calloc(sizeof(t_map), 1);
	//map = NULL;
	ft_check_map(map, argv);

	return (0);
} 




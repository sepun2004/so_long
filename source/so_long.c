/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2024/12/16 19:02:53 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h> 
#include "../Include/so_long.h"

void ft_init() //Esta funcion debe generar a ventada
{
	mlx_t *mlx;
	
	if (!(mlx = mlx_init(800, 600, "so_long", true)))
	{
		ft_printf_error("Error\nNo se pudo inicializar mlx\n");
	}
	
	mlx_loop(mlx);
	
}

int main(int argc, char **argv)
{
	t_map *map;
	
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
	ft_check_map(map, argv);
	ft_init();
	return (0);
}

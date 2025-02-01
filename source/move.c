/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:49:02 by sepun             #+#    #+#             */
/*   Updated: 2025/02/01 22:04:37 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	nothing(t_data *map, int pos_x, int pos_y)
{
	printf("ingreso en nothing\n");
	printf("pos_x: %d, pos_y: %d\n", pos_x, pos_y);




	
	map->run_map[map->player_x][map->player_y] = '0';
	
	map->run_map[pos_x][pos_y] = 'P';
	map->player_x = pos_x;
	map->player_y = pos_y;
	map->count_moves++;
}

void	ft_move(mlx_t *mlx, t_data *map)
{
	// print_map(map->run_map);
	// ft_printf("------------------------------------\n");
	// ft_printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	// ft_printf("------------------------------------\n");

	mlx_key_hook(mlx, &my_keyhook, map);
	// print_map(map->run_map);
	// ft_printf("------------------------------------\n");
	// ft_printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	// ft_printf("------------------------------------\n");
}

void 	exit_check(t_data *map, int pos_x, int pos_y)
{
	//printf("pos_x: %d, pos_y: %d\n", pos_x, pos_y);
	if(map->coins == 0)
	{
		map->count_moves++;
		ft_printf("You win\n");
		return ;	
	}
	else
	{
		map->run_map[pos_x][pos_y] = 'E';
		map->run_map[map->player_x][map->player_y] = 'P';
		// map->player_x = pos_x;
		// map->player_y = pos_y;
	}
}

void all_move(t_data *map, int pos_x, int pos_y)
{
	printf("\n\n\n\n\ningreso en all_move\n");
	print_map(map);
	ft_printf("------------------------------------\n");
	ft_printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	ft_printf("------------------------------------\n");
	
	if (map->run_map[pos_x][pos_y] == '1')
	{
		printf("ingreso en 1\n");
		return ;
	}
	printf("coins: %d\n", map->coins);

	if (map->run_map[pos_x][pos_y] == 'C')
	{
		printf("ingreso en coins\n");
		map->coins--;
		map->run_map[pos_x][pos_y] = 'P';
		map->run_map[map->player_x][map->player_y] = '0';
	}

	if (map->run_map[pos_x][pos_y] == 'E')
	{
		printf("ingreso en exit\n");
		printf("pos_x: %d, pos_y: %d\n", pos_x, pos_y);
		exit_check(map, pos_x, pos_y);
		return ;
	}

	else
	{
		nothing(map, pos_x, pos_y);
	}
	print_map(map);
	ft_printf("------------------------------------\n");
	ft_printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	ft_printf("------------------------------------\n");

	draw_player(map, map->mlx);
}
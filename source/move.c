/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:49:02 by sepun             #+#    #+#             */
/*   Updated: 2025/02/28 23:03:28 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	nothing(t_data *map, int pos_x, int pos_y)
{
	map->run_map[pos_x][pos_y] = 'P';
	map->run_map[map->player_x][map->player_y] = '0';
	img_to_window(map->mlx, map->texture->backgound_texture,
		map->player_y * 50, map->player_x * 50);
	map->player_x = pos_x;
	map->player_y = pos_y;
	img_to_window(map->mlx, map->texture->player_texture,
		pos_y * 50, pos_x * 50);
	map->count_moves++;
}

void	ft_move(mlx_t *mlx, t_data *map)
{
	mlx_key_hook(mlx, &my_keyhook, map);
	mlx_loop(map->mlx);
}

void	exit_check(t_data *map, int pos_x, int pos_y)
{
	if (map->coins == 0)
	{
		map->count_moves++;
		free_struct(map);
		return ;
	}
	else
	{
		map->run_map[pos_x][pos_y] = 'E';
		map->run_map[map->player_x][map->player_y] = 'P';
		ft_printf("You can't leave without collecting all the coins\n");
	}
}

void	all_move(t_data *map, int pos_x, int pos_y)
{
	if (map->run_map[pos_x][pos_y] == '1')
		return ;
	else if (map->run_map[pos_x][pos_y] == 'C')
	{
		map->coins--;
		map->run_map[pos_x][pos_y] = 'P';
		map->run_map[map->player_x][map->player_y] = '0';
		img_to_window(map->mlx, map->texture->backgound_texture,
			map->player_y * 50, map->player_x * 50);
		map->player_x = pos_x;
		map->player_y = pos_y;
		img_to_window(map->mlx, map->texture->player_texture,
			pos_y * 50, pos_x * 50);
		map->count_moves++;
	}
	else if (map->run_map[pos_x][pos_y] == 'E')
		exit_check(map, pos_x, pos_y);
	else
		nothing(map, pos_x, pos_y);
	ft_printf("Count moves: %d\n", map->count_moves);
}

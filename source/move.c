/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:49:02 by sepun             #+#    #+#             */
/*   Updated: 2025/01/31 21:57:51 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"


void	move_rigth(t_data *map)
{
	if (map->run_map[map->player_y][map->player_x + 1] == '1')
		return ;
	else if (map->run_map[map->player_y][map->player_x + 1] == 'C')
		map->coins--;
	else if (map->run_map[map->player_y][map->player_x + 1] == 'E')
	{
		if (map->coins == 0)
		{
			ft_printf_error("You win\n");
		}
		else
			return ;
	}
	map->run_map[map->player_y][map->player_x] = '0';
	map->player_x++;
	map->run_map[map->player_y][map->player_x] = 'P';
	map->count_moves++;
	printf("count_moves: %d\n", map->count_moves);
}


void	move_left(t_data *map)
{
	if (map->run_map[map->player_y][map->player_x - 1] == '1')
		return ;
	else if (map->run_map[map->player_y][map->player_x - 1] == 'C')
		map->coins--;
	else if (map->run_map[map->player_y][map->player_x - 1] == 'E')
	{
		if (map->coins == 0)
		{
			ft_printf_error("You win\n");
		}
		else
			return ;
	}
	map->run_map[map->player_y][map->player_x] = '0';
	map->player_x--;
	map->run_map[map->player_y][map->player_x] = 'P';
	map->count_moves++;
	printf("count_moves: %d\n", map->count_moves);
}


void	move_up(t_data *map)
{
	if (map->run_map[map->player_y - 1][map->player_x] == '1')
		return ;
	else if (map->run_map[map->player_y - 1][map->player_x] == 'C')
		map->coins--;
	else if (map->run_map[map->player_y - 1][map->player_x] == 'E')
	{
		if (map->coins == 0)
		{
			ft_printf_error("You win\n");
		}
		else
			return ;
	}
	map->run_map[map->player_y][map->player_x] = '0';
	map->player_y--;
	map->run_map[map->player_y][map->player_x] = 'P';
	map->count_moves++;
}

void	move_down(t_data *map)
{
	if (map->run_map[map->player_y + 1][map->player_x] == '1')
		return ;
	else if (map->run_map[map->player_y + 1][map->player_x] == 'C')
		map->coins--;
	else if (map->run_map[map->player_y + 1][map->player_x] == 'E')
	{
		if (map->coins == 0)
		{
			ft_printf_error("You win\n");
		}
		else
			return ;
	}
	map->run_map[map->player_y][map->player_x] = '0';
	map->player_y++;
	map->run_map[map->player_y][map->player_x] = 'P';
	map->count_moves++;
}


void	ft_move(mlx_t *mlx, t_data *map)
{
	mlx_key_hook(mlx, &my_keyhook, map);
	mlx_loop(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2025/02/28 23:04:26 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

static void	verification_arg(int argc, char **argv)
{
	if (argc > 2)
		ft_printf_error("Error\nToo many arguments\n");
	if (argc == 2 && ft_check_ber(argv) == -1)
		ft_printf_error("Error\nThe file could not be executed\n");
}

void	free_and_print_error(t_data *game, char *error)
{
	ft_printf_error(error);
	free_struct(game);
}

void	locate_player(t_data *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->run_map[x])
	{
		y = 0;
		while (map->run_map[x][y] != '\0')
		{
			if (map->run_map[x][y] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*map;

	map = (t_data *)param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		all_move(map, map->player_x - 1, map->player_y);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		all_move(map, map->player_x + 1, map->player_y);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		all_move(map, map->player_x, map->player_y - 1);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		all_move(map, map->player_x, map->player_y + 1);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_struct(map);
		return ;
	}
	draw_player(map, map->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*map;

	verification_arg(argc, argv);
	map = ft_calloc(sizeof(t_data), 1);
	if (!map)
		free_struct(map);
	map->check = 0;
	ft_check_map(map, argv);
	if (map->check == 0)
	{
		ft_printf("Error\ningreso aqui \n");
		free_struct(map);
	}
	if ((map->map_x * 50) > MAX_MAP_X || (map->map_y * 50) > MAX_MAP_Y)
		free_and_print_error(map, "Error\nMapa demasiado grande\n");
	map->mlx = mlx_init(map->map_x * 50, map->map_y * 50, "so_long", true);
	if (!map->mlx)
		free_struct(map);
	locate_player(map);
	ft_texture(map, map->mlx);
	if (!map->texture)
		free_struct(map);
	ft_move(map->mlx, map);
	return (0);
}

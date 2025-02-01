/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2025/02/01 22:10:51 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	locate_player(t_data *map)
{
	int x;
	int y;
	
	x = 0;
	while (x < map->map_x)
	{
		y = 0;
		while (y < map->map_y)
		{
			if (map->run_map[y][x] == 'P')
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
	t_data *map;

	map = (t_data *)param;
	printf("los valores de x : %d y y son : %d\n", map->player_x, map->player_y);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		all_move(map, map->player_x, map->player_y - 1);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) 
		&& keydata.action == MLX_PRESS)
		all_move(map, map->player_x, map->player_y + 1);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		all_move(map, map->player_x - 1, map->player_y);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		all_move(map, map->player_x + 1, map->player_y);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);

	// print_map();
	print_map(map);
	// ft_printf("------------------------------------\n");
	// ft_printf("\n+++player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	// ft_printf("------------------------------------\n");
	draw_player(map, map->mlx);
}

int main(int argc, char **argv)
{
	t_data *map;
	
	if (argc > 2)
		ft_printf_error("Error\nDemasiados argumentos\n");
	if (argc == 2 && ft_check_ber(argv) == -1)
		ft_printf_error("Error\nNo es un archivo .ber\n");
	map = ft_calloc(sizeof(t_data), 1);
	if (!map)
		ft_printf_error("Error\nNo se pudo asignar memoria para el mapa\n");
	ft_check_map(map, argv);
	if (!(map->mlx = mlx_init(map->map_x * 50, map->map_y * 50, "so_long", true)))
		ft_printf_error("Error\nNo se pudo inicializar mlx\n");
	ft_texture(map,map->mlx);
	ft_move(map->mlx, map);
	mlx_loop(map->mlx);
	return (0);
}


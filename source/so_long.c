/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2025/01/31 21:58:00 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	locate_player(t_data *map)
{
	int i;
	int j;
	
	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (j < map->map_x)
		{
			if (map->run_map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				ft_printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data *map;

	map = (t_data *)param;
	(void)map;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_up(map);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) 
		&& keydata.action == MLX_PRESS)
		move_down(map);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_left(map);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_rigth(map);
	ft_texture(map, map->mlx);
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
	if (!(map->mlx = mlx_init(800, 600, "so_long", true)))
		ft_printf_error("Error\nNo se pudo inicializar mlx\n");
	locate_player(map);
	ft_texture(map,map->mlx);
	ft_move(map->mlx, map);
	mlx_loop(map->mlx);
	return (0);
}


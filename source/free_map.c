/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:59:22 by sepun             #+#    #+#             */
/*   Updated: 2025/02/18 20:52:22 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//LEAK SUMMARY:
// ==828021==    definitely lost: 120 bytes in 6 blocks
// ==828021==    indirectly lost: 50,000 bytes in 5 blocks
// ==828021==      possibly lost: 0 bytes in 0 blocks
// ==828021==    still reachable: 317,955 bytes in 3,106 blocks
// ==828021==         suppressed: 0 bytes in 0 blocks

#include "../Include/so_long.h"

void	free_map(t_data *map)
{
	int	i;

	i = 0;
	while (map->run_map[i])
	{
		free(map->run_map[i]);
		free(map->test_map[i]);
		i++;
	}
	free(map->run_map);
	free(map->test_map);
}

void	free_texture(t_texture *texture, mlx_t *mlx)
{
	if (!texture)
		return ;
	mlx_delete_image(mlx, texture->wall_texture);
	mlx_delete_image(mlx, texture->backgound_texture);
	mlx_delete_image(mlx, texture->player_texture);
	mlx_delete_image(mlx, texture->collectible_texture);
	mlx_delete_image(mlx, texture->exit_texture);
}

void	free_struct(t_data *map)
{
	if (map->texture)
	{
		free_texture(map->texture, map->mlx);
		free(map->texture);
	}
	if (map->run_map || map->test_map)
		free_map(map);
	if (map->mlx)
	{
		mlx_close_window(map->mlx);
		mlx_terminate(map->mlx);
	}
	if (map)
		free(map);
	exit(0);
}

void	check_convert_texture_to_image(t_data *s_data)
{
	if (!s_data->texture->wall_texture
		|| !s_data->texture->backgound_texture
		|| !s_data->texture->player_texture
		|| !s_data->texture->collectible_texture
		|| !s_data->texture->exit_texture)
		free_struct(s_data);
}

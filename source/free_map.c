/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:59:22 by sepun             #+#    #+#             */
/*   Updated: 2025/02/05 22:34:16 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void free_map(t_data *map)
{
	int i;

	i = 0;
	printf("free_map\n");
	while (map->run_map[i])
	{
		free(map->run_map[i]);
		free(map->test_map[i]);
		i++;
	}
	free(map->run_map);
	free(map->test_map);
}

void free_texture(t_texture *texture, mlx_t *mlx)
{
	printf("free_texture_ prueba\n");
	mlx_delete_image(mlx, texture->wall_texture);
	mlx_delete_image(mlx, texture->backgound_texture);
	mlx_delete_image(mlx, texture->player_texture);
	mlx_delete_image(mlx, texture->collectible_texture);
	mlx_delete_image(mlx, texture->exit_texture);
	// mlx_delete_texture(texture->wall_texture);
	// mlx_delete_texture(texture->backgound_texture);
	// mlx_delete_texture(texture->player_texture);
	// mlx_delete_texture(texture->collectible_texture);
	// mlx_delete_texture(texture->exit_texture);
	/* free(texture->wall_texture);
	free(texture->backgound_texture);
	free(texture->player_texture);
	free(texture->collectible_texture);
	free(texture->exit_texture); */
}

void free_struct(t_data *map)
{
	// mlx_terminate(map->mlx);
	// free(map->texture);
	printf("free_struct\n");
	if (map->texture)
	{
		free_texture(map->texture, map->mlx);
		free(map->texture);
	}
	if (map->run_map || map->test_map)
		free_map(map);
	// mlx_close_window(map->mlx);
	if (map->mlx)
		free(map->mlx);
	if (map)
		free(map);
	ft_printf("free_struct\n");
	exit(1);

	// mlx_close_hook(map->mlx, mlx_close, map);
}

void	check_convert_texture_to_image(t_data *s_data)
{
	if (!s_data->texture->wall_texture || !s_data->texture->backgound_texture ||
		!s_data->texture->player_texture || !s_data->texture->collectible_texture ||
		!s_data->texture->exit_texture)
		free_struct(s_data);
}


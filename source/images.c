/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:57:10 by sepun             #+#    #+#             */
/*   Updated: 2025/02/18 17:06:00 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cantidad de leaks, debe terminar en : 955 , de 3.106

#include "../Include/so_long.h"

void	load_textures(t_data *game)
{
	// void	*tmp;

	// tmp = NULL;

	if (!game)
		free_struct(game);
	game->texture = ft_calloc(sizeof(t_texture), 1);
	if (!game->texture)
		free_struct(game);
	// tmp = game->texture->wall_texture;
	game->texture->wall_texture = mlx_load_png("textures/wall.png");
	// printf("background: %p\n", game->texture->wall_texture);
	// printf("background: %p\n", tmp);
	// mlx_delete_image(game->mlx, tmp);
	// free(tmp);
	// tmp = game->texture->backgound_texture;
	game->texture->backgound_texture = mlx_load_png("textures/background.png");
	
	// mlx_delete_image(game->mlx, tmp);
	// free(tmp);
	// tmp = game->texture->player_texture;
	game->texture->player_texture = mlx_load_png("textures/player.png");
	// mlx_delete_image(game->mlx, tmp);
	// free(tmp);
	// tmp = game->texture->collectible_texture;
	game->texture->collectible_texture = mlx_load_png("textures/coins.png");
	// mlx_delete_image(game->mlx, tmp);
	// free(tmp);
	// tmp = game->texture->exit_texture;
	game->texture->exit_texture = mlx_load_png("textures/exit_final.png");
	// mlx_delete_image(game->mlx, tmp);
	// free(tmp);
	if (!game->texture->wall_texture || !game->texture->backgound_texture
		|| !game->texture->player_texture || !game->texture->collectible_texture
		|| !game->texture->exit_texture)
		free_struct(game);
	check_convert_texture_to_image(game);
}

void	convert_texture_to_image(t_data *s_data, mlx_t *mlx)
{
	void	*img;

	img = NULL;
	img = s_data->texture->wall_texture;
	s_data->texture->wall_texture = mlx_texture_to_image(mlx,
			s_data->texture->wall_texture);
	mlx_delete_texture(img);
	img = s_data->texture->backgound_texture;
	s_data->texture->backgound_texture = mlx_texture_to_image(mlx,
			s_data->texture->backgound_texture);
	mlx_delete_texture(img);
	img = s_data->texture->player_texture;
	s_data->texture->player_texture = mlx_texture_to_image(mlx,
			s_data->texture->player_texture);
	mlx_delete_texture(img);
	img = s_data->texture->collectible_texture;
	s_data->texture->collectible_texture = mlx_texture_to_image(mlx,
			s_data->texture->collectible_texture);
	mlx_delete_texture(img);
	img = s_data->texture->exit_texture;
	s_data->texture->exit_texture = mlx_texture_to_image(mlx,
			s_data->texture->exit_texture);
	mlx_delete_texture(img);
	if (!s_data->texture->wall_texture ||
		 !s_data->texture->backgound_texture
		 || !s_data->texture->player_texture
		 || !s_data->texture->collectible_texture
		 || !s_data->texture->exit_texture)	
		free_struct(s_data);
	check_convert_texture_to_image(s_data);
}

void	img_to_window(mlx_t *mlx, mlx_image_t *img, int i, int j)
{
	if (mlx_image_to_window(mlx, img, i, j) < 0)
		ft_printf_error("Error: No se pudo convertir la imagen a ventana.");
}

void	ft_texture(t_data *map, mlx_t *mlx)
{
	int	i;
	int	j;

	load_textures(map);
	convert_texture_to_image(map, mlx);
	exit(1);
	i = -1;
	while (map->run_map[++i] != NULL)
	{
		j = -1;
		while (map->run_map[i][++j] != '\0')
		{
			if (map->run_map[i][j] == '1')
				img_to_window(mlx, map->texture->wall_texture, j * 50, i * 50);
			else if (map->run_map[i][j] == '0')
				img_to_window(mlx, map->texture->backgound_texture,
					j * 50, i * 50);
			else if (map->run_map[i][j] == 'C')
				img_to_window(mlx, map->texture->collectible_texture,
					j * 50, i * 50);
			else if (map->run_map[i][j] == 'E')
				img_to_window(mlx, map->texture->exit_texture,
					j * 50, i * 50);
		}
	}
	draw_player(map, mlx);
}

void	draw_player(t_data *map, mlx_t *mlx)
{
	if (!map->texture || !map->texture->player_texture)
	{
		free_struct(map);
		return ;
	}
	if (mlx_image_to_window(mlx, map->texture->player_texture,
			map->player_y * 50, map->player_x * 50) < 0)
		free_struct(map);
}

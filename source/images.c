#include "../Include/so_long.h"

void	load_textures(t_data *game)
{
	game->texture = ft_calloc(sizeof(t_texture), 1);
	if (!game->texture)
		ft_printf_error("Error: No se pudo asignar memoria para las texturas\n");
	game->texture->wall_texture = mlx_load_png("textures/muro_50x50.png");
	game->texture->backgound_texture = mlx_load_png("textures/background_50x50.png");
	game->texture->player_texture = mlx_load_png("textures/background_player.png");
	game->texture->collectible_texture = mlx_load_png("textures/coins.png");
	game->texture->exit_texture = mlx_load_png("textures/exit_final.png");
	if (!game->texture->wall_texture || !game->texture->backgound_texture
		|| !game->texture->player_texture || !game->texture->exit_texture
		|| !game->texture->collectible_texture)
		ft_printf_error("Error: Una o más texturas no se pudieron cargar");
}

void convert_texture_to_image(t_data *s_data, mlx_t *mlx)
{
	mlx_image_t *img;
	
	img = mlx_texture_to_image(mlx ,s_data->texture->wall_texture);
	if (!img)
		ft_printf_error("Error: No se pudo convertir la textura a imagen.");
	s_data->texture->wall_texture = img;
	img = mlx_texture_to_image(mlx, s_data->texture->backgound_texture);
	if (!img)
		ft_printf_error("Error: No se pudo convertir la textura a imagen.");
	s_data->texture->backgound_texture = img;
	img = mlx_texture_to_image(mlx, s_data->texture->player_texture);
	if (!img)
		ft_printf_error("Error: No se pudo convertir la textura a imagen.");
	s_data->texture->player_texture = img;
	img = mlx_texture_to_image(mlx, s_data->texture->collectible_texture);
	if (!img)
		ft_printf_error("Error: No se pudo convertir la textura a imagen.");
	s_data->texture->collectible_texture = img;
	img = mlx_texture_to_image(mlx, s_data->texture->exit_texture);
	if (!img)
		ft_printf_error("Error: No se pudo convertir la textura a imagen.");
	s_data->texture->exit_texture = img;
}

void img_to_window(mlx_t *mlx, mlx_image_t *img, int i, int j)
{
	if (mlx_image_to_window(mlx, img, i, j) < 0)
		ft_printf_error("Error: No se pudo convertir la imagen a ventana.");
	
}

void ft_texture(t_data *map, mlx_t *mlx)
{
	int i;
	int j;
	load_textures(map);
	convert_texture_to_image(map, mlx);
	i = 0;
	while (i < map->map_x)
	{
		j = 0;
		while (j < map->map_y)
		{
			//printf("----i: %d, j: %d----\n", i, j);
			//printf("map->run_map[i][j]: %c\n", map->run_map[i][j]);
			if (map->run_map[i][j] == '1')
				img_to_window(mlx, map->texture->wall_texture, j * 50, i * 50);
			else if (map->run_map[i][j] == '0')
				img_to_window(mlx, map->texture->backgound_texture, j * 50, i * 50);
			else if (map->run_map[i][j] == 'C')
				img_to_window(mlx, map->texture->collectible_texture,j * 50,i * 50);
			else if (map->run_map[i][j] == 'E')
				img_to_window(mlx, map->texture->exit_texture,j * 50,i * 50);
			j++;
		}
		i++;
	}
	draw_player(map, mlx);
}

void draw_player(t_data *map, mlx_t *mlx)
{
	if (mlx_image_to_window(mlx, map->texture->player_texture, map->player_x * 50, map->player_y * 50) < 0)
		ft_printf_error("Error: No se pudo convertir la imagen a ventana.");
}

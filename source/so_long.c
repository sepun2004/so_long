/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2025/01/29 21:28:51 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h> 
#include "../Include/so_long.h"

// void ft_init() //Esta funcion debe generar a ventada
// {
// 	mlx_image_t *img;
// 	mlx_texture_t *texture;
	
	
	

// }

void	load_textures(t_data *game)
{
	game->texture = ft_calloc(sizeof(t_texture), 1);
	if (!game->texture)
		ft_printf_error("Error: No se pudo asignar memoria para las texturas\n");
	game->texture->wall_texture = mlx_load_png("textures/wall.png");
	game->texture->backgound_texture = mlx_load_png("textures/background.png");
	game->texture->player_texture = mlx_load_png("textures/Player.png");
	game->texture->collectible_texture = mlx_load_png("textures/coins.png");
	game->texture->exit_texture = mlx_load_png("textures/exit.png");
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

void img_to_window(mlx_t *mlx, mlx_image_t *img)
{
	if (!mlx_image_to_window(mlx, img, 0, 0))
		ft_printf_error("Error: No se pudo convertir la imagen a ventana.");
	
}

void ft_texture(t_data *map, mlx_t *mlx)
{
	load_textures(map);
	
	convert_texture_to_image(map, mlx);
	img_to_window(mlx, map->texture->wall_texture);
	img_to_window(mlx, map->texture->backgound_texture);
	img_to_window(mlx, map->texture->player_texture);
	img_to_window(mlx, map->texture->collectible_texture);
	img_to_window(mlx, map->texture->exit_texture);
	// render_map(); // mlx_image_to_window //Esto va en el renderizado // dibujar el player separado
	//mlx_loop(mlx);
	//Delete_texture / delete_image
}

int main(int argc, char **argv)
{
	t_data *map;
	
	if (argc > 2)
	{
		ft_printf("Error\n");
		return (-1);
	} 
	if (argc == 2 && ft_check_ber(argv) == -1)
	{
		ft_printf("No es un archivo .ber\n");
		return(-1);
	}
	map = ft_calloc(sizeof(t_data), 1);
	if (!map)
	{
		ft_printf("Error\n");
		return (-1);
	}
	ft_check_map(map, argv);
	mlx_t *mlx;
	// mlx_image_t *img;
	// mlx_texture_t *texture;
	if (!(mlx = mlx_init(800, 600, "so_long", true)))
		ft_printf_error("Error\nNo se pudo inicializar mlx\n");
	// ft_init();
	ft_texture(map, mlx);
	// mlx_loop(mlx);	
	return (0);
}


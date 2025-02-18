/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:00 by sepun             #+#    #+#             */
/*   Updated: 2025/02/18 20:31:07 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#define MAX_MAP_X 1000
#define MAX_MAP_Y 1500

typedef struct s_texture
{
	void	*wall_texture;
	void	*player_texture;
	void	*exit_texture;
	void	*collectible_texture;
	void	*backgound_texture;
}			t_texture;

typedef struct s_data
{
	int			i;
	int			j;
	int			check;
	int			map_x;
	int			map_y;
	int			coins;
	char		**test_map;
	char		**run_map;
	int			player_x;
	int			player_y;
	int			count_moves;
	mlx_t		*mlx;
	t_texture	*texture;
}			t_data;

//CHECK_MAP
void	ft_printf_error(char *str);
void	parce_map(t_data *map);

//PARCE_MAP
void	ft_check_map(t_data *map, char **argv);
void	ft_check_objects(t_data *test_map);
void	ft_check_rectangle_map(t_data *game);
void	ft_check_border(t_data *game);
void	locate_player(t_data *map);
void	flood_fill(t_data *game, int x, int y);
int		ft_check_ber(char **argv);

//TEXTURES
void	ft_texture(t_data *map, mlx_t *mlx);
void	load_textures(t_data *game);
void	convert_texture_to_image(t_data *s_data, mlx_t *mlx);
void	img_to_window(mlx_t *mlx, mlx_image_t *img, int i, int j);
void	draw_player(t_data *map, mlx_t *mlx);

//MOVE
void	ft_move(mlx_t *mlx, t_data *map);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	all_move(t_data *map, int pos_x, int pos_y);
void	exit_check(t_data *map, int pos_x, int pos_y);
void	nothing(t_data *map, int pos_x, int pos_y);

//IMAGES
void	update_textures(t_data *map, int pos_x, int pos_y, mlx_t *mlx);

//FREE
void	free_texture(t_texture *texture, mlx_t *mlx);
void	free_map(t_data *map);
void	free_and_print_error(t_data *game, char *error);
void	check_convert_texture_to_image(t_data *s_data);
void	free_struct(t_data *map);

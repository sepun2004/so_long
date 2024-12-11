/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:00 by sepun             #+#    #+#             */
/*   Updated: 2024/12/11 19:28:42 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_map
{
	int i;
	int j;
	int k;
	int map_x;
	int map_y;
	int coins;
	char **test_map;
	char **run_map;
}               t_map;

typedef struct s_data
{
	// void	mlx;
	t_map	*map;
	
}			t_data;


void    ft_check_map(t_map *map, char **argv);
void    parce_map(t_map *map);
void    ft_check_objects(t_map *test_map);
void	ft_check_rectangle_map(t_map *game);
void    ft_check_long_map(t_map *test_map);
void	ft_check_border(t_map *game);
void    ft_printf_error(char *str);
int     ft_check_ber(char **argv);
void	print_map(char **map);
int ft_strelen_char_doble_puntero(char **str);







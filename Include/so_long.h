/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:00 by sepun             #+#    #+#             */
/*   Updated: 2024/12/11 21:51:35 by marvin           ###   ########.fr       */
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

//PARCE_MAP
void	ft_check_rectangle_map(t_map *game);
void	ft_check_border(t_map *game);
void	ft_check_objects(t_map *test_map);
int		ft_check_ber(char **argv);

//so_long
void ft_check_map(t_map *map, char **argv);
void parce_map(t_map *map);
void ft_printf_error(char *str);
void print_map(char **map);







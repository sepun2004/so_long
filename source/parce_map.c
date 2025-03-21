/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:50:32 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 21:50:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

// static void print_map(t_data *game)
// {
// 	int	i;

// 	i = 0;
// 	while (game->test_map[i])
// 	{
// 		ft_printf("%s\n", game->test_map[i]);
// 		i++;
// 	}
// 	ft_printf("\n");
// }	

void	ft_check_rectangle_map(t_data *game)
{
	int	i;

	i = 0;
	game->map_x = ft_strlen(game->test_map[i]);
	i = -1;
	while (game->test_map[++i])
	{
		if ((size_t)game->map_x != ft_strlen(game->test_map[i]))
			ft_printf_error("Error\nNot valid rectangle map\n");
	}
	game->map_y = i;
}

void	ft_check_border(t_data *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->test_map[++y])
	{
		if (y == 0 || y == game->map_y - 1)
		{
			x = -1;
			while (game->test_map[y][++x])
				if (game->test_map[y][x] != '1')
					ft_printf_error("Error\nNot valid border\n");
		}
		else if (game->test_map[y][0] != '1' ||
			game->test_map[y][game->map_x - 1] != '1')
			ft_printf_error("Error\nNot valid border\n");
	}
}

void	ft_check_objects(t_data *test_map)
{
	int	p;
	int	e;
	int	x;
	int	y;

	test_map->coins = 0;
	y = -1;
	p = 0;
	e = 0;
	while (test_map->test_map[++y])
	{
		x = -1;
		while (test_map->test_map[y][++x])
		{
			if (test_map->test_map[y][x] == 'C')
				test_map->coins++;
			else if (test_map->test_map[y][x] == 'E')
				e++;
			else if (test_map->test_map[y][x] == 'P')
				p++;
		}
	}
	if (test_map->coins < 1 || e != 1 || p != 1)
		free_and_print_error(test_map, "Error\nNot valid objects\n");
}

int	ft_check_ber(char **argv)
{
	int	j;

	j = ft_strlen(argv[1]);
	if (j < 5)
		return (-1);
	if (argv[1][j - 1] != 'r' && argv[1][j - 2] != 'e'
		&& argv[1][j - 3] != 'b' && argv[1][j - 4] != '.')
		return (-1);
	return (0);
}

void	flood_fill(t_data *game, int x, int y)
{
	if (game->test_map[x][y] == '1' || game->test_map[x][y] == 'X')
		return ;
	if (game->test_map[x][y] == 'C')
		game->coins--;
	if (game->test_map[x][y] == 'E' && game->coins != 0)
	{
		game->test_map[x][y] = 'X';
		game->check = 1;
		return ;
	}
	game->test_map[x][y] = 'X';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
}

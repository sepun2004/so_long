/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:23 by sepun             #+#    #+#             */
/*   Updated: 2025/02/01 22:08:41 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void    ft_check_map(t_data *map, char **argv)
{
    int     fd;
    char    *line;
    char    *new_line;

    new_line = ft_strdup("");
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_printf_error("Error\nNo se pudo abrir el archivo\n");
    line = get_next_line(fd);
    while (line)
    {
        new_line = ft_strjoin(new_line, line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    map->test_map = ft_split(new_line, '\n');
    map->run_map = ft_split(new_line, '\n');
    if (map->test_map == NULL || map->run_map == NULL)
        ft_printf_error("Error\nNo se pudo dividir el mapa\n");
    free(new_line);
    parce_map(map);
}

void    parce_map(t_data *map)
{
	int coins;

	coins = 0;
    ft_check_objects(map);
    ft_check_rectangle_map(map);
    ft_check_border(map);
	locate_player(map);
	printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	coins = map->coins;
	// printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	flood_fill(map, map->player_x, map->player_y);
	map->coins = coins;
}

void    ft_printf_error(char *str)
{
    ft_printf("%s", str);
    exit(1);
}

// void    print_map(char **map)
// {
//     int i;

//     i = -1;
//     while (map[++i] != NULL)
//         ft_printf("%s\n", map[i]);
// }

void print_map(t_data *map)
{
	int x;
	int y;

	y = 0;
	while (map->run_map[y])
	{
		x = 0;
		while (map->run_map[y][x])
		{
			ft_printf("%c", map->run_map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}	

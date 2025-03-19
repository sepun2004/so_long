/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:23 by sepun             #+#    #+#             */
/*   Updated: 2025/02/28 23:05:02 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	ft_check_map(t_data *map, char **argv)
{
	char	*line;
	char	*new_line;
	char	*temp;
	int		fd;

	new_line = ft_strdup("");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_printf_error("Error\nCould not open file\n");
	line = get_next_line(fd);
	while (line)
	{
		temp = new_line;
		new_line = ft_strjoin(new_line, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->test_map = ft_split(new_line, '\n');
	map->run_map = ft_split(new_line, '\n');
	if (map->test_map == NULL || map->run_map == NULL)
		ft_printf_error("Error\ncould not split map\n");
	free(new_line);
	parce_map(map);
}

static void	ft_check_valid_characters(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->test_map[i])
	{
		j = 0;
		while (map->test_map[i][j])
		{
			if (map->test_map[i][j] != '1' && map->test_map[i][j] != '0' &&
				map->test_map[i][j] != 'P' && map->test_map[i][j] != 'E' &&
				map->test_map[i][j] != 'C')
				free_and_print_error(map, "Error\nInvalid characters\n");
			j++;
		}
		i++;
	}
}

void	parce_map(t_data *map)
{
	int	coins;
	int	i;

	i = 0;
	coins = 0;
	ft_check_valid_characters(map);
	ft_check_objects(map);
	ft_check_rectangle_map(map);
	ft_check_border(map);
	locate_player(map);
	coins = map->coins;
	flood_fill(map, map->player_x, map->player_y);
	if (map->coins != 0)
		free_and_print_error(map, "Error\na coin is unattainable\n");
	while (map->test_map[i])
	{
		if (ft_strchr(map->test_map[i], 'E') != NULL)
			free_and_print_error(map, "Error\nno exit\n");
		i++;
	}
	if (map->coins == 0 && ft_strchr(map->test_map[i], 'E') == NULL)
	{
		map->check = 1;
	}
	map->coins = coins;
}

void	ft_printf_error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

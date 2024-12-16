/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:23 by sepun             #+#    #+#             */
/*   Updated: 2024/12/16 18:50:36 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void    ft_check_map(t_map *map, char **argv)
{
    int     fd;
    char    *line;
    char    *new_line;

    new_line = ft_strdup("");
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_printf_error("Error\nNo se pudo abrir el archivo\n");
    line = get_next_line(fd);
    while (line != NULL)
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
    print_map(map->test_map);
    parce_map(map);
}

void    parce_map(t_map *map)
{
    ft_check_objects(map);
    ft_check_rectangle_map(map);
    ft_check_border(map);
    
}

void    ft_printf_error(char *str)
{
    ft_printf("%s", str);
    exit(1);
}

void    print_map(char **map)
{
    int i;

    i = -1;
    while (map[++i] != NULL)
        ft_printf("%s\n", map[i]);
}
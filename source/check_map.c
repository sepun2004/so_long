/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:23 by sepun             #+#    #+#             */
/*   Updated: 2024/12/10 18:29:39 by sepun            ###   ########.fr       */
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
		ft_printf_error("Error\n No se pudo abrir el archivo\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		new_line = ft_strjoin(new_line, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->test_map = ft_split(new_line, ' ');
	map->run_map = ft_split(new_line, ' ');
	if (map->test_map == NULL || map->run_map == NULL)
		ft_printf_error("Error\n No se pudo dividir el mapa\n");
		// return -1;
	free(new_line);
	print_map(map->test_map);
	parce_map(map);

}

void    parce_map(t_map *map)
{
    ft_check_objects(map);
    ft_check_border (map);
}

void ft_check_border()
{
    
}

void	ft_check_objects(t_map *test_map)
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
			if (test_map->test_map[y][x] == 'E')
				e++;
			if (test_map->test_map[y][x] == 'P')
				p++;
		}
	}
	if (test_map->coins < 1 || e != 1 || p != 1)
		ft_printf_error("Error\nNot valid objects in check_objects\n");
}

void    ft_printf_error(char *str)
{
    ft_printf("%s", str);
    exit(1);
}
// 11111
// 1P001
// 10C01
// 10E01
// 10001
// 11111


// int	ft_check_border(char **argv)
// {
// 	int fd;
// 	int i;
// 	int k;
// 	int j;
// 	char *line;
	
// 	i = 0;
// 	k = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	while ((line = get_next_line(fd)))
// 	{
// 		while (line[i]!= '\0')
// 		{
// 			printf("Ingrese al bucle\n");
// 			j = ft_strlen(line);
// 			if (line[i] != '1' &&/* i < j && */line[j] == '\n')
// 			{
// 				printf("No es un mapa valido////\n");
// 				return (-1);
// 			}
// 			i++;
// 		}
// 		k++;
// 		free(line);
// 	}
// 	return (0);
// }



// void	ft_check_long_map(t_map *test_map)
// {
// 	int	y;

// 	y = 0;
// 	test_map->map_x = ft_strlen(test_map->map_y[y]);
// 	printf("map_x = %d\n", test_map->map_x);
//     // y = -1;
// 	// while (test_map->map[++y])
// 	// {
// 	// 	if (test_map->map_x != (int)ft_strlen(test_map->map[y]))
// 	// 	{
// 	// 		ft_error("Error\n Not valid map isn't rectangle\n");
// 	// 		break ;
// 	// 	}
// 	// }
// 	// test_map->map_y = y;
// 	// if (test_map->map_y >= 32 || test_map->map_x >= 60)
// 	// 	ft_error("Error\n Not valid map is very long\n");
// }




int ft_strelen_char_doble_puntero(char **str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != NULL)
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            j++;
        }
        i++;
    }
    return (j);
}
// int ft_read_map(char **argv)
// {
//     int fd;
//     char *line;
//     // char *tmp;
//     int i;
//     int j;

//     i = 0;
//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1)
//         return (-1);
//     while ((line = get_next_line(fd)))
// 	{
//         j = 0;
//         while (line[j] != '\0')
//         {
//             if (line[j] != '1' && line[j] != '0' && line[j] != 'P' && line[j] != 'E' && line[j] != 'C' && line[j] != '\n')
//             {
// 				printf("Dio error en el if----\n");
//                 return(-1);
//             }
//             j++;
//         }
//         i++;
// 		free(line);
//     }
//     return (0);
// }


void print_map(char **map)
{
	int i;

	i = -1;
	while (map[++i] != NULL)
		ft_printf("%s\n", map[i]);
}


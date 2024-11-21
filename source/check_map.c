/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:23 by sepun             #+#    #+#             */
/*   Updated: 2024/11/21 20:21:14 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	print_map(char **map)
{
	int i;

	i = -1;
	while (map[++i] != NULL)
		ft_printf("%s\n", map[i]);
}

int ft_check_map(t_data *data, char **argv)
{
	int fd;
	char *line;
	char *new_line;
	
	new_line = ft_strdup("");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		new_line = ft_strjoin(new_line, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->test_map = ft_split(new_line, ' ');
	data->run_map = ft_split(new_line, ' ');
	if (data->test_map == NULL || data->run_map == NULL)
		return (-1);
	free(new_line);
	print_map(data->test_map);
	exit(0);
	return(0);
}


// 11111
// 1P001
// 10C01
// 10E01
// 10001
// 11111

int	ft_check_border(char **argv)
{
	int fd;
	int i;
	int k;
	int j;
	char *line;
	
	i = 0;
	k = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		while (line[i]!= '\0')
		{
			printf("Ingrese al bucle\n");
			j = ft_strlen(line);
			if (line[i] != '1' &&/* i < j && */line[j] == '\n')
			{
				printf("No es un mapa valido////\n");
				return (-1);
			}
			i++;
		}
		k++;
		free(line);
	}
	return (0);
}

int	ft_check_long_map(char **argv)
{
	int fd;
	int i;
	int long_map;
	int long_map2;
	// int fd2;
	char *line;
	
	long_map = 0;
	long_map2 = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		long_map = ft_strlen(line);
		if(line[long_map - 1] == '\n')
		{
			long_map--;
		}
		printf("long_map es %d\n", long_map);
		printf("line es %d\n", long_map2);
		if (long_map != long_map2 && long_map2 != 0 )
		{
			printf("No es un mapa valido\n");
			return (-1);
		}
		long_map2 = long_map;
		i++;
	}
	return (0);
}

int ft_read_map(char **argv)
{
    int fd;
    char *line;
    // char *tmp;
    int i;
    int j;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    while ((line = get_next_line(fd)))
	{
        j = 0;
        while (line[j] != '\0')
        {
            if (line[j] != '1' && line[j] != '0' && line[j] != 'P' && line[j] != 'E' && line[j] != 'C' && line[j] != '\n')
            {
				printf("Dio error en el if----\n");
                return(-1);
            }
            j++;
        }
        i++;
		free(line);
    }
    return (0);
}

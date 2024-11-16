/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:23 by sepun             #+#    #+#             */
/*   Updated: 2024/11/16 18:36:21 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int ft_check_map(char **argv)
{
    if (ft_read_map(argv) == -1)
    {
		printf("dio error en ft_read_map\n");
        return (-1);
    }
	if (ft_check_long_map(argv) == -1)
	{
		printf("dio error en ft_check_long_map\n");
		return (-1);
	}
	
    return(0);    
}

int ft_check_long_map(char **argv)
{
	int fd;
	int i;
	int long_map;
	int long_map2;
	// int fd2;
	char *line;
	
	long_map = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		long_map = ft_strlen(line);
		if(line[long_map - 1] == '\n')
		{
			// line[long_map - 1] = '\0';
			long_map--;
		}
		line = get_next_line(fd);
		long_map2 = ft_strlen(line);
		if(line[long_map2 - 1] == '\n')
		{
			// line[long_map2 - 1] = '\0';
			long_map2--;
		}
		printf("long_map es %d\n", long_map);
		printf("line es %d\n", long_map2);
		if (long_map != long_map2)
		{
			printf("No es un mapa valido\n");
			return (-1);
		}
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
		// line = ft_strtrim(line, " ");
		// if (line == NULL)
		// 	return (-1);
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

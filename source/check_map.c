/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:23 by sepun             #+#    #+#             */
/*   Updated: 2024/11/06 10:28:07 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_check_map(char **argv)
{
    if (ft_read_map(argv) == -1)
    {
        return (-1);
    }
    return(0);    
}
int ft_read_map(char **argv)
{
    
    int fd;
    char *line;
    int i;
    int j;

    i = 0;
    j = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    while (get_next_line(fd))
    {
        line = get_next_line(fd);
        while (line[j] != '\0')
        {
            if (line[j] != '1' && line[j] != '0' && line[j] != 'P' && line[j] != 'E' && line[j] != 'C')
            {
                ft_printf("Error");
                return(-1);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

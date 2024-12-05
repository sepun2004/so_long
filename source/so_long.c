/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:11 by sepun             #+#    #+#             */
/*   Updated: 2024/12/05 16:56:05 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h> 
#include "../Include/so_long.h"

int main(int argc, char **argv)
{
	// int result;
	t_data *data;

	if (argc > 2)
	{
		ft_printf("Error\n");
		return (-1);
	} 
	if (argc == 2 && ft_check_ber(argv) == -1)
	{
		ft_printf("No es un archivo .ber\n");
		return(-1);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	
	if (ft_check_map(data, argv))
	{
		ft_printf("No es un mapa valido\n");
		return (-1);
	}
	
	// printf("ft_check_map es %d\n", result);
	return (0);
} 

int ft_check_ber(char **argv)
{
	int j;
	
	j = ft_strlen(argv[1]);
	if (j < 4)
	{
		return (-1);
	}
	if (argv[1][j - 1] != 'r' && argv[1][j - 2] != 'e' && argv[1][j - 3] != 'b' && argv[1][j - 4] != '.')
	{
		return (-1);
	}
	return (0);
}


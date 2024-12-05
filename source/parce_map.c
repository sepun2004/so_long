/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:56:43 by sepun             #+#    #+#             */
/*   Updated: 2024/12/05 17:02:34 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Include/so_long.h"

int ft_check_map(data, argv)
{
	printf("Ingrese a ft_check_map\n");
	if (ft_check_char(argv) == -1)
	{
		ft_printf("Error en check char\n");
		return (-1);
	}
	if (ft_check_long_map(argv) == -1)
	{
		// ft_printf("No es un mapa valido\n");
		return (-1);
	}
	if (ft_check_border(argv) == -1)
	{
		// ft_printf("No es un mapa valido\n");
		return (-1);
	}
	if (ft_read_map(argv) == -1)
	{
		// ft_printf("No es un mapa valido\n");
		return (-1);
	}
	return (0);
}


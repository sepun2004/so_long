/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:00 by sepun             #+#    #+#             */
/*   Updated: 2024/11/21 20:12:11 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_map
{
	int i;
	int j;
	int k;
	int map_x;
	int map_y;
	int coins;
}               t_map;

typedef struct s_data
{
	t_map	*map;
	char	**test_map;
	char	**run_map;
}			t_data;

//Parce
int ft_check_map(t_data *data, char **argv);
int ft_check_long_map(char **argv);
int ft_read_map(char **argv);
int	ft_check_border(char **argv);
// int ft_count_elements(char **argv);
int main(int argc, char **argv);


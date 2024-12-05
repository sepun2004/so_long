/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <sepun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:00 by sepun             #+#    #+#             */
/*   Updated: 2024/12/05 16:09:01 by sepun            ###   ########.fr       */
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

//Parceo
int		ft_check_map(t_data *data, char **argv);
int		ft_check_long_map(char **argv);
int		ft_read_map(char **argv);
int		ft_check_border(char **argv);
void	is_ordered(t_list *stack_a);
//
int ft_check_char(t_data *data);

int parce_map(t_data *data);

//
void print_map(char **map);
//
int ft_check_ber(char **argv);
int ft_count_elements(char **argv);

// int ft_chek_ber(char **argv);

// int ft_count_elements(char **argv);
int		main(int argc, char **argv);


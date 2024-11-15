/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:40:07 by sepun             #+#    #+#             */
/*   Updated: 2023/09/25 20:48:07 by sepun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int x)
{
	while ((x >= '0' && x <= '9'))
		return (1);
	return (0);
}
/*int main() {
    int x;

	x = 2;
	printf("%d", ft_isdigit(x));

}*/

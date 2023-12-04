/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:37:03 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/02 17:52:50 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_int_color(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xff);
}

int validate_colors(char *rgb, t_error *error)
{
	char	**numbers;

	numbers = ft_split(rgb, ',');
	if (!numbers)
	{
		*error = MEMORY_ERROR;
		return (0);
	}
	// TODO: Validar errores de los números (rango, más números de lo normal, menos, ...)
	*error = NO_ERROR;
	return (rgb_to_int_color(ft_atoi(numbers[0]),
			ft_atoi(numbers[1]), ft_atoi(numbers[2])));
}

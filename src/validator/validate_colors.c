/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:37:03 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 16:03:45 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_range(int number)
{
	return (0 <= number && number <= 255);
}

static int	rgb_to_int_color(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xff);
}

int	validate_colors(char *rgb, t_error *error)
{
	char	**numbers;
	int		r_number;
	int		g_number;
	int		b_number;

	numbers = ft_split(rgb, ',');
	if (!numbers)
	{
		*error = MEMORY_ERROR;
		return (0);
	}
	r_number = ft_atoi(numbers[0]);
	g_number = ft_atoi(numbers[1]);
	b_number = ft_atoi(numbers[2]);
	if (!valid_range(r_number) || !valid_range(g_number)
		|| !valid_range(b_number))
	{
		*error = INVALID_RANGE_COLOR;
		return (0);
	}
	*error = NO_ERROR;
	return (rgb_to_int_color(r_number, g_number, b_number));
}

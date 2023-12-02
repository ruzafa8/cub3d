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

static int32_t	rgb_to_int_color(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 0xff);
}

t_error	validate_floor_color(char *line, t_cub3d *cub3d)
{
	char	**numbers;

	if (ft_strlen(line) > 2 && line[0] == 'F' && line[1] == ' ')
	{
		numbers = ft_split(line + 2, ',');
		cub3d->floor_color = rgb_to_int_color(ft_atoi(numbers[0]),
				ft_atoi(numbers[1]), ft_atoi(numbers[2]));
		return (NO_ERROR);
	}
	return (PARSER_ERROR);
}

t_error	validate_ceil_color(char *line, t_cub3d *cub3d)
{
	char	**numbers;

	if (ft_strlen(line) > 2 && line[0] == 'C' && line[1] == ' ')
	{
		numbers = ft_split(line + 2, ',');
		cub3d->ceil_color = rgb_to_int_color(ft_atoi(numbers[0]),
				ft_atoi(numbers[1]), ft_atoi(numbers[2]));
		return (NO_ERROR);
	}
	return (PARSER_ERROR);
}

t_error validate_colors(int fd, t_cub3d *cub3d)
{
	t_error error;

	error = validate_floor_color(ft_get_next_line(fd), cub3d);
	if (error != NO_ERROR)
		return (error);
	error = validate_ceil_color(ft_get_next_line(fd), cub3d);
	return (error);
}

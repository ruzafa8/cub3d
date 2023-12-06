/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:49:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/06 12:50:07 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	first_end_line(t_map *line, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		if (line[index] != VOID && line[index] != WALL)
			return (0);
		index++;
	}
	return (1);
}

static int	any_neightbour_void(t_map **map, size_t x, size_t y, size_t max_y)
{
	if (y == 0)
		return (map[x - 1][y] == VOID || map[x + 1][y] == VOID
			|| map[x][y + 1] == VOID);
	if (y == max_y - 1)
		return (map[x - 1][y] == VOID || map[x + 1][y] == VOID
			|| map[x][y - 1] == VOID);
	return (map[x - 1][y] == VOID || map[x + 1][y] == VOID
		|| map[x][y - 1] == VOID || map[x][y + 1] == VOID);
}

int	validate_border(t_map **map, size_t max_x, size_t max_y)
{
	size_t	i;
	size_t	j;

	i = 1;
	if (!first_end_line(map[0], max_x)
		|| ! first_end_line(map[max_x - 1], max_x))
		return (0);
	while (i < max_x - 1)
	{
		j = 0;
		while (j < max_y)
		{
			if (map[i][j] == FLOOR && any_neightbour_void(map, i, j, max_y))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

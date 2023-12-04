/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:49:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 20:49:50 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	first_end_line(t_map *line)
{
	while (*line)
	{
		if (*line != VOID && *line != WALL)
			return (0);
		line++;
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
	if (!first_end_line(map[0]) || ! first_end_line(map[max_x - 1]))
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

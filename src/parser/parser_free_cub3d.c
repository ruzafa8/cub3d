/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_cub3d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:15:52 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/07 16:36:09 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_free(t_map **map, size_t height)
{
	size_t	x;

	x = 0;
	while (x < height)
	{
		free(map[x]);
		x++;
	}
}

void	parser_free_cub3d(t_cub3d **cub3d)
{
	if ((*cub3d)->north_texture)
		free((*cub3d)->north_texture);
	if ((*cub3d)->south_texture)
		free((*cub3d)->south_texture);
	if ((*cub3d)->west_texture)
		free((*cub3d)->west_texture);
	if ((*cub3d)->east_texture)
		free((*cub3d)->east_texture);
	if ((*cub3d)->map)
	{
		map_free((*cub3d)->map, (*cub3d)->height);
		free((*cub3d)->map);
	}
	if ((*cub3d)->player)
		free((*cub3d)->player);
	free(*cub3d);
}

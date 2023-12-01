/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_cub3d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:15:52 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/11/29 20:55:30 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		free((*cub3d)->map);
	free(*cub3d);
}

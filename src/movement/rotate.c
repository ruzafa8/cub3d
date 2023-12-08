/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:06:27 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 18:28:44 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * performs a rotation of the player in the shot
 * both in the direction of gaze and in the camera plane.
 * @param data: info game.
 * @param dir: direction.
 */

void	rotate_player(t_data *data, int dir)
{
	t_player	*player;
	double		rotation;
	double		tmp;

	player = data->cub3d->player;
	rotation = ROT_SPEED * dir;
	tmp = player->dir_x;
	player->dir_x = player->dir_x * cos(rotation)
		- player->dir_y * sin(rotation);
	player->dir_y = tmp * sin(rotation)
		+ player->dir_y * cos(rotation);
	tmp = player->plane_x;
	player->plane_x = player->plane_x * cos(rotation)
		- player->plane_y * sin(rotation);
	player->plane_y = tmp * sin(rotation)
		+ player->plane_y * cos(rotation);
}

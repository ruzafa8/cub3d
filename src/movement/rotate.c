/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:06:27 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 17:18:48 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

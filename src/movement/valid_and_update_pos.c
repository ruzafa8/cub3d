/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_update_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:51:44 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 16:32:39 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_pos(t_data *data, double x, double y)
{
	return (x > 0.25 && y > 0.25
		&& x < data->cub3d->height - COLLIDER_DIST
		&& y < data->cub3d->width - COLLIDER_DIST
		&& data->cub3d->map[(int) x][(int) y] == FLOOR);
}

void	update_pos(t_data *data, double x, double y)
{
	if (is_valid_pos(data, x, data->cub3d->player->pos_y))
		data->cub3d->player->pos_x = x;
	if (is_valid_pos(data, data->cub3d->player->pos_x, y))
		data->cub3d->player->pos_y = y;
}
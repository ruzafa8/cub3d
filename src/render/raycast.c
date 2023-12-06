/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:32 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/06 10:36:54 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void cal_euclidean_dis(t_raycast *raycast, t_player *player)
{
	if (raycast->dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (player->pos_x - raycast->map_x) * raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - player->pos_x)
			* raycast->delta_dist_x;
	}
	if (raycast->dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (player->pos_y - raycast->map_y) * raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - player->pos_y)
			* raycast->delta_dist_y;
	}
}

static void set_raycast(t_data *data, int x)
{
    t_raycast   *raycast;
    t_player    *player;
    double       camera_x;

    raycast = data->raycast;
    player = data->cub3d->player;
    camera_x = 2 * x / (double) WIDTH -1;
	raycast->dir_x = data->cub3d->player->dir_x + data->cub3d->player->plane_x * camera_x;
	raycast->dir_y = data->cub3d->player->dir_y + data->cub3d->player->plane_y * camera_x;
	raycast->map_x = (int) data->cub3d->player->pos_x;
	raycast->map_y = (int) data->cub3d->player->pos_y;
	if (raycast->dir_x == 0)
		raycast->delta_dist_x = INFINITE;
	else
		raycast->delta_dist_x = fabs(1 / raycast->dir_x);
	if (raycast->dir_y == 0)
		raycast->delta_dist_y = INFINITE;
	else
		raycast->delta_dist_y = fabs(1 / raycast->dir_y);
	cal_euclidean_dis(raycast, player);
}

void	render_frame(t_data *data)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		set_raycast(data, x);
		//execute_dda(data, data->ray);
		//calculate_heights(data->ray);
		//textures_calculation(data, data->ray, data->player, x);
	}
}
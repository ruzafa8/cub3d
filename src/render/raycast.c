/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:32 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 11:25:41 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cal_heights(t_raycast *raycast)
{
	if (raycast->side == HIT_X)
		raycast->perp_wall_dist = raycast->side_dist_x - raycast->delta_dist_x;
	else
		raycast->perp_wall_dist = raycast->side_dist_y - raycast->delta_dist_y;
	raycast->line_height = (int) HEIGHT / raycast->perp_wall_dist;
	raycast->draw_start = -(raycast->line_height) / 2 + HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + HEIGHT / 2;
	if (raycast->draw_end >= HEIGHT)
		raycast->draw_end = HEIGHT - 1;
}

static void	exec_dda(t_data *data, t_raycast *raycast)
{
	while (true)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			if (raycast->step_x == FORWARD)
				raycast->map_x++;
			else
				raycast->map_x--;
			raycast->side = HIT_X;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			if (raycast->step_y == FORWARD)
				raycast->map_y++;
			else
				raycast->map_y--;
			raycast->side = HIT_Y;
		}
		if (data->cub3d->map[raycast->map_x][raycast->map_y] == WALL)
			return ;
	}
}

static void	cal_euclidean_dis(t_raycast *raycast, t_player *player)
{
	if (raycast->dir_x < 0)
	{
		raycast->step_x = BACKWARD;
		raycast->side_dist_x = (player->pos_x - raycast->map_x)
			* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = FORWARD;
		raycast->side_dist_x = (raycast->map_x + 1.0 - player->pos_x)
			* raycast->delta_dist_x;
	}
	if (raycast->dir_y < 0)
	{
		raycast->step_y = BACKWARD;
		raycast->side_dist_y = (player->pos_y - raycast->map_y)
			* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = FORWARD;
		raycast->side_dist_y = (raycast->map_y + 1.0 - player->pos_y)
			* raycast->delta_dist_y;
	}
}

static void	set_raycast(t_data *data, int x)
{
	t_raycast	*raycast;
	t_player	*player;
	double		camera_x;

	raycast = data->raycast;
	player = data->cub3d->player;
	camera_x = 2 * x / (double) WIDTH - 1;
	raycast->dir_x = data->cub3d->player->dir_x + data->cub3d->player->plane_x
		* camera_x;
	raycast->dir_y = data->cub3d->player->dir_y + data->cub3d->player->plane_y
		* camera_x;
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
		exec_dda(data, data->raycast);
		cal_heights(data->raycast);
		ft_printf("heights\n");
		cal_texture(data, data->raycast, data->cub3d->player, x);
		ft_printf("texture\n");
	}
}

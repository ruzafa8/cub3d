#include "cub3d.h"

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
	//calculate_euclidean_dis(raycast, player);
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
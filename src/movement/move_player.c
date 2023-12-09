/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:16:25 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/09 18:33:11 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_data *data)
{
	double	x;
	double	y;

	x = data->cub3d->player->pos_x + data->cub3d->player->dir_x * MOV_SPEED;
	y = data->cub3d->player->pos_y + data->cub3d->player->dir_y * MOV_SPEED;
	update_pos(data, x, y);
}

static void	move_right(t_data *data)
{
	double	x;
	double	y;

	x = data->cub3d->player->pos_x + data->cub3d->player->dir_y * MOV_SPEED;
	y = data->cub3d->player->pos_y - data->cub3d->player->dir_x * MOV_SPEED;
	update_pos(data, x, y);
}

static void	move_backward(t_data *data)
{
	double	x;
	double	y;

	x = data->cub3d->player->pos_x - data->cub3d->player->dir_x * MOV_SPEED;
	y = data->cub3d->player->pos_y - data->cub3d->player->dir_y * MOV_SPEED;
	update_pos(data, x, y);
}

static void	move_left(t_data *data)
{
	double	x;
	double	y;

	x = data->cub3d->player->pos_x - data->cub3d->player->dir_y * MOV_SPEED;
	y = data->cub3d->player->pos_y + data->cub3d->player->dir_x * MOV_SPEED;
	update_pos(data, x, y);
}

void	move_player(void *game_data)
{
	t_data	*data;

	data = (t_data *) game_data;
	cleaner_img(data);
	render_frame(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		free_and_exit(data, EXIT_SUCCESS);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forward(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_backward(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_Q))
		rotate_player(data, 1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_E))
		rotate_player(data, -1);
}

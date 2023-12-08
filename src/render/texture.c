/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:00:03 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 12:33:47 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_index(t_raycast *raycast)
{
	if (raycast->side == HIT_X)
	{
		if (raycast->dir_x < 0)
			return (WEST);
		else
			return (EAST);
	}
	else if (raycast->dir_y > 0)
		return (SOUTH);
	return (NORTH);
}

static void	print_map(t_data *data, t_raycast *raycast, int x)
{
	int				y;
	t_texture_info	*tex;
	uint8_t			*pixels;
	int32_t			color;
	t_orientation	texture_index;

	tex = data->tex_info;
	y = raycast->draw_start - 1;
	while (++y < raycast->draw_end)
	{
		tex->tex_y = (int)(tex->tex_pos) & (TEX_SIZE - 1);
		tex->tex_pos += tex->step;
		texture_index = get_texture_index(raycast);
		pixels = &data->textures[texture_index]
			->pixels[TEX_SIZE * tex->tex_y * 4 + tex->tex_x * 4];
		color = pixels[0] << 24 | pixels[1] << 16 | pixels[2] << 8 | pixels[3];
		mlx_put_pixel(data->game_img, x, y, color);
	}
}

void	cal_texture(t_data *data, t_raycast *raycast, t_player *player, int x)
{
	t_texture_info	*tex;

	tex = data->tex_info;
	if (raycast->side == HIT_X)
		raycast->wall_x = player->pos_y + raycast->perp_wall_dist
			* raycast->dir_y;
	else
		raycast->wall_x = player->pos_x + raycast->perp_wall_dist
			* raycast->dir_x;
	raycast->wall_x -= floor(raycast->wall_x);
	tex->tex_x = (int)(raycast->wall_x * ((double) TEX_SIZE));
	if ((raycast->side == HIT_X && raycast->dir_x > 0)
		|| (raycast->side == HIT_Y && raycast->dir_y < 0))
		tex->tex_x = TEX_SIZE - tex->tex_x - 1;
	tex->step = 1.0 * TEX_SIZE / raycast->line_height;
	tex->tex_pos = (raycast->draw_start - HEIGHT / 2 + raycast->line_height / 2)
		* tex->step;
	print_map(data, raycast, x);
}

void	paint_ceil_floor(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(data->bg_img, x, y, data->cub3d->ceil_color);
			else
				mlx_put_pixel(data->bg_img, x, y, data->cub3d->floor_color);
		}
	}
}

void	cleaner_img(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			mlx_put_pixel(data->game_img, x, y, 0);
	}
}

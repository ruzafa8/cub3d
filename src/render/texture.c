/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:00:03 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/01 20:00:04 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_ceil_floor(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 480)
	{
		x = -1;
		while (++x < 640)
		{
			if (y < 480 / 2)
				mlx_put_pixel(data->bg_img, x, y, data->cub3d->ceil_color);
			else
				mlx_put_pixel(data->bg_img, x, y, data->cub3d->floor_color);
		}
	}
}
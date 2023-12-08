/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:24:40 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 15:25:35 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_exit(t_data *data, int exit_code_num)
{
	if (data->textures[NORTH])
		mlx_delete_texture(data->textures[NORTH]);
	if (data->textures[SOUTH])
		mlx_delete_texture(data->textures[SOUTH]);
	if (data->textures[EAST])
		mlx_delete_texture(data->textures[EAST]);
	if (data->textures[WEST])
		mlx_delete_texture(data->textures[WEST]);
	if (data->raycast)
		free(data->raycast);
	if (data->tex_info)
		free(data->tex_info);
	parser_free_cub3d(&data->cub3d);
	if (data->game_img)
		mlx_delete_image(data->mlx, data->game_img);
	if (data->bg_img)
		mlx_delete_image(data->mlx, data->bg_img);
	if (data->mlx)
		mlx_close_window(data->mlx);
	if (data->mlx)
		mlx_terminate(data->mlx);
	exit(exit_code_num);
}

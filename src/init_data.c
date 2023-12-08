/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:01:13 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 18:09:48 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data)
{
	data->textures[NORTH] = mlx_load_png(data->cub3d->north_texture);
	if (!data->textures[NORTH])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[SOUTH] = mlx_load_png(data->cub3d->south_texture);
	if (!data->textures[SOUTH])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[EAST] = mlx_load_png(data->cub3d->east_texture);
	if (!data->textures[EAST])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[WEST] = mlx_load_png(data->cub3d->west_texture);
	if (!data->textures[WEST])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
}

void	init_sprite(t_data *data)
{
	data->game_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->game_img)
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	data->bg_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->bg_img)
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	mlx_image_to_window(data->mlx, data->bg_img, 0, 0);
	mlx_image_to_window(data->mlx, data->game_img, 0, 0);
}

void	init_structs(t_data *data)
{
	data->raycast = ft_calloc(1, sizeof(t_raycast));
	if (!(data->raycast))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->tex_info = ft_calloc(1, sizeof(t_texture_info));
	if (!(data->tex_info))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
}

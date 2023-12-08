/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:01:13 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 19:31:17 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*load_png(char *file)
{
	int		fd;
	size_t	filename_len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	filename_len = ft_strlen(file);
	if (filename_len > 4 && file[filename_len - 4] == '.'
		&& file[filename_len - 3] == 'p'
		&& file[filename_len - 2] == 'n'
		&& file[filename_len - 1] == 'g')
		return (mlx_load_png(file));
	return (0);
}

void	init_textures(t_data *data)
{
	data->textures[NORTH] = load_png(data->cub3d->north_texture);
	if (!data->textures[NORTH])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[SOUTH] = load_png(data->cub3d->south_texture);
	if (!data->textures[SOUTH])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[EAST] = load_png(data->cub3d->east_texture);
	if (!data->textures[EAST])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[WEST] = load_png(data->cub3d->west_texture);
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

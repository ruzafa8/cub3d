/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:01:13 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/05 17:34:05 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprite(t_data *data)
{
	data->game_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->game_img)
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		//TODO: liberar todo ->free_and_exit(data, EXIT_FAILURE);
	}
	data->bg_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->bg_img)
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		//TODO: liberar todo ->free_and_exit(data, EXIT_FAILURE);
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
		//free_and_exit(data, EXIT_SUCCESS);
	}
}
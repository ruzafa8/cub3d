/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:59:15 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/08 12:32:02 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.cub3d = parser_parse(argc, argv);
	if (data.cub3d == 0)
		return (1);
	init_mxl(&data);
	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!data.mlx)
	{
		//TODO: liberar todo ->free_and_exit(data, EXIT_FAILURE);
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
	}
	data.cub3d->player->dir_x = 1;
	data.cub3d->player->dir_y = 0;
	data.cub3d->player->plane_x = 0;
	data.cub3d->player->plane_y = 0.66;
	init_textures(&data);
	init_structs(&data);
	init_sprite(&data);
	paint_ceil_floor(&data);
	mlx_loop_hook(data.mlx, &move_player, &data);
	mlx_loop(data.mlx);
	parser_free_cub3d(&data.cub3d);
	return (0);
}

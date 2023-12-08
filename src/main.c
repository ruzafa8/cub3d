/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:59:15 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/08 19:18:37 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.cub3d = parser_parse(argc, argv);
	if (data.cub3d == 0)
		return (1);
	data.raycast = 0;
	data.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!data.mlx)
	{
		free_and_exit(&data, EXIT_FAILURE);
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
	}
	init_textures(&data);
	init_structs(&data);
	init_sprite(&data);
	paint_ceil_floor(&data);
	mlx_loop_hook(data.mlx, &move_player, &data);
	mlx_loop(data.mlx);
	free_and_exit(&data, EXIT_SUCCESS);
	return (0);
}

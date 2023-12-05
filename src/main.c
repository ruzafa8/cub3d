/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:59:15 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/05 17:38:09 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO), EXIT_FAILURE);

	data->cub3d = parser_parse(argc, argv);
	if (data->cub3d == 0)
		return (1);
	
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	// TODO: saber la orientación tanto del jugador como de la camara esta de base es N
	data->cub3d->player->dir_x = 0;
	data->cub3d->player->dir_y = -1;
	data->cub3d->player->plane_x = 0.66;
	data->cub3d->player->plane_y = 0;
	if(!(data->mlx))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		//TODO: liberar todo ->free_and_exit(data, EXIT_FAILURE);
	}
	init_sprite(data);
	paint_ceil_floor(data);
	mlx_loop(data->mlx);
	
	return (0);
}
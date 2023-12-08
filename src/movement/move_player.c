/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:16:25 by atrujill          #+#    #+#             */
/*   Updated: 2023/12/08 11:16:35 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	move_player(void *game_data)
{
	t_data	*data;

	data = (t_data *) game_data;
	cleaner_img(data);
	render_frame(data);
}

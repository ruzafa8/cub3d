/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:51:27 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/06 15:29:25 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum e_map
{
	FLOOR,
	WALL,
	VOID,
}	t_map;

typedef enum e_hit
{
	HIT_X,
	HIT_Y,
}	t_hit;

typedef enum e_direction
{
	NONE,
	FORWARD,
	BACKWARD,
}	t_direction;

#endif
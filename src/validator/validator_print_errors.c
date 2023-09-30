/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_print_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:46:14 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/09/30 16:54:37 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validator_print_errors(t_error error)
{
	if (error == FILE_EXTENSION_ERROR)
		ft_printf("Error\nInvalid file extension. Must be *.cub\n");
	else if (error == NUM_ARGS_ERROR)
	{
		ft_printf("Error\n");
		ft_printf("Usage: ./cub3D <map.cub>\n");
	}
}
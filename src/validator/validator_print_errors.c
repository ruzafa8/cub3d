/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_print_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:46:14 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 12:15:37 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * This functions aims to print a message if there is an error.
 * TODO: Should print on std error!
 */
void	validator_print_errors(t_error error)
{
	if (error == FILE_EXTENSION_ERROR)
		ft_printf("Error\nInvalid file extension. Must be *.cub\n");
	else if (error == NUM_ARGS_ERROR)
		ft_printf("Error\nUsage: ./cub3D <map.cub>\n");
	else if (error == FILE_OPEN_ERROR)
		ft_printf("Error\nCould not open file: %s\n", strerror(errno));
	else if (error == MEMORY_ERROR)
		ft_printf("Error\nCould not allocate memory\n");
	else if (error == NO_PLAYER)
		ft_printf(NO_PLAYER_ERR);
	else if (error == TOO_MUCH_PLAYERS)
		ft_printf(TOO_MUCH_PLAYERS_ERR);
	else if (error == UNKNOWN_CHARACTER_MAP)
		ft_printf(UNKNOWN_CHARACTER_MAP_ERR);
}

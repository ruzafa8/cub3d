/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_print_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:46:14 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/06 11:14:52 by aruzafa-         ###   ########.fr       */
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
	else if (error == RGB_TOO_LONG)
		ft_printf(RGB_TOO_LONG_ERR);
	else if (error == RGB_NAN)
		ft_printf(RGB_NAN_ERR);
	else if (error == RGB_NUM_PARAMS)
		ft_printf(RGB_NUM_PARAMS_ERR);
	else if (error == BORDER_ERROR)
		ft_printf(BORDER_ERROR_ERR);
	else if (error == NOT_A_PROPERTY)
		ft_printf(NOT_A_PROPERTY_ERR);
	else if (error == REPEATED_IDENTIFIER)
		ft_printf(REPEATED_IDENTIFIER_ERR);
	else if (error == IDENTIFIER_ERROR)
		ft_printf(IDENTIFIER_ERROR_ERR);
	else if (error == EXPECTED_MAP)
		ft_printf(EXPECTED_MAP_ERR);
}

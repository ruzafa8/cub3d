/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_print_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:46:14 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/08 18:29:40 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_some_errors(t_error error)
{
	if (error == TOO_MUCH_PLAYERS)
		return (ft_putendl_fd(TOO_MUCH_PLAYERS_ERR, STDERR_FILENO));
	if (error == UNKNOWN_CHARACTER_MAP)
		return (ft_putendl_fd(UNKNOWN_CHARACTER_MAP_ERR, STDERR_FILENO));
	if (error == RGB_TOO_LONG)
		return (ft_putendl_fd(RGB_TOO_LONG_ERR, STDERR_FILENO));
	if (error == RGB_NAN)
		return (ft_putendl_fd(RGB_NAN_ERR, STDERR_FILENO));
	if (error == RGB_NUM_PARAMS)
		return (ft_putendl_fd(RGB_NUM_PARAMS_ERR, STDERR_FILENO));
	if (error == BORDER_ERROR)
		return (ft_putendl_fd(BORDER_ERROR_ERR, STDERR_FILENO));
	if (error == NOT_A_PROPERTY)
		return (ft_putendl_fd(NOT_A_PROPERTY_ERR, STDERR_FILENO));
	if (error == REPEATED_IDENTIFIER)
		return (ft_putendl_fd(REPEATED_IDENTIFIER_ERR, STDERR_FILENO));
	if (error == IDENTIFIER_ERROR)
		return (ft_putendl_fd(IDENTIFIER_ERROR_ERR, STDERR_FILENO));
	if (error == EXPECTED_MAP)
		return (ft_putendl_fd(EXPECTED_MAP_ERR, STDERR_FILENO));
	if (error == MISSING_PROPERTIES)
		return (ft_putendl_fd(MISSING_PROPERTIES_ERR, STDERR_FILENO));
}

/**
 * This functions aims to print a message if there is an error.
 * TODO: Should print on std error!
 */
void	validator_print_errors(t_error error)
{
	if (error == FILE_EXTENSION_ERROR)
		return (ft_putendl_fd(FILE_EXTENSION_ERR, STDERR_FILENO));
	if (error == NUM_ARGS_ERROR)
		return (ft_putendl_fd(NUM_ARGS_ERROR_ERR, STDERR_FILENO));
	if (error == FILE_OPEN_ERROR)
		return (ft_putstr_fd(FILE_OPEN_ERR, STDERR_FILENO),
			ft_putendl_fd(strerror(errno), STDERR_FILENO));
	if (error == MEMORY_ERROR)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	if (error == NO_PLAYER)
		return (ft_putendl_fd(NO_PLAYER_ERR, STDERR_FILENO));
	print_some_errors(error);
}

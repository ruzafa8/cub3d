/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_print_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:46:14 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/11/15 18:31:48 by aruzafa-         ###   ########.fr       */
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
	else if (error == PARSER_ERROR)
		ft_printf("Error\nThere was an error parsing the file\n");
}

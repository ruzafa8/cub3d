/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:48:31 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 15:55:56 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*** PRINT MENSSAGES ***/
# define MALLOC_ERR "Error\nMemory was not allocated"
# define LOAD_ERR "Error\nUnable to load resource"
# define NO_PLAYER_ERR "Error\nMap has got no player"
# define TOO_MUCH_PLAYERS_ERR "Error\nMap has got too much players"
# define UNKNOWN_CHARACTER_MAP_ERR "Error\nMap has got an unknown character"
# define INVALID_RANGE_COLOR_ERR "Error\nRGB number out of range"

typedef enum e_error
{
	NO_ERROR,
	FILE_EXTENSION_ERROR,
	NUM_ARGS_ERROR,
	FILE_OPEN_ERROR,
	MEMORY_ERROR,
	IDENTIFIER_ERROR,
	NO_PLAYER,
	TOO_MUCH_PLAYERS,
	UNKNOWN_CHARACTER_MAP,
	INVALID_RANGE_COLOR,
}	t_error;

#endif
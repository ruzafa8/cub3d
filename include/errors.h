/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:48:31 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/06 10:37:42 by aruzafa-         ###   ########.fr       */
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
# define RGB_TOO_LONG_ERR "Error\nRGB value is so_long"
# define RGB_NAN_ERR "ERROR\nRGB value is not a number"
# define RGB_NUM_PARAMS_ERR "ERROR\nRGB number of params error"
# define BORDER_ERROR_ERR "ERROR\nMap not surrounded by walls"
# define NOT_A_PROPERTY_ERR "ERROR\nTrying to read an invalid property"
# define TOO_MUCH_PROPERTIES_ERR "ERROR\nToo much properties"
# define REPEATED_IDENTIFIER_ERR "ERROR\nProperties duplicated"
# define IDENTIFIER_ERROR_ERR "ERROR\nFile contens unknown properties"
# define EXPECTED_MAP_ERR "ERROR\nExpected a map at file"

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
	RGB_TOO_LONG,
	RGB_NAN,
	RGB_NUM_PARAMS,
	BORDER_ERROR,
	NOT_A_PROPERTY,
	TOO_MUCH_PROPERTIES,
	REPEATED_IDENTIFIER,
	EXPECTED_MAP,
}	t_error;

#endif
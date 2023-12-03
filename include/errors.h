/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:48:31 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/03 16:32:01 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*** PRINT MENSSAGES ***/
# define MALLOC_ERR "Error\nMemory was not allocated"
# define LOAD_ERR "Error\nUnable to load resource"
# define NO_PLAYER_ERR "Error\nMap has got no player"
# define TOO_MUCH_PLAYERS_ERR "Error\nMap has got too much players"

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
}	t_error;

#endif
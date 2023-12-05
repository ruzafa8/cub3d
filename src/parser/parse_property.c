/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_property.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:25:16 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/05 16:55:33 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * This function tries put at texture the value passed as params.
 * If already exists, returns an error.
 * 
 * @param texture: Pointer to the position to store the value.
 * @param value: The value to store.
 * 
 * @returns NO_ERROR if that position points to an empty space
 * or REPEATED_IDENTIFIER error if the value is already set.
 */
static t_error	set_once_or_error(char **texture, char *value)
{
	if (*texture)
		return (REPEATED_IDENTIFIER);
	*texture = ft_strdup(value);
	return (NO_ERROR);
}

/**
 * This function tries to put the RGB color passed as param to the
 * other position specified.
 * If the position has got a color already it returns error and
 * it is not set.
 * 
 * @param rgb_str: The rgb color as string, formatted as "R,G,B"
 * where R, G, and B are number between 0 and 255.
 * @param number: Pointer to the position to store the value.
 * 
 * @returns NO_ERROR if that position points to an empty space
 * or REPEATED_IDENTIFIER error if the value is already set.
 */
static t_error set_number_or_error(char *rgb_str, int *number)
{
	if (*number)
		return (REPEATED_IDENTIFIER);
	return (validate_colors(rgb_str, number));
}

static t_error	add_to_cub3d(char *id, char *value, t_cub3d *cub3d)
{
	if (ft_strncmp(id, "NO", 2) == 0)
		return (set_once_or_error(&cub3d->north_texture, value));
	else if (ft_strncmp(id, "SO", 2) == 0)
		return (set_once_or_error(&cub3d->south_texture, value));
	else if (ft_strncmp(id, "EA", 2) == 0)
		return (set_once_or_error(&cub3d->east_texture, value));
	else if (ft_strncmp(id, "WE", 2) == 0)
		return (set_once_or_error(&cub3d->west_texture, value));
	else if (ft_strncmp(id, "F", 1) == 0)
		return (set_number_or_error(value, &cub3d->floor_color));
	else if (ft_strncmp(id, "C", 1) == 0)
		return (set_number_or_error(value, &cub3d->ceil_color));
	return (IDENTIFIER_ERROR);
}

/**
 * This function tries to extract the identifier and the value of a 
 * line. If there is any problem, an error is returned and params are
 * freed.
 * 
 * @param line: A string with the following format: 
 * ID (SPACES) VALUE, where ID and VALUE are alpha chars and (SPACES)
 * are one or more spaces (tabs, spaces, break line, ...)
 * @param identifier: A pointer to the position to store the ID found at
 * line param.
 * @param value: A pointer to the position to store the VALUE found at
 * line param.
 * 
 * @returns An error found while trying to parse the line, or NO_ERROR
 * if there was no problem parsing the line param.
 */
t_error	parseable_property(char *line, char **identifier, char **value)
{
	size_t	index;

	index = spaces_find_next(line);
	*identifier = ft_substr(line, 0, index);
	if (!*identifier)
		return (MEMORY_ERROR);
	if (!**identifier)
		return (free(*identifier), NOT_A_PROPERTY);
	index = spaces_skip_from_index(line, index);
	*value = ft_substr(line, index, -1);
	if (!*value)
		return (free(*identifier), MEMORY_ERROR);
	return (NO_ERROR);
}

/**
 * Esta función analiza líneas del siguiente formato:
 * IDENTIFICADOR (ESPACIOS) VALOR.
 * 
 * Inserta en la estructura el valor correspondiente tras analizar la línea
 * si es correcta.
 */
t_error	parse_property(char *line, t_cub3d *cub3d)
{
	char	*identifier;
	char	*value;
	t_error	error;

	if (ft_strlen(line) == 0)
		return (NO_ERROR);
	if (!line)
		return (MEMORY_ERROR);
	error = parseable_property(line, &identifier, &value);
	if (error != NO_ERROR)
		return (error);
	error = add_to_cub3d(identifier, value, cub3d);
	free(identifier);
	free(value);
	return (error);
}

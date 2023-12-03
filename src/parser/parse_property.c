/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_property.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:25:16 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/02 17:15:37 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static t_error	add_to_cub3d(char *id, char *value, t_cub3d *cub3d)
{
	t_error	error;

	error = NO_ERROR;
	if (ft_strncmp(id, "NO", 2) == 0)
		cub3d->north_texture = ft_strdup(value);
	else if (ft_strncmp(id, "SO", 2) == 0)
		cub3d->south_texture = ft_strdup(value);
	else if (ft_strncmp(id, "EA", 2) == 0)
		cub3d->east_texture = ft_strdup(value);
	else if (ft_strncmp(id, "WE", 2) == 0)
		cub3d->west_texture = ft_strdup(value);
	else if (ft_strncmp(id, "F", 1) == 0)
		cub3d->floor_color = validate_colors(value, &error);
	else if (ft_strncmp(id, "C", 1) == 0)
		cub3d->ceil_color = validate_colors(value, &error);
	else
		error = IDENTIFIER_ERROR;
	return (error);
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
	size_t	index;
	t_error	error;

	if (ft_strlen(line) == 0)
		return (NO_ERROR);
	if (!line)
		return (MEMORY_ERROR);
	index = spaces_find_next(line);
	identifier = ft_substr(line, 0, index);
	if (!identifier)
		return (MEMORY_ERROR);
	index = spaces_skip_from_index(line, index);
	value = ft_substr(line, index, -1);
	if (!value)
		return (free(identifier), MEMORY_ERROR);
	error = add_to_cub3d(identifier, value, cub3d);
	free(identifier);
	free(value);
	return (error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:33:48 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/11/15 20:28:22 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * TODO: Custom error for parser?
 */
static t_error	validate_first_line(char *line, t_cub3d *cub3d)
{
	if (ft_strlen(line) > 3 && line[0] == 'N' && line[1] == 'O'
		&& line[2] == ' ')
	{
		cub3d->north_texture = ft_substr(line, 3, -1);
		if (!cub3d->north_texture)
			return (MEMORY_ERROR);
		return (NO_ERROR);
	}
	return (PARSER_ERROR);
}

static t_error	validate_second_line(char *line, t_cub3d *cub3d)
{
	if (ft_strlen(line) > 3 && line[0] == 'S' && line[1] == 'O'
		&& line[2] == ' ')
	{
		cub3d->south_texture = ft_substr(line, 3, -1);
		if (!cub3d->south_texture)
			return (MEMORY_ERROR);
		return (NO_ERROR);
	}
	return (PARSER_ERROR);
}

static t_error	validate_third_line(char *line, t_cub3d *cub3d)
{
	if (ft_strlen(line) > 3 && line[0] == 'W' && line[1] == 'E'
		&& line[2] == ' ')
	{
		cub3d->west_texture = ft_substr(line, 3, -1);
		if (!cub3d->west_texture)
			return (MEMORY_ERROR);
		return (NO_ERROR);
	}
	return (PARSER_ERROR);
}

static t_error	validate_forth_line(char *line, t_cub3d *cub3d)
{
	if (ft_strlen(line) > 3 && line[0] == 'E' && line[1] == 'A'
		&& line[2] == ' ')
	{
		cub3d->east_texture = ft_substr(line, 3, -1);
		if (!cub3d->east_texture)
			return (MEMORY_ERROR);
		return (NO_ERROR);
	}
	return (PARSER_ERROR);
}

t_error	validate_textures_lines(int fd, t_cub3d *cub3d)
{
	char	*line;
	t_error	error;

	line = ft_get_next_line(fd);
	error = validate_first_line(line, cub3d);
	free(line);
	if (error != NO_ERROR)
		return (error);
	line = ft_get_next_line(fd);
	error = validate_second_line(line, cub3d);
	free(line);
	if (error != NO_ERROR)
		return (error);
	line = ft_get_next_line(fd);
	error = validate_third_line(line, cub3d);
	free(line);
	if (error != NO_ERROR)
		return (error);
	line = ft_get_next_line(fd);
	error = validate_forth_line(line, cub3d);
	free(line);
	if (error != NO_ERROR)
		return (error);
	return (NO_ERROR);
}

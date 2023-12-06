/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_map_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:16:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/06 17:04:03 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Given a list of strings, returns the lenght of the biggest string.
 * 
 * @param map: the list of strings.
 * 
 * @returns the max length.
 */
static size_t	get_max_len(t_list *map)
{
	size_t	max;
	size_t	len;

	max = 0;
	len = 0;
	while (map)
	{
		len = ft_strlen((char *) map->content);
		if (len > max)
			max = len;
		map = map->next;
	}
	return (max);
}

/**
 * This function aims to normalize the len of the map lines.
 * Search for the longest one and pads the other ones with spaces
 * to the longest one.
 * 
 * @param map: A list with the lines of the map. The function updates
 * the line padding.
 */
static void	padd_map(t_list	*map)
{
	size_t	max_len;
	char	*padded;

	max_len = get_max_len(map);
	while (map)
	{
		padded = str_padd_spaces((char *) map->content, max_len);
		free(map->content);
		map->content = padded;
		map = map->next;
	}
}

/**
 *  This function reads lines until it is not empty.
 *  As get_next_line returns the line with the '\n', we just
 *  need to verify if the first char is '\n'.
 * 
 * @param fd: File descriptor to read.
 * 
 * @returns the next line which is not empty
 */
static char	*skip_empty_lines(int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	return (line);
}

/**
 * Parses the map from the file.
 * 
 * @param fd: The file descriptor where the map is readen.
 * @param map: Pointer to store the map readen.
 * 
 * @returns an error code. NO_ERROR if everything is OK.
 */
t_error	parse_read_map_fd(int fd, t_list **map)
{
	char	*line;
	char	*aux;

	line = skip_empty_lines(fd);
	aux = str_remove_last_breakdown(line);
	if (!validate_line_is_map(aux))
		return (free(aux), free(line), EXPECTED_MAP);
	free(aux);
	*map = 0;
	while (line)
	{
		ft_lstadd_back(map, ft_lstnew(str_remove_last_breakdown(line)));
		free(line);
		line = ft_get_next_line(fd);
	}
	padd_map(*map);
	return (NO_ERROR);
}

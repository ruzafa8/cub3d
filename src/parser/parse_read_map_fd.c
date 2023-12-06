/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_map_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:16:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/06 11:02:30 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static t_error	skip_empty_lines(int fd, char **line)
{
	char	*aux;

	*line = ft_get_next_line(fd);
	while (**line == '\n')
	{
		free(*line);
		*line = ft_get_next_line(fd);
	}
	aux = str_remove_last(*line);
	if (validate_line_is_map(aux))
		return (free(aux), NO_ERROR);
	free(aux);
	free(*line);
	return (EXPECTED_MAP);
}

t_error	parse_read_map_fd(int fd, t_list **map)
{
	char	*line;
	t_error	error;

	error = skip_empty_lines(fd, &line);
	if (error)
		return (error);
	*map = 0;
	while (line)
	{
		ft_lstadd_back(map, ft_lstnew(str_remove_last(line)));
		free(line);
		line = ft_get_next_line(fd);
	}
	padd_map(*map);
	return (NO_ERROR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read_map_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:16:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/03 16:17:26 by aruzafa-         ###   ########.fr       */
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

t_list	*parse_read_map_fd(int fd)
{
	t_list	*map;
	char	*line;

	line = ft_get_next_line(fd);
	map = 0;
	while (line)
	{
		ft_strlen(line);
		ft_lstadd_back(&map, ft_lstnew(str_remove_last(line)));
		free(line);
		line = ft_get_next_line(fd);
	}
	padd_map(map);
	return (map);
}

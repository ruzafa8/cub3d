/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:26:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/08 13:26:37 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	char_to_map(char c)
{
	if (c == ' ')
		return (VOID);
	if (c == '0')
		return (FLOOR);
	if (c == '1')
		return (WALL);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (FLOOR);
	return (VOID);
}

static t_map	*char_array_to_map_array(char *c, size_t len)
{
	t_map	*res;
	size_t	i;

	i = 0;
	res = (t_map *) ft_calloc(len, sizeof(t_map));
	while (i < len)
	{
		res[i] = char_to_map(c[i]);
		i++;
	}
	return (res);
}

static t_error	convert_map(t_cub3d *cub3d, t_list *map)
{
	size_t	i;

	cub3d->height = ft_lstsize(map);
	cub3d->width = ft_strlen((char *) map->content);
	cub3d->map = (t_map **) ft_calloc(cub3d->height, sizeof(t_map *));
	if (!cub3d->map)
		return (MEMORY_ERROR);
	i = 0;
	while (map)
	{
		cub3d->map[i] = char_array_to_map_array(map->content, cub3d->width);
		map = map->next;
		i++;
	}
	return (NO_ERROR);
}

static void	free_map(t_list **map)
{
	if (!map)
		return ;
	ft_lstclear(map, free);
}

/**
 * TODO: Valgrind.
 */
t_error	parser_map(int fd, t_cub3d *cub3d)
{
	t_error	error;
	t_list	*map;

	error = parse_read_map_fd(fd, &map);
	if (error != NO_ERROR)
		return (free_map(&map), error);
	if (!validate_is_map(map))
		return (free_map(&map), UNKNOWN_CHARACTER_MAP);
	error = parse_player(map, cub3d);
	if (error != NO_ERROR)
		return (free_map(&map), error);
	error = convert_map(cub3d, map);
	free_map(&map);
	if (error != NO_ERROR)
		return (error);
	if (!validate_border(cub3d->map, cub3d->height, cub3d->width))
		return (BORDER_ERROR);
	return (error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:26:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 20:49:28 by aruzafa-         ###   ########.fr       */
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

/**
 * TODO: Valgrind.
 */
t_error	parser_map(int fd, t_cub3d *cub3d)
{
	t_error	error;
	t_list	*map;
	t_list	*aux;
	size_t	i;

	map = parse_read_map_fd(fd);
	if (!validate_is_map(map))
		return (UNKNOWN_CHARACTER_MAP);
	error = validate_player(map, cub3d);
	cub3d->height = ft_lstsize(map);
	if (error != NO_ERROR)
		return (error);
	cub3d->map = (t_map **) ft_calloc(cub3d->height, sizeof(t_map *));
	if (!cub3d->map)
		return (MEMORY_ERROR);
	i = 0;
	aux = map;
	cub3d->width = ft_strlen((char *) map->content);
	while (aux)
	{
		cub3d->map[i] = char_array_to_map_array(aux->content, cub3d->width);
		aux = aux->next;
		i++;
	}
	if (!validate_border(cub3d->map, cub3d->height, cub3d->width))
		return (BORDER_ERROR);
	return (error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:26:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 12:09:47 by aruzafa-         ###   ########.fr       */
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
	return (VOID);
}

static t_map	*char_array_to_map_array(char *c)
{
	t_map	*res;
	size_t	len;

	len = ft_strlen(c);
	res = (t_map *) ft_calloc(len, sizeof(t_map));
	while (len--)
		res[len] = char_to_map(c[len]);
	return (res);
}

/**
 * TODO: Validation.
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
	if (error != NO_ERROR)
		return (error);
	cub3d->map = (t_map **) ft_calloc(ft_lstsize(map), sizeof(t_map *));
	if (!cub3d->map)
		return (MEMORY_ERROR);
	i = 0;
	aux = map;
	while (aux)
	{
		cub3d->map[i] = char_array_to_map_array(aux->content);
		aux = aux->next;
		i++;
	}
	return (error);
}

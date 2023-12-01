/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:26:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/11/29 21:28:43 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	char_to_map(char c)
{
	if (c == ' ')
		return VOID;
	if (c == '0')
		return FLOOR;
	if (c == '1')
		return WALL;
	return VOID;
}

static t_map	*char_array_to_map_array(char *c, size_t len)
{
	t_map	*res;

	res = (t_map *) ft_calloc(len, sizeof(t_map));
	while (len--)
		res[len] = char_to_map(c[len]);
	return (res);
}

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

static t_list	*read_map_from_fd(int fd)
{
	t_list	*l;
	char	*line;

	line = ft_get_next_line(fd);
	l = 0;
	while (line)
	{
		ft_lstadd_back(&l, ft_lstnew(str_remove_last(line)));
		free(line);
		line = ft_get_next_line(fd);
	}
	return (l);
}

t_map	**parser_map(int fd)
{
	t_list	*map;
	t_list	*aux;
	size_t	max_len;
	char	*str;
	t_map	**final_map_res;

	map = read_map_from_fd(fd);
	aux = map;
	max_len = get_max_len(map);
	while (aux)
	{
		str = str_padd_spaces((char *) aux->content, max_len);
		aux = aux->next;
	}
	// TODO: Validate chars
	aux = map;
	size_t lst_size = ft_lstsize(aux);
	final_map_res = (t_map **) ft_calloc(lst_size, sizeof(t_map *));
	size_t	i;
	i = 0;
	while (i < lst_size)
	{
		final_map_res[i] = char_array_to_map_array(aux->content, max_len);
		aux = aux->next;
		i++;
	}
	// TODO: Valgrind...
	return (final_map_res);
}

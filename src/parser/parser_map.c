/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:26:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/03 16:19:51 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_error	validate_one_player(t_list	*list)
{
	int		num_players;
	char	*line;

	num_players = 0;
	while (list && num_players < 2)
	{
		line = (char *) list->content;
		while (*line && num_players < 2)
		{
			if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
				num_players++;
			line++;
		}
		list = list->next;
	}
	if (num_players < 1)
		return (NO_PLAYER);
	if (num_players > 1)
		return (TOO_MUCH_PLAYERS);
	return (NO_ERROR);
}

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
t_map	**parser_map(int fd, t_error *error)
{
	t_list	*map;
	t_list	*aux;
	t_map	**final_map_res;
	size_t	i;

	map = parse_read_map_fd(fd);
	*error = validate_one_player(map);
	if (*error != NO_ERROR)
		return (0);
	final_map_res = (t_map **) ft_calloc(ft_lstsize(map), sizeof(t_map *));
	i = 0;
	aux = map;
	while (aux && error == NO_ERROR)
	{
		*error = validate_is_map(aux->content);
		aux = aux->next;
		final_map_res[i] = char_array_to_map_array(aux->content);
		i++;
	}
	return (final_map_res);
}

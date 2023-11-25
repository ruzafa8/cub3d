/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:26:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/11/25 19:25:38 by aruzafa-         ###   ########.fr       */
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

void	parser_map(int fd)
{
	t_list	*map;
	t_list	*aux;
	size_t	max_len;
	char	*str;

	map = read_map_from_fd(fd);
	aux = map;
	max_len = get_max_len(map);
	while (aux)
	{
		str = str_padd_spaces((char *) aux->content, max_len);
		// ft_printf("'%s'\n", (char *)aux->content);
		ft_printf("'%s'", aux);
		aux = aux->next;
	}
	// TODO: Validate chars

}

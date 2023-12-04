/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_is_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:51:05 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 12:01:58 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_line_is_map(char *line)
{
	size_t	i;

	if (!line || !line[0])
		return (0);
	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" 01NSEW", line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_is_map(t_list *map)
{
	while (map)
	{
		if (!validate_line_is_map((char *) map->content))
			return (0);
		map = map->next;
	}
	return (1);
}

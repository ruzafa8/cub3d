/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:07:12 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 12:00:11 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_player	*init_player(int x, int y)
{
	t_player	*player;

	player = (t_player *) ft_calloc(1, sizeof(t_player));
	player->x = x;
	player->y = y;
	return (player);
}

static t_player	*find_player(t_list *list)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (list)
	{
		j = 0;
		line = (char *) list->content;
		while (*line)
		{
			if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
				return (init_player(i, j));
			line++;
			j++;
		}
		i++;
		list = list->next;
	}
	return ((t_player *) 0);
}

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

t_error	validate_player(t_list *list, t_cub3d *cub3d)
{
	t_error	error;

	error = validate_one_player(list);
	if (error != NO_ERROR)
		return (error);
	cub3d->player = find_player(list);
	return (NO_ERROR);
}

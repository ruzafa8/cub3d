/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:07:12 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/09 18:33:51 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Set the information related to the facing point at player node.
 * 
 * @param player: The player structure. The information related to the facing
 * of the player is initialized here.
 * @param facing: A char with the player facing cardinal point
 * ('N', 'S', 'E', 'W')
 */
static void	set_facing(t_player *player, char facing)
{
	if (facing == 'N')
	{
		player->dir_x = -1;
		player->plane_y = 0.66;
	}
	else if (facing == 'S')
	{
		player->dir_x = 1;
		player->plane_y = -0.66;
	}
	else if (facing == 'E')
	{
		player->dir_y = 1;
		player->plane_x = 0.66;
	}
	else if (facing == 'W')
	{
		player->dir_y = -1;
		player->plane_x = -0.66;
	}
}

/**
 * Init the player node. It receives the necessary information
 * to init the structure.
 * 
 * @param x: The position at x axis of the player in the map.
 * @param y: The position at y axis of the player in the map.
 * @param facing: A char that indicates what cardinal point is
 * the player facing ('N' for North, 'S' for South,
 * 'E' for East and 'W' for West)
 * 
 * @returns the node of the player with the information initialized.
 */
static t_player	*init_player(int x, int y, char facing)
{
	t_player	*player;

	player = (t_player *) ft_calloc(1, sizeof(t_player));
	if (!player)
		return ((t_player *) 0);
	player->pos_x = (double) x + 0.5;
	player->pos_y = (double) y + 0.5;
	set_facing(player, facing);
	return (player);
}

/**
 * Searches the player in the structure and return a node with all
 * the information about the player.
 * 
 * @param list: The map.
 * 
 * @returns the player.
 */
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
				return (init_player(i, j, *line));
			line++;
			j++;
		}
		i++;
		list = list->next;
	}
	return ((t_player *) 0);
}

/**
 * This function validates if there is one player in the given map.
 * 
 * @param list: The map where perform the validation.
 * 
 * @return an error code if there is no player or more than 1.
 * Else return NO_ERROR.
 */
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

/**
 * This function search for the player in a map of chars.
 * If the player is found, the function adds it to cub3d structure.
 * If any error is detected, it is not inicialized and an error is returned.
 * 
 * @param list: The map to search the player for.
 * @param cub3d: The structure to store the player if everything is OK.
 * 
 * @returns an error code or NO_ERROR if no error found.
 */
t_error	parse_player(t_list *list, t_cub3d *cub3d)
{
	t_error	error;

	error = validate_one_player(list);
	if (error != NO_ERROR)
		return (error);
	cub3d->player = find_player(list);
	if (!cub3d->player)
		return (MEMORY_ERROR);
	return (NO_ERROR);
}

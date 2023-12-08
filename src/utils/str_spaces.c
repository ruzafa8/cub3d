/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:52:57 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/08 20:26:18 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define FILE_SPACES "\t\n\v\f\r "

int	spaces_isspace(char c)
{
	return (ft_strchr(FILE_SPACES, (int) c) != (char *) 0);
}

size_t	spaces_find_next(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (spaces_isspace(str[i]))
			return (i);
		i++;
	}
	return (0);
}

size_t	spaces_skip_from_index(char *str, size_t index)
{
	size_t	i;

	i = index;
	while (str[i])
	{
		if (!spaces_isspace(str[i]))
			return (i);
		i++;
	}
	return (0);
}

char	*spaces_trim(char *str)
{
	char	*trimmed;

	trimmed = ft_strtrim(str, FILE_SPACES);
	free(str);
	return (trimmed);
}

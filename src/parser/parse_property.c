/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_property.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:25:16 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/01 20:48:24 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

static size_t	find_next_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (isspace(str[i]))
			return (i);
		i++;
	}
	return (0);
}

static size_t	skip_spaces_from(char *str, size_t index)
{
	size_t	i;

	i = index;
	while (str[i])
	{
		if (!isspace(str[i]))
			return (i);
		i++;
	}
	return (0);	
}

void	parse_property(char *line)
{
	char	*trimmed;
	char	*identifier;
	char	*value;
	size_t	index;

	trimmed = ft_strtrim(line, "\t\n\v\f\r ");
	index = find_next_space(line);
	identifier = ft_substr(line, 0, index);
	index = skip_spaces_from(line, index); // skip spaces
	value = ft_substr(line, index, -1);
	ft_printf("%s->%s", identifier, value);
}

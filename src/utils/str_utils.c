/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:59:44 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/06 12:32:49 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*str_remove_last(char *str)
{
	char	*res;
	size_t	len;
	size_t	index;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] != '\n')
		return (ft_strdup(str));
	res = (char *) ft_calloc(len, sizeof(char));
	index = 0;
	while (index < len - 1)
	{
		res[index] = str[index];
		index++;
	}
	return (res);
}

/**
 * This function creates a new string with an specific len adding
 * spaces to end of it.
 * @param str: The string to replicate.
 * @param len: The new size of the string.
 * 
 * @returns a new string with the same content as str, with size len.
 * If the len is lower than the string, then the result is truncated.
 * If the len is bigger than the string, it is filled with spaces ' '.
 */
char	*str_padd_spaces(char *str, size_t len)
{
	char	*res;
	size_t	index;
	size_t	str_len;

	str_len = ft_strlen(str);
	res = (char *) ft_calloc(len + 1, sizeof(char));
	ft_memset((void *) res, (int) ' ', len);
	index = 0;
	while (index < str_len && index < len)
	{
		res[index] = str[index];
		index++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:37:03 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/06 10:15:38 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	count_num_strings(char *numbers)
{
	size_t	num_commas;
	size_t	i;

	i = 0;
	num_commas = 0;
	while (numbers[i])
	{
		if (numbers[i] == ',')
			num_commas++;
		i++;
	}
	return (num_commas);
}

static int	rgb_to_int_color(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xff);
}

/**
 * This function validates that the string received is number between 0 and 255.
 * 
 * We validate for each char if it a number.
 * Then, we validate the len (must not be bigger than 3). That way we avoid
 * overflows.
 * 
 * Finally we convert it to int and validate range between 0 and 255
 */
static t_error	validate_number(char *number, int *number_to_int)
{
	int	i;

	i = 0;
	if (!number)
		return (RGB_NUM_PARAMS);
	while (number[i])
	{
		if (!ft_isdigit((int) number[i]))
			return (RGB_NAN);
		i++;
	}
	if (ft_strlen(number) > 3)
		return (RGB_TOO_LONG);
	*number_to_int = ft_atoi(number);
	if (*number_to_int < 0 || *number_to_int > 255)
		return (RGB_TOO_LONG);
	return (NO_ERROR);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != 0)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/**
 * TODO: Revisar bien los Leaks... 
 * numbers_str es un array de arrays, no lo estamos borrando bien
 */
t_error	validate_colors(char *rgb, int *number)
{
	char	**numbers_str;
	int		*numbers;
	t_error	error;

	if (count_num_strings(rgb) != 2)
		return (RGB_NUM_PARAMS);
	numbers_str = ft_split(rgb, ',');
	numbers = (int *) ft_calloc(3, sizeof(int));
	if (!numbers_str || !numbers)
		return (free(numbers), free_split(numbers_str), MEMORY_ERROR);
	error = validate_number(numbers_str[0], numbers);
	if (error != NO_ERROR)
		return (free(numbers), free_split(numbers_str), error);
	error = validate_number(numbers_str[1], numbers + 1);
	if (error != NO_ERROR)
		return (free(numbers), free_split(numbers_str), error);
	error = validate_number(numbers_str[2], numbers + 2);
	if (error != NO_ERROR)
		return (free(numbers), free_split(numbers_str), error);
	*number = rgb_to_int_color(numbers[0], numbers[1], numbers[2]);
	return (free(numbers), free_split(numbers_str), NO_ERROR);
}

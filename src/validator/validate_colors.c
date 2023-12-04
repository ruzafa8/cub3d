/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:37:03 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/04 16:23:20 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * This function validates that the string received is number between 0 and 255.
 * 
 * Firstable, we validate len (must not be bigger than 3). That way we avoid
 * overflows.
 * 
 * Then we validate each char of the string is a number.
 */
static int	validate_number(char *number)
{
	int	i;

	if (ft_strlen(number) > 3)
		return (0);
	i = 0;
	while (number[i])
	{
		if (!ft_isdigit((int) number[i]))
			return (0);
		i++;
	}
	return (1);
}

static size_t	count_num_strings(char **strs)
{
	size_t	num;

	num = 0;
	while (*strs)
	{
		num++;
		strs++;
	}
	return (num);
}

static int	valid_range(int number)
{
	return (0 <= number && number <= 255);
}

static int	rgb_to_int_color(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xff);
}

int	validate_colors(char *rgb, t_error *error)
{
	char	**numbers;
	int		r_number;
	int		g_number;
	int		b_number;

	numbers = ft_split(rgb, ',');
	if (!numbers)
	{
		*error = MEMORY_ERROR;
		return (0);
	}
	if (count_num_strings(numbers) != 3)
	{
		*error = INVALID_RGB_COLOR;
		return (0);
	}
	if (!validate_number(numbers[0]) || !validate_number(numbers[1])
		|| !validate_number(numbers[2]))
	{
		*error = INVALID_RGB_COLOR;
		return (0);
	}
	r_number = ft_atoi(numbers[0]);
	g_number = ft_atoi(numbers[1]);
	b_number = ft_atoi(numbers[2]);
	if (!valid_range(r_number) || !valid_range(g_number)
		|| !valid_range(b_number))
	{
		*error = INVALID_RGB_COLOR;
		return (0);
	}
	*error = NO_ERROR;
	return (rgb_to_int_color(r_number, g_number, b_number));
}

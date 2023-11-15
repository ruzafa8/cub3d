/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_validate_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:12:04 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/11/15 17:33:35 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * The extension of the file must be ".cub"
 */
static int	validate_file_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (
		len >= 5
		&& filename[len - 1] == 'b'
		&& filename[len - 2] == 'u'
		&& filename[len - 3] == 'c'
		&& filename[len - 4] == '.'
	);
}

/**
 * The program must receive only one argument: The name of the file to process.
 */
static int	validate_num_of_args(int argc)
{
	return (argc == 2);
}

t_error	validator_validate_args(int argc, char **argv)
{
	if (!validate_num_of_args(argc))
		return (NUM_ARGS_ERROR);
	if (!validate_file_extension(argv[1]))
		return (FILE_EXTENSION_ERROR);
	return (NO_ERROR);
}

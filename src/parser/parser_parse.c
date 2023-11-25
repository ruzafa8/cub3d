/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:14:54 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/11/25 18:43:34 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_cub3d	*parse_fd(int fd, t_error *error)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *) ft_calloc(1, sizeof(t_cub3d));
	*error = validate_textures_lines(fd, cub3d);
	// TODO: Validate empty line...
	ft_get_next_line(fd);
	parser_map(fd);
	if (*error == NO_ERROR)
		return (cub3d);
	parser_free_cub3d(&cub3d);
	return (0);
}

static t_error	read_file(char *filename, t_cub3d **cub3d)
{
	int		fd;
	t_error	error;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (FILE_OPEN_ERROR);
	*cub3d = parse_fd(fd, &error);
	close(fd);
	return (error);
}

t_cub3d	*parser_parse(int argc, char **argv)
{
	t_error	error;
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *) NULL;
	error = validator_validate_args(argc, argv);
	if (error == NO_ERROR)
		error = read_file(argv[1], &cub3d);
	return (validator_print_errors(error), cub3d);
}

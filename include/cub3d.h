/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:48:25 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/02 14:30:50 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <ft.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "errors.h"
# include "map.h"
# include "MLX42/MLX42.h"

# define BUFFER_SIZE 1024

typedef struct s_cub3d
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceil_color;
	t_map	**map;
}	t_cub3d;

typedef struct s_data
{
	t_cub3d	*cub3d;
	mlx_t *mlx;
	mlx_image_t		*game_img;
	mlx_image_t		*bg_img;
	
} t_data;

/*** VALIDATION FUNCTIONS ***/
t_error	validator_validate_args(int argc, char **argv);
void	validator_print_errors(t_error error);
t_error	validate_textures_lines(int fd, t_cub3d *cub3d);
t_error	validate_colors(int fd, t_cub3d *cub3d);


/*** PARSING FUNCTIONS ***/
t_cub3d	*parser_parse(int argc, char **argv);
void	parser_free_cub3d(t_cub3d **cub3d);
t_map	**parser_map(int fd);
void	parse_property(char *line);


/*** STRING UTILS ***/
char	*str_padd_spaces(char *str, size_t len);
char	*str_remove_last(char *str);

/*** RENDER ***/
void	init_sprite(t_data *data);
void	paint_ceil_floor(t_data *data);

#endif
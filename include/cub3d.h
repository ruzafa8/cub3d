/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:48:25 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/12/08 20:26:35 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <ft.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "errors.h"
# include "map.h"
# include "MLX42/MLX42.h"

# define BUFFER_SIZE 	1024
# define WIDTH			640
# define HEIGHT			480
# define TEX_SIZE		64
# define INFINITE		1e30
# define MOV_SPEED 		0.035
# define COLLIDER_DIST	1.25
# define ROT_SPEED 		0.045

typedef struct s_texture_info
{
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}	t_texture_info;

typedef struct s_raycast
{
	char			player_dir;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	t_direction		step_x;
	t_direction		step_y;
	t_hit			side;
	int				draw_start;
	int				draw_end;
	int				line_height;
	double			perp_wall_dist;
	double			wall_x;

}	t_raycast;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_cub3d
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color;
	int			ceil_color;
	t_map		**map;
	size_t		width;
	size_t		height;
	t_player	*player;
}	t_cub3d;

typedef struct s_data
{
	t_cub3d			*cub3d;
	mlx_t			*mlx;
	mlx_image_t		*game_img;
	mlx_image_t		*bg_img;
	t_raycast		*raycast;
	t_texture_info	*tex_info;
	mlx_texture_t	*textures[4];
}	t_data;

/*** VALIDATION FUNCTIONS ***/
t_error	validator_validate_args(int argc, char **argv);
void	validator_print_errors(t_error error);
t_error	validate_colors(char *rgb, int *number);
int		validate_is_map(t_list *map);
int		validate_line_is_map(char *line);
int		validate_border(t_map **map, size_t max_x, size_t max_y);

/*** PARSING FUNCTIONS ***/
t_cub3d	*parser_parse(int argc, char **argv);
void	parser_free_cub3d(t_cub3d **cub3d);
t_error	parser_map(int fd, t_cub3d *cub3d);
t_error	parse_property(char *line, t_cub3d *cub3d);
t_error	parseable_property(char *line, char **identifier, char **value);
t_error	parse_read_map_fd(int fd, t_list **map);
t_error	parse_player(t_list *map, t_cub3d *cub3d);

/*** STRING UTILS ***/
char	*str_padd_spaces(char *str, size_t len);
char	*str_remove_last_breakdown(char *str);
size_t	spaces_find_next(char *str);
size_t	spaces_skip_from_index(char *str, size_t index);
char	*spaces_trim(char *str);
int		spaces_isspace(char c);

/*** RENDER ***/
void	init_sprite(t_data *data);
void	init_structs(t_data *data);
void	init_textures(t_data *data);
void	paint_ceil_floor(t_data *data);
void	cleaner_img(t_data *data);
void	render_frame(t_data *data);
void	cal_texture(t_data *data, t_raycast *raycast, t_player *player, int x);

/*** MOVEMENT ***/
void	move_player(void *game_data);
void	update_pos(t_data *data, double x, double y);
void	rotate_player(t_data *data, int dir);

/*** FREE ***/
void	free_and_exit(t_data *data, int exit_code_num);

#endif
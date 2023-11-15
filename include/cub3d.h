#ifndef CUB3D_H
# define CUB3D_H

# include <ft.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "errors.h"

# define BUFFER_SIZE 1024

typedef struct s_cub3d
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
}	t_cub3d;

/*** VALIDATION FUNCTIONS ***/
t_error	validator_validate_args(int argc, char **argv);
void	validator_print_errors(t_error error);
t_error	validate_textures_lines(int fd, t_cub3d *cub3d);


/*** PARSING FUNCTIONS ***/
t_cub3d	*parser_parse(int argc, char **argv);
void	parser_free_cub3d(t_cub3d **cub3d);

#endif
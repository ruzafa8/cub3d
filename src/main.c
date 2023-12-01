#include "cub3d.h"

int main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = parser_parse(argc, argv);
	if (cub3d == 0)
		return (1);
	ft_printf("NO: %s\nSO: %s\nWE: %s\nEA: %s",
		cub3d->north_texture, cub3d->south_texture, cub3d->west_texture, cub3d->east_texture);
	return (0);
}

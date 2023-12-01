#include "cub3d.h"

int main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = parser_parse(argc, argv);
	if (cub3d == 0)
		return (1);
	
	return (0);
}

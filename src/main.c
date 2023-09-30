#include "cub3d.h"

int main(int argc, char **argv)
{
	t_error	error;

	error = validator_validate(argc, argv);
	if (error != NO_ERROR)
		return (validator_print_errors(error), 1);
	ft_printf("Valid arguments.\n");
	return (0);
}

#ifndef CUB3D_H
# define CUB3D_H

# include <ft.h>
# include <errors.h>

/*** VALIDATION FUNCTIONS ***/
t_error	validator_validate(int argc, char **argv);
void	validator_print_errors(t_error error);

#endif
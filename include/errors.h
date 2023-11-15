#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_error
{
	NO_ERROR,
	FILE_EXTENSION_ERROR,
	NUM_ARGS_ERROR,
	FILE_OPEN_ERROR,
	MEMORY_ERROR,
	PARSER_ERROR,
}	t_error;

#endif
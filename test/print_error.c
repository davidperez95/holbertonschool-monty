#include "monty.h"

int print_error(int flag, size_t line_number)
{
	char *errors[] = {"usage: push integer", "nil"};

	fprintf(stderr, "L%ld: %s\n", line_number, errors[flag]);
	return (EXIT_FAILURE);
}

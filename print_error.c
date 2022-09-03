#include "monty.h"

int print_error(int flag, unsigned int line_number)
{
	char *errors[] = {"usage: push integer", "nil"};

	fprintf(stderr, "L%d: %s\n", line_number, errors[flag]);
	return (EXIT_FAILURE);
}

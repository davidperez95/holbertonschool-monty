#include "monty.h"

/**
 * print_error - prints errors
 * @flag: integer to find error
 * @line_number: line number of the error
 * Return: EXIT_FAILURE
 */
int print_error(int flag, unsigned int line_number)
{
	char *errors[] = {"usage: push integer", "nil"};

	fprintf(stderr, "L%d: %s\n", line_number, errors[flag]);
	return (EXIT_FAILURE);
}

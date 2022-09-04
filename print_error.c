#include "monty.h"

/**
 * print_error - prints errors
 * @flag: integer to find error
 * @line_number: line number of the error
 * Return: EXIT_FAILURE
 */
int print_error(int flag, unsigned int line_number)
{
	char *errors[] = {"usage: push integer", "can\'t pint, stack empty", "can\'t pop an empty stack",
		"can\'t swap, stack too short", "can\'t add, stack too short"};

	fprintf(stderr, "L%d: %s\n", line_number, errors[flag]);
	return (EXIT_FAILURE);
}

/**
 * open_error - prints error if cant open file
 * @filename: name of the file
 * Return: EXIT_FAILURE
 */
int open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

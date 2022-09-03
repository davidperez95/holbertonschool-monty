#include "monty.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @av: arguments vector
 * Return: EXIT_SUCCESS
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL;
	size_t len = 0;
	unsigned int line_number = 0, status = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
		return (open_error(av[1]));

	while ((getline(&line, &len, fd)) != EOF)
	{
		line_number++;
		if (empty_line(line, DELIM_LINE))
			continue;
		token = tokenizer(line, DELIM_LINE);
		if (!token)
		{
			free(line);
			free(token);
			continue;
		}

		if (strcmp(token[0], "push") == 0)
			status = push_op(&stack, token, line_number);
		else
			status = select_op(&stack, token, line_number);

		free_token(token);
	}
	fclose(fd);
	free_stack(&stack);
	free(line);

	return (status);
}

/**
 * empty_line - checks if line is empty
 * @line: pointer to line
 * @delims: delimiters to check
 * Return: 0 on success 1 on failure
 */
int empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
			break;
		}
		if (delims[j] == '\0')
		return (0);
	}

	return (1);
}

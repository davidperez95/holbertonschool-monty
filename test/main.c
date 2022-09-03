#include "monty.h"

int main(int ac, char **av)
{
	FILE *fd = NULL;
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL;
	size_t len = 0;
	unsigned int line_number = 0, status = 0, i = 0;

	if (ac != 2)
	{
		fprintf(stderr, "not usage\n");
		exit(EXIT_FAILURE);
	}

	
	fd = fopen(av[1], "r");
	if (fd == NULL)
		exit(EXIT_FAILURE);

	while ((getline(&line, &len, fd)) != EOF) 
	{
		line_number++;
		token = tokenizer(line, DELIM_LINE);
		if (!token)
		{
			free(line);
			free(token);
			continue;
		}
		for (i = 0; token[i] != NULL; i++)
		{
			printf("%s\n", token[i]);
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

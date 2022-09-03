#include "monty.h"

int main(int ac, char **av)
{
	FILE *fd = NULL;
	char *line = NULL, **token = NULL;
	size_t len = 0, line_number = 1;
	int i = 0;

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
		free_token(token);
	}

	fclose(fd);
	free(line);

	return (EXIT_SUCCESS);
}

#include "monty.h"

/**
 *
 *
 *
 */
int main(int ac, char **av)
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], O_RDONLY);
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fd)) != EOF)
	{
		printf("Retrieved line of length %zu:\n", read);
		printf("%s", line);
	}

	fclose(fd);
	if (line)
		free(line);

	exit(EXIT_SUCCESS);
}

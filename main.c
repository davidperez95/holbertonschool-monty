#include "monty.h"

/**
 * main - entry point
 * @argv: arguments vector
 * @argc: arguments count
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	int fd = 0, n_read = 0, n_write = 0;
	char buffer[BUFSIZ];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	n_read = read(fd, buffer, BUFSIZ);
	if (n_read == -1)
		exit(EXIT_FAILURE);

	n_write = write(STDOUT_FILENO, buffer, BUFSIZ);
	if (n_write == -1)
		exit(EXIT_FAILURE);

	close(fd);

	return (0);
}

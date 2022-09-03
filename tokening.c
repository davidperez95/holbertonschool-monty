#include "monty.h"

/**
 * _calloc - asing memory of nmemb elements
 * @nmemb: number of elements
 * @size: size of the memory
 * Return: void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *array  = NULL;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
	return (NULL);

	array = malloc(nmemb * size);

	if (!array)
	{
		free(array);
		return (NULL);
	}

	for (i = 0; i < (nmemb * size); i++)
		array[i] = 0;

	return (array);
}

/**
 * tokenizer - tokenizes a string
 * @line: string to token
 * @delim: delimites to token
 * Return: double pointer
 */
char **tokenizer(char *line, char *delim)
{
	char *token = NULL, *copy_line = NULL;
	char **argv = NULL;
	int count_token = 0, i = 0;

	copy_line = malloc((sizeof(char) * strlen(line)) + 1);
	if (copy_line == NULL)
		return (NULL);

	strcpy(copy_line, line);
	token = strtok(line, delim);
	while (token != NULL)
		token = strtok(NULL, delim), count_token++;
	count_token++;

	argv = _calloc(count_token + 8, sizeof(char *));
	if (!argv)
	{
		free(copy_line);
		return (NULL);
	}
	token = strtok(copy_line, delim);
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!argv[i])
		{
			free(copy_line);
			return (NULL);
		}
		strcpy(argv[i], token), i++, token = strtok(NULL, delim);
	}
	if (!argv[0])
	{
		free(copy_line);
		free(argv);
		return (NULL);
	}
	free(copy_line), argv[i] = NULL;
	return (argv);
}

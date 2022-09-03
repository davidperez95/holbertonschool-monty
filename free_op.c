#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: pointer to the stack
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * free_token - frees the token
 * @token: array of strings
 * Return: void
 */
void free_token(char **token)
{
	int i;

	for (i = 0; token[i] != NULL; i++)
	{
		free(token[i]);
		token[i] = NULL;
	}

	free(token);
}

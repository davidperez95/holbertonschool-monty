#include "monty.h"

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

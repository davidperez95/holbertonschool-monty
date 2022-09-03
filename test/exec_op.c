#include "monty.h"

int push_op(stack_t **stack, char **token, size_t line_number)
{
	stack_t *new = NULL;

	if (token[1] == NULL)
		return (print_error(0, line_number));
		
	if (token[1][0] < '0' || token[1][0] > '9')
	{
		free_stack(stack);
		return (print_error(0, line_number));
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		return (EXIT_FAILURE);
	}
	new->n = atoi(token[1]);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;

	printf("number in stack: %d\n", new->n);

	return (EXIT_SUCCESS);
}

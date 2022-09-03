#include "monty.h"

int select_op(stack_t **stack, char **token, unsigned int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"pall", pall_op},
		{NULL, NULL}
	};

	for (i = 0; i < 2; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, token[0]);
	return (EXIT_FAILURE);	
}

int push_op(stack_t **stack, char **token, unsigned int line_number)
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

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

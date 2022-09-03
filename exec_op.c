#include "monty.h"

/**
 * select_op - selects monty operation
 * @stack: pointer to stack
 * @token: array of strings
 * @line_number: line number
 * Return: EXIT_SUCCESS
 */
int select_op(stack_t **stack, char **token, unsigned int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"pall", pall_op},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
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

/**
 * push_op - adds an integer at the top of the stack
 * @stack: pointer to stack
 * @token: array of strings
 * @line_number: line number
 * Return: EXIT_SUCCESS
 */
int push_op(stack_t **stack, char **token, unsigned int line_number)
{
	int i = 0;
	stack_t *new = NULL;

	if (token[1] == NULL)
		return (print_error(0, line_number));

	for (i = 0; token[1][i] != '\0'; i++)
	{
		if (token[1][i] == '-' && i == 0)
			continue;
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_stack(stack);
			return (print_error(0, line_number));
		}
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

	return (EXIT_SUCCESS);
}

/**
 * pall_op - prints the stack
 * @stack: pointer to the stack
 * @line_number: number of the line
 * Return: void
 */
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

#include "monty.h"

/**
 * swap_op - swaps the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: number of the line
 * Return: void
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	int tmp;

	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_error(3, line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}

/**
 * add_op - adds the two top elements of the stack
 * @stack; pointer to the stack
 * @line_number: number of the line
 * Return: void
 
void add_op(stack_t **stack, unsigned int line_number)
{
	
}
*/

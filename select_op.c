#include "monty.h"

/**
 *
 *
 *
 */
void (*get_op)(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_s op[] = {
		{"push", push_op},
		{"pall", pall_op},
		{NULL, NULL}
	};

	for (; op[i].opcode != NULL; i++)
	{
		
	}
}

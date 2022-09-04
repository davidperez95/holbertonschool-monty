#ifndef _MONTY_
#define _MONTY_

/* impoting */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

/* macros */
#define DELIM_LINE " \n\t\a\r"

/* typedef and structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* prototypes */
char **tokenizer(char *line, char *delim);
void *_calloc(unsigned int nmemb, unsigned int size);
int select_op(stack_t **stack, char **token, unsigned int line_number);
int empty_line(char *line, char *delims);

/* monty operations */
int push_op(stack_t **stack, char **token, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);

/* handle errors */
int print_error(int flag, unsigned int line_number);
int open_error(char *filename);

/* frees */
void free_token(char **token);
void free_stack(stack_t **stack);

#endif /* _MONTY_ */

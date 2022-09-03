#ifndef _MONTY_
#define _MONTY_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define DELIM_LINE " \n\t\a"

char **tokenizer(char *line, char *delim);
void *_calloc(unsigned int nmemb, unsigned int size);
int select_op(stack_t **stack, char **token, unsigned int line_number);

/* monty operations */
int push_op(stack_t **stack, char **token, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);

/* handle errors */
int print_error(int flag, unsigned int line_number);

/* frees */
void free_token(char **token);
void free_stack(stack_t **stack);

#endif

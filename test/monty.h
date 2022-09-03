#ifndef _MONTY_
#define _MONTY_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DELIM_LINE " \n\t\a"

char **tokenizer(char *line, char *delim);
void *_calloc(unsigned int nmemb, unsigned int size);
void free_token(char **token);

#endif

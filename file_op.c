#include "monty.h"
#include <stdlib.h>


void _file_op(FILE *filename)
{
	char *lineptr = NULL;/* line Buffer */
	size_t n = 0; /*line buffer size */
	int file_status, line_num = 0;
	char **tokens = NULL;
	ssize_t line_size, nread;
	FILE *stream;
	file_status = access(filename, R_OK);
	if (file_status == -1)
		err(2, filename);
	/* open file */
	stream = fopen(filename, "r");
	if (stream == NULL)
		err(2, filename);

	nread = getline(&lineptr, &n, stream);
	while (nread != -1)
	{
		line_num++;
		tokens = tokenizer(lineptr)
		/*function to work on tokens goes here*/
		/* goto nextline*/
		nread = getline(&lineptr, &n, stream);
	}
	free(lineptr);
	fclose(stream);
}

int tokenizer(char *lineptr, line_number )
{
	char *opcode;
	char *value:
	int data;
	opcode = strtok(lineptr," ");
	if (opcode == NULL)
		return (1);
	value = strtok(NULL, " ")
	if (isdigit(value))
	{
		data = atoi(value);
	}
	else:
	{
		perror("L%i: usage: push integer", line_number);
		exit(EXITFAILURE);
	}
	 (*get_opcode(char *format))(stack_t **stack, line_number)/* get opcode function goes here */
	return (0);
}


int _len(char **token)
{
	int i = 0;

	while (token[i])
		i++;
	return (i);
}

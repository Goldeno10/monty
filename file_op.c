#include "monty.h"
#include <stdlib.h>


void _file_op(FILE *filename)
{
	char *lineptr = NULL;/* line Buffer */
	size_t n = 0; /*line buffer size */
	int line_num = 0;
	ssize_t line_size, nread;
	FILE *stream;
	/* open file */
	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		perror("Error: Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}

	nread = getline(&lineptr, &n, stream);
	while (nread != -1)
	{
		line_num++;
		//function to take lineptr goes here
		tokenizer(lineptr, linenumber)	/* goto next line */
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
	void (*get_opcode(char *format))(stack_t **stack, line_number)/* get opcode function goes here */
	return (0);
}



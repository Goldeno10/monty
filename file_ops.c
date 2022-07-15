#include "monty.h"
stack_t *head = NULL;
char *arg = "12";
void _file_op(char *filename)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *lineptr = NULL;/* line Buffer */
	size_t n = 0; /*line buffer size */
	int file_status, line_num = 0;
	char  **tokens = NULL;/*[1024];*/
	FILE *stream;

	/*check file status */
	file_status = access(filename, R_OK);
	if (file_status == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/* open file */
	stream = fopen(filename, "r");
	if (stream == 0)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&lineptr, &n, stream) != -1)
	{
		tokens = malloc(sizeof (char *) * strlen(lineptr));
		line_num++;
		_tokenize(lineptr, tokens);
		f = get_opcode(tokens[0]);
		if (!f)
		{
			dprintf(2, "L%i: unknown instruction %s\n", line_num, tokens[0]);
			exit(EXIT_FAILURE);
		}
/*		arg = tokens[1];*/
		f(&head, line_num);
	}
	free(lineptr);
	fclose(stream);
}
/**
* tokenizer - creates tokens from given input
* @line: to be tokenized
*
* Return: array of strings
*/
char **_tokenize(char *line, char **arr)
{
	int i = 0;
	char *p = strtok(line, " \t");

	while (p != NULL)
	{
		arr[i] = p;
		p = strtok(NULL, " \t");
		i++;
	}
	return (arr);
}

/**
*
*
*
*
*/
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_num)
{
	int i = 0;
	instruction_t ops[] ={
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

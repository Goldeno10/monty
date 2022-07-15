#include "monty.h"

stack_t *head = NULL;
char *arg = NULL;
void _file_op(char *filename)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *lineptr = NULL;/* line Buffer */
	size_t n = 0; /*line buffer size */
	int file_status, line_num = 0;
	char  *tokens[4096];/*[1024];*/
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
		line_num++;
		_tokenizer(lineptr, tokens);
		f = get_opcode(tokens[0]);

		if (!f)
		{
			dprintf(2, "L%i: unknown instruction %s\n", line_num, tokens[0]);
			exit(EXIT_FAILURE);
		}
		if (tokens[1])
		{
			arg = tokens[1];
		}
		else{
			arg = NULL;
		}
		f(&head, line_num);
	}
	free(lineptr);
	fclose(stream);
}

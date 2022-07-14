#include "monty.h"
stack_t *head = NULL;
char *arg;
void _file_op(char *filename)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *lineptr = NULL;/* line Buffer */
	size_t n = 1024; /*line buffer size */
	int file_status, line_num = 0;
	char *tokens[3024];
	ssize_t nread;
	FILE *stream;

	/*check file status */
	file_status = access(filename, R_OK);
	if (file_status == -1)
		err(2, filename);
	/* open file */
	stream = fopen(filename, "r");
	if (stream == NULL)
		err(2, filename);

	/*read fist line */
	nread = getline(&lineptr, &n, stream);
	while (nread != -1)
	{
		line_num++;
		_tokenize(lineptr, tokens);
		f = get_opcode(tokens[0]);
		if (!f)
			err(3, line_num, tokens[0]);
		arg = tokens[1];
		f(&head, line_num);
		/* goto nextline*/
		nread = getline(&lineptr, &n, stream);
	}
	free(lineptr);
	fclose(stream);
}



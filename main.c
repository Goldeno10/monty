#include "monty.h"


/**
*
*
*
*
*
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_file_op(argv[1]);
	free_stack(head);
	return (0);
}


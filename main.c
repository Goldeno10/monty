#include "monty.h"


int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		_error(1);
	file_op(argv[1]);
}

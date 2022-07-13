#include "monty.h"

void (*get_opcode(char *format))(stack_t **stack, unsigned int line_number)
{
	instructions_t ops[] ={
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

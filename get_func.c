#include "monty.h"

void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instructions_t ops[] ={
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	while (ops[i])
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f)
		i++;
	}
}

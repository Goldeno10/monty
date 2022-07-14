#include "monty.h"

void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t ops[] ={
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};
	while (ops[i].opcode)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			break;
		i++;
	}
	return (ops[i].f);
}

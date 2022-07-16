#include "monty.h"

/**
*tok_arr - creates array of tokens from given input
*@lineptr: The line to be tokenized
*@tokens: Empty array to be fild with tokens
*Return: Nothing
*/

void tok_arr(char *lineptr, char *tokens[])
{
	ssize_t i;
	char *token;

	token = strtok(lineptr, " \t\n");
	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;
	if (strncmp(tokens[0], "#", 1) == 0)
		tokens[0] = "nop";
}

/**
*get_opcode - Choses the right function for an opcode
*@code: Opcode string
*Return: A pointer to an opcode functin
*/
void (*get_opcode(char *code))(stack_t **stack, unsigned int line_num)
{
	int i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{NULL, NULL}
	};
	i = 0;
	while (ops[i].opcode)
	{
		if (strcmp(code, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
/**
*check_arg - Checks if argument is and integer
*@line_num: command line number
*Return: Nothing
*/
void check_arg(unsigned int line_num)
{
	if (!arg)
	{
		dprintf(2, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (!isdigit(arg))
	{
		dprintf(2, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
}

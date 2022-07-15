#include "monty.h"

/**
* tokenizer - creates tokens from given input
* @line: to be tokenized
*
* Return: array of strings
*/
char **_tokenizer(char *lineptr, char **tokens)
{
	char delim[] = " \t";
	char *token;
	int i = 0;

	token = strtok(lineptr, delim);
	while (token != NULL && i < 2)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	if (tokens[0] == NULL)
		return (NULL);
	if (strncmp(tokens[0], "#", 1) == 0)
		tokens[0] = "nop";
	return (tokens);
}

/**
*get_opcode - Choses the right function for an opcode
*@code: Opcode string
*@stack: Doubly linked list head
*@line_num: opcode line number in file
*Return: A pointer to an opcode functin
*/
void (*get_opcode(char *code))(stack_t **stack, unsigned int line_num)
{
	int i;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{NULL, NULL}
	};
	while (ops[i].opcode)
	{
		if (strcmp(code, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

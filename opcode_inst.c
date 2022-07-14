#include "monty.h"

void check_arg(unsigned int line_num)
{
	int j;

	if (!arg)
		err(4, line_num);
	for (j = 0; arg[j] != '\0'; j++)
	{
		if (!isdigit(arg[j]) && arg[j] != '-')
			err(4, line_num);
	}
}


/**
 * _push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void _push(stack_t **stack, unsigned int line_num)
{
	int n;

	check_arg(line_num);

	n = atoi(arg);

	add_dnodeint_end(stack, n);
}
/**
 * _pall - prints all values on the stack
 *
 * @stack: head of the linked list
 * @line_num: line numbers
 * Return: no return
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;
	(void)line_num;;

	curr = *stack;
	print_dlistint(curr);
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	(void)line_num;

	if (*stack == NULL)
		more_err(6, line_num);

	printf("%d\n", (*stack)->n);
}

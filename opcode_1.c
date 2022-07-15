#include "monty.h"

/**
  * add - Adds the top two elements of the stack
  * @stack: Head of doubly linked list
  * @line_num: line number
  */
void _add(stack_t **stack, unsigned int line_num)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		dprintf(2, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_num);
}

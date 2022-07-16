#include "monty.h"

/**
  * add - Adds the top two elements of the stack
  * @stack: Head pointer to a  doubly linked list
  * @line_num: line number
  */
void add(stack_t **stack, unsigned int line_num)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		dprintf(2, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_num);
}
/**
 * sub - Subtracts the top two elements of the stack
 * @stack: Head pointer to a doubly linked list
 * @line_num: line number
 */
void sub(stack_t **stack, unsigned int line_num)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		dprintf(2, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_num);
}
/**
 * div -  Devides the top  element by the second too element of the stack
 * @stack: Head pointer to a doubly linked list
 * @line_num: line number
 */
void _div(stack_t **stack, unsigned int line_num)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		dprintf(2, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_num);
}

/**
 * mod - Computes the modulus ot the top two elements of the stack
 * @stack: Head pointer to a doubly linked list
 * @line_num: line number
 */
void mod(stack_t **stack, unsigned int line_num)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		dprintf(2, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		dprintf(2, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_num);
}

/**
 * mul - Multiply the top two elements of the stack
 * @stack: Head pointer to a doubly linked list
 * @line_num: line number
 */
void mul(stack_t **stack, unsigned int line_num)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		dprintf(2, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_num);
}


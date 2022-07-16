#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_num)
{
	int n;
	stack_t *new;

	check_arg(line_num);
	n = atoi(arg);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		if (*stack != NULL)
			free_stack(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *stack;
	new->prev = NULL;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
/**
 * pall - prints all values on the stack
 * @stack: head of the linked list
 * @line_num: line numbers
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *c = *stack;
	(void)line_num;

	if (!stack)
	{
		dprintf(2, "L%d: can't pall, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	for (; c; c = c->next)
		dprintf(2, "%d\n", c->n);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: head of the linked list
 * @line_num: line number
 * Return: no return
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;
	(void) line_num;

	if (!h)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes first node of a linked list
 * @stack: first node of linked list
 * @line_num: line number
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *del = *stack;

	if (!del)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack = del->next;
	free(del);
}

/**
  * swap - swaps the top two elements of the stack
  * @stack: head node of linked list
  * @line_num: line number
  */
void swap(stack_t **stack, unsigned int line_num)
{
	int x = (*stack)->n;

	if (!(stack) || !(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		dprintf(2, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}

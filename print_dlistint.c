#include "monty.h"
/**
*print_dlistint - prints all the elements of a dlistint_t list.
*@h: Pointer to head node
*Return: Number ofnodes
*/

size_t print_dlistint(stack_t *h)
{
	stack_t *current;
	size_t n;

	current = h;
	n = 0;
	/* navigate to end of stack */
	if (current)
        {
                while (current)
                        current = current->next;
        }
	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->prev;
		n++;
	}
	return (n);
}

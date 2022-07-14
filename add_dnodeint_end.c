#include "monty.h"
/**
*add_dnodeint_end - adds a new node at the end of a dlistint_t list.
*@head: Pointer to head of list
*@n: List node data
*Return: the address of the new element, or NULL if it failed
*/

stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *current, *new;

	current = *head;
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;
	/* navigating to the end node if node is not null*/
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	new->prev = current;
	if (current)
	{
		current->next = new;
	}
	else
	{
		*head = new;/* if head node point to null l, then point it to new node*/
	}
	return (new);
}

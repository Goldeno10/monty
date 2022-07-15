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
		dprintf(2, "Error: malloc failed");
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

/**
*free_dlistint - frees a dlistint_t list.
*@head: Head pointer to list to be freed
*Return: Nothing
*/
void free_stack(stack_t *head)
{
	stack_t *f_h;

	if (!head)
		return;
	if (head)
	{
		while (head->prev)
			head = head->prev;
	}
	f_h = head;
	while (head)
	{
		f_h = head;
		head = head->next;
		free(f_h);
	}
}

/**
*print_dlistint - prints all the elements of a dlistint_t
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

/**
*add_dnodeint - adds a new node at the beginning of a dlist
*@head:Pointer to a pointer to a start of a list
*@n: Node integer data
*Return: The address of the new element, or NULL if it fail
*/

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new, *c;

	c = *head;
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	if (c != NULL)
	{
		while (c->prev != NULL)
			c = c->prev;
	}
	new->next = c;
	if (c)
		c->prev = new;
	*head = new;
	return (new);
}

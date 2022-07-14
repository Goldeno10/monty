#include "monty.h"

stack_t *head = NULL;

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		err(1);
	_file_op(argv[1]);
	free_stack(head);
	return (0);
}
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

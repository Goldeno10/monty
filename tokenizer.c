#include "monty.h"
#include <string.h>
/**
* tokenizer - creates tokens from given input
* @line: to be tokenized
*
* Return: array of strings
*/
char **_tokenize(char *line, char **arr)
{
	int i = 0;
	char *p = strtok(line, " ");

	while (p != NULL)
	{
		arr[i++] = p;
		p = strtok(NULL, " ");
	}
	return (arr);
}
/**
* _strdup - dupicates string
* @s: to be duplicated
*
* Return: pointer to duplicate string
*/
char *_strdup(char *s)
{
        char *ptr;
        int i, len;

        if (s == NULL)
                return (NULL);

        len = strlen(s);

        ptr = malloc(sizeof(char) * (len + 1));
        if (!ptr)
                return (NULL);
        for (i = 0; *s != '\0'; s++, i++)
                ptr[i] = s[0];

        ptr[i++] = '\0';
        return (ptr);
}

#include "monty.h"
#include <string.h>
/**
* tokenizer - creates tokens from given input
* @line: to be tokenized
*
* Return: array of strings
*/
char **tokenizer(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	buf = _strdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = NULL;
	free(buf);
	return (tokens);
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

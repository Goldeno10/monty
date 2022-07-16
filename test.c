#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void tok_arr(char *lnptr, char *tokens[]);
#define FILENAME "00.m"

int main(void)
{
  /* Open the file for reading */
  char *line_buf = NULL;
  size_t line_buf_size = 0;
  int line_count = 0, n;
  ssize_t line_size;
  FILE *fp = fopen(FILENAME, "r");
  if (!fp)
  {
    fprintf(stderr, "Error opening file '%s'\n", FILENAME);
    return EXIT_FAILURE;
  }

  /* Get the first line of the file. */
  line_size = getline(&line_buf, &line_buf_size, fp);

  /* Loop through until we are done with the file. */
  while (line_size >= 0)
  {
    /* Increment our line count */
    line_count++;

    n = strlen(line_buf);
    char *tokens[n + 1];
    tok_arr(line_buf, tokens);

    for (int i =  0; tokens[i] != NULL; i++)
	printf("%s \n", tokens[i]);

    /* Show the line details */
    printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s", line_count,
        line_size, line_buf_size, line_buf);

    /* Get the next line */
    line_size = getline(&line_buf, &line_buf_size, fp);
  }

  /* Free the allocated line buffer */
  free(line_buf);
  line_buf = NULL;

  /* Close the file now that we are done with it */
  fclose(fp);

  return EXIT_SUCCESS;
}

void tok_arr(char *lnptr, char *tokens[])
{
	ssize_t i;
	char *token;

	token = strtok(lnptr, " \t\n");
	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
/*	return tokens*/
}

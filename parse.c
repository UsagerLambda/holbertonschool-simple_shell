#include "header.h"
/**
 * parse - divide the string in tokens
 * @line_ptr: string to divide
 * @tokens: numbers of arguments
 * @nb_tokens: -
 */
void parse(char *line_ptr, char *tokens[], int *nb_tokens)
{
char *token = NULL;
int i = 0;
*nb_tokens = 0;

token = strtok(line_ptr, " ");
while (token)
{
	tokens[i] = token;
	i++;
	token = strtok(NULL, " ");
}
*nb_tokens = i;
tokens[i] = NULL;
}

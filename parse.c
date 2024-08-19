#include "header.h"
/**
 * parse - Tokenizes a command line into individual arguments.
 * @line_ptr: The command line string to tokenize.
 * @tokens: An array to store the tokens.
 * @nb_tokens: A pointer to the number of tokens parsed.
 *
 * This fonction splits the command line into tokens separated by spaces.
 * Each token is stored in the tokens array, and the total number of tokens
 * is stored in nb_tokens.
 */
void parse(char *line_ptr, char *tokens[], int *nb_tokens)
{
char *token = NULL;
int i = 0;
*nb_tokens = 0;

token = strtok(line_ptr, " \n\t");
while (token)
{
	tokens[i] = token;
	i++;
	token = strtok(NULL, " \n\t");
}
*nb_tokens = i;
tokens[i] = NULL;
}

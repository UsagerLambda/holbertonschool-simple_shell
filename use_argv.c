#include "header.h"
/**
 * use_argv - execute the arguments
 * @argc: numbers of arguments
 * @argv: content of arguments
 * @envp: environnement
 * Return: 0
 */
int use_argv(int argc, char *argv[], char *envp[])
{
	int i = 0;
	char **tokens = malloc(argc * sizeof(char *));
	int nb_tokens = argc - 1;

	for (i = 0; i < nb_tokens; i++)
	{
	tokens[i] = argv[i + 1];
	}
	tokens[nb_tokens] = NULL;

	which_path(tokens, nb_tokens, envp);
	return (0);
}

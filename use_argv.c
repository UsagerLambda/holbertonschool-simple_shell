#include "header.h"
/**
 * use_argv - Handles command-line arguments in non-interactive mode.
 * @argc: Number of command-line arguments.
 * @argv: Array of pointers to the arguments.
 * @envp: Array of environment variables.
 *
 * This function processes commands passed as arguments to the shell.
 * It tokenizes the arguments and searches for the command in the PATH.
 * If found, the command is executed.
 *
 * Return: Always 0.
 */
int use_argv(int argc, char *argv[], char *envp[])
{
	int i = 0;
	int nb_tokens;
	char **tokens = malloc((argc - 1) * sizeof(char *));

	if (tokens == NULL)
		errors(EXIT_FAILURE, "malloc failed", argv, NULL);

	nb_tokens = argc - 1;

	for (i = 0; i < nb_tokens; i++)
		tokens[i] = argv[i + 1];

	tokens[nb_tokens] = NULL;

	which_path(tokens, nb_tokens, envp, NULL);
	free(tokens);
	return (0);
}

#include "header.h"
/**
 * it_exist - Checks if a command exists in a specified directory.
 * @dir: The directory to search in.
 * @tokens: The array of command and arguments.
 * @nb_tokens: The number of tokens in the command.
 * @envp: The environment variables.
 *
 * This function constructs the full path to the command by concatenating
 * the directory path and the command name. It then checks if the command
 * is executable using the access() system call. If the command exists
 * and is executable, the function calls execute() to run the command
 * and returns 1. If the command does not exist or is not executable,
 * it returns 0.
 *
 * Return: Returns 1 if the command exists and is executable, 0 otherwise.
 */
int it_exist(char *dir, char *tokens[], int nb_tokens, char *envp[])
{
char path[PATH_MAX];
strcpy(path, dir);
strcat(path, "/");

if (nb_tokens > 0 && tokens[0] != NULL)
	strcat(path, tokens[0]);

if (access(path, X_OK) == 0)
{
	execute(path, tokens, envp);
	return (1);
}
return (0);
}

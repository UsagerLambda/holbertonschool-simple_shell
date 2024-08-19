#include "header.h"
/**
 * which_path - Find the full path of a command and executes it.
 * @tokens: The array of command and arguments.
 * @nb_tokens: The number of tokens in the command.
 * @envp: The environment variables.
 *
 * This function searches the directories listed in the PATH environment
 * variable for an executable file that matches the command in tokens[0].
 * If found, it executes the command; otherwise, it prints an error message.
 */
void which_path(char **tokens, int nb_tokens, char *envp[])
{
int found = 0;
char *path, *dir;
char *path_env = getenv("PATH");

if (path_env == NULL)
errors(EXIT_FAILURE, "(!) errors with getenv");

path = strdup(path_env);

if (access(tokens[0], X_OK) == 0)
	execute(tokens[0], tokens, envp);

if (path == NULL)
errors(EXIT_FAILURE, "(!) errors with strdup");

dir = strtok(path, ":");
while (dir != NULL && !found)
{
	if (it_exist(dir, tokens, nb_tokens, envp))
	found = 1;
	dir = strtok(NULL, ":");
}
free(path);
}

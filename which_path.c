#include "header.h"
/**
 * which_path - find the path of tokens
 * @tokens: tokens to find the path
 * @nb_tokens: numbers of tokens
 * @envp: environnement
 */
void which_path(char **tokens, int nb_tokens, char *envp[])
{
int found = 0;
char *path, *dir;
char *path_env = getenv("PATH");

if (path_env == NULL)
errors(EXIT_FAILURE, "(!) errors with getenv");

path = strdup(path_env);

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

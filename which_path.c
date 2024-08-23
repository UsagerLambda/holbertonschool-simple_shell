#include "header.h"
/**
 * which_path - Searches for a command in the directories listed in PATH.
 * @tokens: Array of command and arguments.
 * @nb_tokens: Number of tokens in the command.
 * @envp: Array of environment variables.
 * @line_ptr: Pointer to the line input, used for memory cleanup.
 *
 * This function splits the PATH environment variable into individual
 * directories and searches each directory for the specified command.
 * If the command is found in a directory, it is executed.
 */
void which_path(char **tokens, int nb_tokens, char *envp[], char *line_ptr)
{
int found = 0;
char *path, *dir;
char *path_env = NULL;
int i;
(void)line_ptr;

for (i = 0; envp[i] != NULL; i++)
{
	if (strncmp(envp[i], "PATH=", 5) == 0)
	{
		path_env = envp[i] + 5;
		break;
	}
}

if (path_env == NULL)
errors(EXIT_FAILURE, "getenv failed", tokens, line_ptr);

path = strdup(path_env);

if (path == NULL)
errors(EXIT_FAILURE, "strdup failed", tokens, line_ptr);

if (tokens[0] == NULL)
{
	errors(EXIT_FAILURE, "command not found", tokens, line_ptr);
	free(path);
	return;
}

if (access(tokens[0], X_OK) == 0 && tokens[0] != NULL)
{
	execute(tokens[0], tokens, envp, line_ptr);
	free(path);
	return;
}

dir = strtok(path, ":");
while (dir != NULL && !found)
{
	if (it_exist(dir, tokens, nb_tokens, envp, line_ptr))
	found = 1;
	dir = strtok(NULL, ":");
}

if (!found)
	errors(EXIT_FAILURE, "command not found", tokens, line_ptr);

free(path);
}

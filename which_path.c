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
void which_path(char **tokens, int nb_tokens, char *envp[], char *line_ptr)
{
int found = 0;
char *path, *dir;
char *path_env = getenv("PATH");
(void)line_ptr;

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

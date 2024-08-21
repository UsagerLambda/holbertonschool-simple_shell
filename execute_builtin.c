
#include "header.h"
/**
 * execute_builtin - Executes a built-in shell command.
 * @tokens: The array of command and arguments.
 * @envp: The environment variables.
 *
 * This function checks if the command in tokens[0] is a built-in command
 * (like `exit` or `env`). If it is, the corresponding function is executed.
 * If the command is not a built-in, the function returns -1.
 *
 * Return: Returns 0 if a built-in command is executed, -1 otherwise.
 */
int execute_builtin(char **tokens, char **envp)
{
	int i = 0;

	builtin_t builtins[] = {
	{"exit", shell_exit},
	{"env", shell_env},
	{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (-1);

	while (builtins[i].cmd != NULL)
	{
		if (strcmp(tokens[0], builtins[i].cmd) == 0)
		{
		return (builtins[i].func(tokens, envp));
		}
		i++;
	}
	return (-1);
}

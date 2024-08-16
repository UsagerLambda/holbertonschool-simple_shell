
#include "header.h"
/**
 * execute_builtin - -
 * @tokens: -
 * @envp: -
 * Return: -
 */
int execute_builtin(char **tokens, char **envp)
{
	int i = 0;

	builtin_t builtins[] = {
	{"exit", shell_exit},
	{"env", shell_env},
	{NULL, NULL}
	};


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

#include "header.h"
/**
 * shell_env - -
 * @args: -
 * @envp: -
 * Return: -
 */
int shell_env(char **args, char **envp)
{
	int i = 0;
	(void)args;

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}

/**
 * shell_exit - -
 * @args: -
 * @envp: -
 * Return: (0)
 */
int shell_exit(char **args, char **envp)
{
	(void)args;
	(void)envp;
	exit(0);
	return (0);
}

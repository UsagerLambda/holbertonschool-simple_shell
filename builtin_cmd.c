#include "header.h"
/**
 * shell_env - Prints the environment variables.
 * @args: The array of command and arguments (unused).
 * @envp: The environment variables.
 *
 * This function iterates through the environment variables and prints each
 * one to the standard output.
 *
 * Return: Always returns 0.
 */
int shell_env(char **args, char **envp, char *line_ptr)
{
	int i = 0;
	(void)args;

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	free(line_ptr);
	return (0);
}

/**
 * shell_exit - Exits the shell.
 * @args: The array of command and arguments (unused).
 * @envp: The environment variables (unused).
 *
 * This function exits the shell by calling the exit system call. It is
 * typically triggered when the user enters the "exit" command.
 *
 * Return: Always returns 0.
 */
int shell_exit(char **args, char **envp, char *line_ptr)
{
	(void)args;
	(void)envp;
	free(line_ptr);
	exit(0);
	return (0);
}

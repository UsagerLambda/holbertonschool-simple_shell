#include "header.h"
/**
 * shell_env - Prints the environment variables.
 * @args: Array of command and arguments (unused).
 * @envp: Array of environment variables.
 * @line_ptr: Pointer to the line input, used for memory cleanup.
 *
 * This function iterates through the environment variables and prints each
 * one to the standard output.
 *
 * Return: Always 0.
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
 * @args: Array of command and arguments (unused).
 * @envp: Array of environment variables (unused).
 * @line_ptr: Pointer to the line input, used for memory cleanup.
 *
 * This function exits the shell by calling the exit system call.
 * It is typically triggered when the user enters the "exit" command.
 *
 * Return: This function does not return, as it exits the process.
 */
int shell_exit(char **args, char **envp, char *line_ptr)
{
	(void)args;
	(void)envp;
	if (line_ptr == NULL)
	exit(1);

	free(line_ptr);
	exit(0);
}

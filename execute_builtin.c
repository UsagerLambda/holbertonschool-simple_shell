
#include "header.h"
/**
 * execute_builtin - Executes a built-in shell command.
 * @tokens: Array of command and arguments.
 * @envp: Array of environment variables.
 * @line_ptr: Pointer to the line input, used for memory cleanup.
 *
 * This function checks if the command in tokens[0] is a built-in command
 * (like `exit` or `env`). If it is, the corresponding function is executed.
 * If the command is not a built-in, the function returns -1.
 *
 * Return: 0 if a built-in command is executed, -1 otherwise.
 */
int execute_builtin(char **tokens, char **envp, char *line_ptr)
{
	if (strcmp(tokens[0], "exit") == 0)
		shell_exit(tokens, envp, line_ptr);

	if (strcmp(tokens[0], "env") == 0)
		shell_env(tokens, envp, line_ptr);

	return (-1);
}

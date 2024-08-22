#include "header.h"
/**
 * execute - Forks a child process to execute a command.
 * @path: Full path to the executable command.
 * @tokens: Array of command-line arguments, including the command name.
 * @envp: Array of environment variables.
 * @line_ptr: Pointer to the line input, used for memory cleanup.
 *
 * This function creates a new process using fork(). The child process
 * replaces its image with the command specified by `path` using execve().
 * If execve fails, an error message is printed, and the child process exits
 * with a failure status. The parent process waits for the child process to
 * complete before continuing.
 */
void execute(char *path, char *tokens[], char *envp[], char *line_ptr)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		errors(EXIT_FAILURE, "fork failed", tokens, line_ptr);

	if (pid == 0)
	{
		execve(path, &tokens[0], envp);
		errors(EXIT_FAILURE, "execve failed", tokens, line_ptr);
	}
	else
	{
		if (wait(&status) == -1)
		{
			errors(EXIT_FAILURE, "wait failed", tokens, line_ptr);
		}
	}
}

#include "header.h"
/**
 * execute - Forks a child process to execute a command.
 * @path: The full path to the executable command.
 * @tokens: An array of command-line arguments, including the command name.
 * @envp: The environment variables.
 *
 * This function creates a new process using fork(). The child process
 * replaces its image with the command specified by `path` using execve().
 * If execve fails, an error message is printed, and the child process exits
 * with a failure status. The parent process waits for the child process to
 * complete before continuing.
 */
void execute(char *path, char *tokens[], char *envp[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	errors(EXIT_FAILURE, "fork");

	if (pid == 0)
	{
	execve(path, &tokens[0], envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
	}
	else
	wait(&status);
}

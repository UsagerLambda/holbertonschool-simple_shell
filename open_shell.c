#include "header.h"
/**
 * open_shell - Runs the shell in interactive mode.
 * @argc: Number of command-line arguments.
 * @argv: Array of pointers to the arguments.
 * @envp: Array of environment variables.
 *
 * This function displays a prompt and waits for the user to input commands.
 * It processes each command by tokenizing the input, checking for built-ins,
 * and then executing the command.
 *
 * Return: Always 0.
 */
int open_shell(int argc, char *argv[], char *envp[])
{
	char *prompt = "$ ";
	char *line_ptr = NULL;
	char *tokens[10];
	int nb_tokens;
	size_t size_line = 0;
	ssize_t nbchar_line = 0;

	(void)argc;
	(void)argv;
	(void)envp;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);

		nbchar_line = getline(&line_ptr, &size_line, stdin);

		if (nbchar_line == -1)
		{
			if (line_ptr)
				free(line_ptr);
			if (isatty(STDIN_FILENO))
				printf("\n");
			return (0);
		}

		if (check_line_ptr(line_ptr) == 0)
			continue;

		parse(line_ptr, tokens, &nb_tokens);

		if (execute_builtin(tokens, envp, line_ptr) == -1)
			which_path(tokens, nb_tokens, envp, line_ptr);
		}
	free(line_ptr);
	return (0);
}


#include "header.h"
/**
 * open_shell - Runs the shell in interactive mode.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 * @envp: The environment variables.
 *
 * This function displays a prompt and waits for the user to input commands.
 * It processes each command by tokenizing the input, checking for built-ins,
 * and then executing the command if it exists in the PATH.
 *
 * Return: Returns 0 on success, or -1 on error.
 */
int open_shell(int argc, char *argv[], char *envp[])
{
char *prompt = "$ ";
char *line_ptr = NULL;
char *tokens[10];
int nb_tokens;
size_t size_line = 0;
int nbchar_line = 0;

(void)argc;
(void)argv;
(void)envp;

while (1)
{
	printf("%s", prompt);
	nbchar_line = getline(&line_ptr, &size_line, stdin);

	if (nbchar_line == -1)
	{
	free(line_ptr);
	printf("\n");
	return (-1);
	}

	if (line_ptr[nbchar_line - 1] == '\n')
		line_ptr[nbchar_line - 1] = '\0';

	parse(line_ptr, tokens, &nb_tokens);

	if (execute_builtin(tokens, envp) == -1)
		which_path(tokens, nb_tokens, envp);
}
free(line_ptr);
return (0);
}

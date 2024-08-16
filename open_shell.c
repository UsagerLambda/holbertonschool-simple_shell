#include "header.h"
/**
 * open_shell - Open a shell
 * @argc: numbers of arguments
 * @argv: content of arguments
 * @envp: environnement
 * Return: 0
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
	printf("Exiting the shell ...\n");
	return (-1);
	}

	if (line_ptr[nbchar_line - 1] == '\n')
		line_ptr[nbchar_line - 1] = '\0';

	parse(line_ptr, tokens, &nb_tokens);

	if (strcmp(tokens[0], "exit") == 0)
	{
		free(line_ptr);
		exit(0);
	}

	which_path(tokens, nb_tokens, envp);
}
free(line_ptr);
return (0);
}

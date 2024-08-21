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
    ssize_t nbchar_line = 0;
    int i = 0;

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

        if (line_ptr[nbchar_line - 1] == '\n')
        {
            line_ptr[nbchar_line - 1] = '\0';
        }

        parse(line_ptr, tokens, &nb_tokens);

        if (execute_builtin(tokens, envp) == -1)
        {
            which_path(tokens, nb_tokens, envp, line_ptr);
        }
    }

    if (line_ptr)
        free(line_ptr);

    while (tokens[i])
    {
    tokens[i] = NULL;
    i++;
    }

    return (0);
}

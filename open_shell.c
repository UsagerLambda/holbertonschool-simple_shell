#include "header.h"

int open_shell(int argc, char *argv[], char *envp[])
{
    char *prompt = "$ ";
    char *line_ptr = NULL;
    char *tokens[10];
    int nb_tokens;
    size_t size_line = 0;
    int nbchar_line = 0;
    char full_path[1024];

    (void)argc;
    (void)argv;

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

        if (execute_builtin(tokens, envp) == 0)
            continue;

        if (path_handle(tokens[0], full_path) == 0)
        {
            execute(full_path, tokens, envp);
        }
        else
        {
            printf("%s: command not found\n", tokens[0]);
        }
    }
    free(line_ptr);
    return (0);
}

int open_shell(int argc, char *argv[], char *envp[])
{
    char *prompt = "$ ";
    char *line_ptr = NULL;
    char *tokens[10];
    int nb_tokens;
    size_t size_line = 0;
    ssize_t nbchar_line; /* ssize_t is the correct type for getline return value */

    (void)argc;
    (void)argv;
    (void)envp;

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            printf("%s", prompt);
        }

        nbchar_line = getline(&line_ptr, &size_line, stdin);

        if (nbchar_line == -1)
        {
            /* If getline fails, free memory and handle error */
            if (line_ptr)
            {
                free(line_ptr);
            }
            if (isatty(STDIN_FILENO))
            {
                printf("\n");
            }
            return (0); /* or EXIT_FAILURE if appropriate */
        }

        /* Remove newline character from input */
        if (nbchar_line > 0 &&
            line_ptr[nbchar_line - 1] == '\n')
        {
            line_ptr[nbchar_line - 1] = '\0';
        }

        parse(line_ptr, tokens, &nb_tokens);

        /* Execute built-in commands or look up and execute commands from PATH */
        if (execute_builtin(tokens, envp) == -1)
        {
            which_path(tokens, nb_tokens, envp, line_ptr);
        }
    }

	/*Free line_ptr after exiting loop*/
    if (line_ptr)
    {
        free(line_ptr);
    }
	/*or EXIT_SUCCESS if appropriate*/
    return (0);
}

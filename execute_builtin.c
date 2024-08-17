#include "header.h"

int execute_builtin(char **tokens, char **envp)
{
    int i;
    builtin_t builtins[] = {
        {"exit", shell_exit},
        {"env", shell_env},
        {NULL, NULL}
    };

    for (i = 0; builtins[i].cmd; i++)
    {
        if (strcmp(tokens[0], builtins[i].cmd) == 0)
        {
            return builtins[i].func(tokens, envp);
        }
    }
    return (-1); 
}

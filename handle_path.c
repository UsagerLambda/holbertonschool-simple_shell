#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Return: 0 on success, 1 on error
 */
int path_handle(int argc, char *argv[])
{
    char *dir;
    char *path;
    char filepath[1024];

    /* Check if the user provided a command as an argument */
    if (argc < 2)
    {
        printf("Usage: %s command\n", argv[0]);
        return (1);
    }

    /* Get the PATH environment variable */
    path = getenv("PATH");
    /* Split the PATH into individual directories */
    dir = strtok(path, ":");

    /* Iterate through each directory in PATH */
    while (dir != NULL)
    {
        /* Construct the full file path */
        strcpy(filepath, dir);
        strcat(filepath, "/");
        strcat(filepath, argv[1]);

        /* Check if the file is accessible and executable */
        if (access(filepath, X_OK) == 0)
        {
            printf("Found: %s\n", filepath);
            return (0);
        }

        /* Move to the next directory in PATH */
        dir = strtok(NULL, ":");
    }

    /* If the command is not found in any directory */
    printf("%s: command not found\n", argv[1]);
    return (1);
}

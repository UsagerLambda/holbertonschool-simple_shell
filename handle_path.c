#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int path_handle(char *command, char *full_path)
{
    char *path, *dir;
    char filepath[1024];

    path = getenv("PATH");
    if (!path)
        return (-1);

    dir = strtok(path, ":");

    
    while (dir != NULL)
    {
        snprintf(filepath, sizeof(filepath), "%s/%s", dir, command);

        if (access(filepath, X_OK) == 0)
        {
            strcpy(full_path, filepath);
            return (0);
        }

        dir = strtok(NULL, ":");
    }

    return (-1);
}

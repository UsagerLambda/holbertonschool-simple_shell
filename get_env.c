#include "header.h"
/**
 * get_env - Retrieves the PATH environment variable.
 * @path_env: Pointer where the PATH value will be stored.
 * @envp: Array of environment variables.
 *
 * Description:
 * This function iterates through the array of environment variables (envp)
 * to find the "PATH" variable. When "PATH" is found, the function updates
 * the path_env pointer to point to the value of the "PATH" variable.
 * If "PATH" is not found, path_env remains unchanged.
 */
void get_env(char **path_env, char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			*path_env = envp[i] + 5;
			break;
		}
	}
}

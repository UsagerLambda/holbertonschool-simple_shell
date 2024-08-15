#include "header.h"
/**
 * execute - execute le commande in the path specified
 * @path: path to the command
 * @tokens: args of the command
 * @envp: environnement
 */
void execute(char *path, char *tokens[], char *envp[])
{
	execve(path, &tokens[0], envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

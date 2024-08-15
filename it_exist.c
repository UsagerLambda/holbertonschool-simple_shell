#include "header.h"
/**
 * it_exist - check if the path to the command exist
 * @dir: path to check
 * @tokens: commande to check the path
 * @nb_tokens: numbers of tokens
 * @envp: environnement
 * Return: 1 if the path is correct, 0 if not
 */
int it_exist(char *dir, char *tokens[], int nb_tokens, char *envp[])
{
pid_t pid;
char path[PATH_MAX];
strcpy(path, dir);
strcat(path, "/");

if (nb_tokens > 0 && tokens[0] != NULL)
	strcat(path, tokens[0]);

if (access(path, X_OK) == 0)
{
	pid = fork();

	if (pid == 0)
	execute(path, tokens, envp);
	else
	wait(NULL);
	return (1);
}
return (0);
}

#include "header.h"
/**
 * it_exist - check if the path to the command exist
 * @dir: path to check
 * @tokens: commande to check the path
 * @nb_tokens: numbers of tokens
 * @envp: environnement
 */
void it_exist(char *dir, char *tokens[], int nb_tokens, char *envp[])
{
char path[PATH_MAX];
strcpy(path, dir);
strcat(path, "/");
pid_t pid;

if (nb_tokens > 0 && tokens[0] != NULL)
	strcat(path, tokens[0]);

if (access(path, X_OK) == 0)
{
	pid = fork();
	if (pid == 0)
	execute(path, tokens, envp);
	else
	wait(NULL);
}
}

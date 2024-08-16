#include "header.h"
/**
 * main - Open a shell if argc < 2 else execute arguments
 * @argc: numbers of arguments
 * @argv: content of arguments
 * @envp: environnement
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
if (argc < 2)
open_shell(argc, argv, envp);
else
{
use_argv(argc, argv, envp);
}
return (0);
}

#include "header.h"
/**
 * main - Entry point for the simple shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 * @envp: The environment variables.
 *
 * This function initalizes the shell. If no arguments are provided,
 * it run in interactive mode; otherwise, it processes commands from
 * the arguments. It also handles cleanup and exits the shell properly.
 *
 * Return: Always returns 0 on success.
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

#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
/**
 * struct builtin_s - Represents a shell builtin command.
 * @cmd: The name of the builtin command (e.g., "exit", "env").
 * @func: A pointer to the function that executes the builtin command.
 *
 * This structure is used to associate a command name with its corresponding
 * function in the shell. The `cmd` member stores the name of the builtin
 * command as a string, while the `func` member is a function pointer that
 * points to the function responsible for executing the command. The function
 * takes two arguments: an array of arguments and the environment variables.
 */
typedef struct builtin_s
{
	char *cmd;
	int (*func)(char **args, char **envp);
} builtin_t;
int execute_builtin(char **tokens, char **envp);
int shell_exit(char **args, char **envp);
int shell_env(char **args, char **envp);
int open_shell(int argc, char *argv[], char *envp[]);
int use_argv(int argc, char *argv[], char *envp[]);
void parse(char *line_ptr, char *tokens[], int *nb_tokens);
void which_path(char **tokens, int nb_tokens, char *envp[]);
void errors(int code, char *str);
int it_exist(char *dir, char *tokens[], int nb_tokens, char *envp[]);
void execute(char *path, char *tokens[], char *envp[]);
#endif

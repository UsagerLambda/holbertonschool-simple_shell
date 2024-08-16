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
 * struct builtin_s - -
 * @cmd: -
 * @func: -
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

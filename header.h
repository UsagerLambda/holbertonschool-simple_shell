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
int check_line_ptr(char *str);
void get_env(char **path_env, char *envp[]);
int execute_builtin(char **tokens, char **envp, char *line_ptr);
int shell_exit(char **args, char **envp, char *line_ptr);
int shell_env(char **args, char **envp, char *line_ptr);
int open_shell(int argc, char *argv[], char *envp[]);
int use_argv(int argc, char *argv[], char *envp[]);
void parse(char *line_ptr, char *tokens[], int *nb_tokens);
void which_path(char **tokens, int nb_tokens, char *envp[], char *line_ptr);
void errors(int code, char *str, char *tok[], char *line_ptr);
int it_exist(char *dir, char *tokens[], int nb_tokens, char *envp[],
	char *line_ptr);
void execute(char *path, char *tokens[], char *envp[], char *line_ptr);
#endif

#include "header.h"
/**
 * errors - Prints an error message and exits the program.
 * @code: The exit code to use when terminating the program.
 * @str: The error message to print.
 * @tok: -
 *
 * This function prints the specified error message to the standard error
 * stream and then exits the program with the given exit code.
 */
void errors(int code, char *str, char *tok[], char *line_ptr)
{
(void)str;
if (isatty(0) == 0)
{
fprintf(stderr, "hsh: %d: %s: not found\n", code, tok[0]);
free(tok[0]);
free(line_ptr);
exit(127);
}
else
fprintf(stderr, "%s : command not found\n", tok[0]);
}

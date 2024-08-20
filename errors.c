#include "header.h"
/**
 * errors - Prints an error message and exits the program.
 * @code: The exit code to use when terminating the program.
 * @str: The error message to print.
 *
 * This function prints the specified error message to the standard error
 * stream and then exits the program with the given exit code.
 */
void errors(int code, char *str)
{
perror(str);
exit(code);
}

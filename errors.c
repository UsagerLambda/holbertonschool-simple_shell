#include "header.h"
/**
 * errors - Handles errors by printing a message and optionally freeing memory.
 * @code: Exit code for the process.
 * @str: Error message to print.
 * @tok: Array of tokens (can be NULL).
 * @line_ptr: Pointer to the line input, used for memory cleanup (can be NULL).
 *
 * This function prints an error message to stderr, frees any allocated
 * memory if necessary, and then exits the process with the given code.
 */
void errors(int code, char *str, char *tok[], char *line_ptr)
{
(void)str;
if (isatty(0) == 0)
{
fprintf(stderr, "hsh: %d: %s: not found\n", code, tok[0]);
if (line_ptr == NULL)
exit(127);
if (line_ptr)
free(line_ptr);
exit(127);
}
else
fprintf(stderr, "%s : command not found\n", tok[0]);
}

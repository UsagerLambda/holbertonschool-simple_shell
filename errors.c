#include "header.h"
/**
 * errors - handles errors
 * @str: error message
 * @code: return value
 */
void errors(int code, char *str)
{
dprintf(STDERR_FILENO, "%s\n", str);
exit(code);
}

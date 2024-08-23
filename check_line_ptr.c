#include "header.h"
/**
 * check_line_ptr - Checks if a string is non-empty and non-whitespace.
 * @str: String to be checked.
 *
 * This function iterates through the string and returns -1 if it
 * contains any non-whitespace characters. Otherwise, it returns 0.
 *
 * Return: -1 if the string contains non-whitespace characters, 0 otherwise.
 */
int check_line_ptr(char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\n' && *str != '\t')
			return (-1);
		str++;
	}
	return (0);
}

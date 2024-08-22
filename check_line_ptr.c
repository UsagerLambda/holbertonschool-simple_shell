#include "header.h"
/**
*/
int check_line_ptr(char *str)
{
    while (*str != '\0') {
        if (*str != ' ' && *str != '\n')
            return (-1);
        str++;
    }
    return (0);
}
#include "my_str.h"

int my_line_lenght(char const *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}
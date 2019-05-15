#include "my_str.h"

char *my_strcat_no_free(const char *left, const char *right)
{
    size_t len = my_strlen(left);
    char *new = malloc(len + my_strlen(right) + 1);

    if (!left || !right || !new)
        return (NULL);
    my_strcpy(new, left);
    my_strcpy(&new[len], right);
    return (new);
}


char *my_strcat(char **s1, char const *s2)
{
    int size = my_strlen(*s1) + my_strlen(s2) + 1;
    char *new_str = malloc(sizeof(char) * size);

    my_strcpy(new_str, *s1);
    my_strcpy(new_str + my_strlen(*s1), s2);
    free(*s1);
    *s1 = new_str;
    return (new_str);
}

char *my_strncat(char **s1, char const *s2, int n)
{
    int size = (my_strlen(s2) < n) ? my_strlen(s2) : n;
    char *new_str;

    size += my_strlen(*s1);
    new_str = malloc(sizeof(char) * (size + 1));
    my_strcpy(new_str, *s1);
    my_strncpy(new_str + my_strlen(*s1), s2, n);
    free(*s1);
    *s1 = new_str;
    return new_str;
}

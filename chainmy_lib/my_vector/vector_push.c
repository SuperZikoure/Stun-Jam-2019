#include "my_vector.h"

static void *smalloc(size_t size)
{
    void *ret;

    ret = malloc(size);
    if (!ret)
        exit(84);
    return (ret);
}

vector_t *vector_create(void)
{
    vector_t *new = smalloc(sizeof(vector_t));

    if (!new)
        return (NULL);
    new->size = 0;
    new->start = 0;
    new->end = 0;
    return (new);
}

void vector_push_back(vector_t *vect, void *content)
{
    link_t *to_insert;

    if (vect->start == 0) {
        to_insert = link_create(content);
        if (!to_insert)
            return;
        vect->size++;
        vect->start = to_insert;
        vect->end = to_insert;
        return;
    }
    link_push_after(vect->end, content);
    vect->end = vect->end->next;
    vect->size++;
}

void vector_push_top(vector_t *vect, void *content)
{
    if (vect->start == 0) {
        vector_push_back(vect, content);
        return;
    }
    link_push_before(vect->start, content);
    vect->start = vect->start->prev;
    vect->size++;
}
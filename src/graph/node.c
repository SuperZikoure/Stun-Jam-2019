/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** node
*/

#include "graphs.h"

node_t *node_create(void)
{
    node_t *new = malloc(sizeof(node_t));

    new->owner = NEUTRAL;
    new->defense = 0;
    new->attack = 0;
    new->links = vector_create();
    return (new);
}

void node_destroy(node_t *node)
{
    free(node->links);
    free(node);
}
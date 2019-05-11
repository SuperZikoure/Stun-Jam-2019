/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** graph
*/

#include "graphs.h"

graph_t *graph_create(void)
{
    graph_t *new = malloc(sizeof(graph_t));

    return (new);
}

void graph_destroy(graph_t *graph)
{
    free(graph);
}
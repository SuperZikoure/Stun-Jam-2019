/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** graph
*/

#include "graphs.h"

static void *smalloc(size_t size)
{
    void *ret;

    ret = malloc(size);
    if (!ret)
        exit(84);
    return (ret);
}

graph_t *graph_create(void)
{
    graph_t *new = smalloc(sizeof(graph_t));

    new->nodes = vector_create();
    new->selected = NULL;
    return (new);
}

void graph_destroy(graph_t *graph)
{
    while (graph->nodes->start) {
        node_destroy((node_t*)graph->nodes->start->content);
        vector_pop_top(graph->nodes);
    }
    free(graph->nodes);
    free(graph);
}

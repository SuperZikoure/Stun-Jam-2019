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

    new->nodes = vector_create();
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
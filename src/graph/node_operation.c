/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** node_operation
*/

#include "graphs.h"

void node_create_link(node_t *node1, node_t *node2)
{
    vector_push_back(node1->links, node2);
    vector_push_back(node2->links, node1);
}

void node_create_link_from_id(graph_t *graph, int node1, int node2)
{
    node_t *a = graph_get_node_by_id(graph, node1);
    node_t *b = graph_get_node_by_id(graph, node2);

    node_create_link(a, b);
}
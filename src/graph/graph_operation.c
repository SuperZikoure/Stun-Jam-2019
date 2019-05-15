#include "graphs.h"

node_t *graph_get_node_by_id(graph_t *graph, int id)
{
    link_t *current = graph->nodes->start;
    node_t *current_content;

    while (current) {
        current_content = (node_t*)current->content;
        if (current_content->id == id)
            return (current_content);
        current = current->next;
    }
    return (NULL);
}
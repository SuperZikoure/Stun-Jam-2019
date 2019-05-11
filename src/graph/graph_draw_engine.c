/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** graph_draw_engine
*/

#include "graphs.h"

void sfRenderWindow_drawGraph(sfRenderWindow *window, graph_t *graph)
{
    link_t *current = graph->nodes->start;
    node_t *current_content;

    while (current) {
        current_content = (node_t*)current->content;
        sfRenderwindow_drawNode(window, current_content);
        current = current->next;
    }
}
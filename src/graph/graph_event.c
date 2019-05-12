/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** graph_event
*/

#include "graphs.h"

void graph_event_clicked(graph_t *graph, sfRenderWindow *window)
{
    link_t *current = graph->nodes->start;
    node_t *current_content;

    if (sfMouse_isButtonPressed(sfMouseLeft))
        graph->selected = NULL;
    while (current) {
        current_content = (node_t*)current->content;
        if (node_isClicked(current_content, window))
            graph->selected = current_content;
        current = current->next;
    }
    current = graph->nodes->start;
    while (current) {
        current_content = (node_t*)current->content;
        if (node_isClicked(current_content, window)) {
            graph->skill = current_content;
        }
        current = current->next;
    }
}
/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** graph_event
*/

#include "game.h"
#include "graphs.h"

void graph_event_clicked(graph_t *graph, sfRenderWindow *window, game_t *game)
{
    link_t *current = graph->nodes->start;
    node_t *current_content;

    if (sfMouse_isButtonPressed(sfMouseLeft))
        graph->selected = NULL;
    while (current) {
        current_content = (node_t*)current->content;
        if (node_isClicked(current_content, window, game))
            graph->selected = current_content;
        current = current->next;
    }
    current = graph->nodes->start;
    while (current) {
        current_content = (node_t*)current->content;
        if (node_isClicked(current_content, window, game)) {
            graph->skill = current_content;
        }
        current = current->next;
    }
}
#include "game.h"

void game_fill_graph(game_t *game)
{
    node_t *current;

    for (int i = 0; i < NB_NODE; i++) {
        current = node_create(pos_nodes[i].x, pos_nodes[i].y, game->assets);
        vector_push_back(game->graph->nodes, current);
    }
    node_create_link_from_id(game->graph, 0, 1);
    node_create_link_from_id(game->graph, 1, 2);
    node_create_link_from_id(game->graph, 2, 3);
    node_create_link_from_id(game->graph, 0, 4);
    node_create_link_from_id(game->graph, 4, 1);
    node_create_link_from_id(game->graph, 1, 5);
    node_create_link_from_id(game->graph, 1, 6);
    node_create_link_from_id(game->graph, 2, 6);
    node_create_link_from_id(game->graph, 2, 7);
    node_create_link_from_id(game->graph, 3, 7);
    node_create_link_from_id(game->graph, 4, 5);
    node_create_link_from_id(game->graph, 5, 6);
    node_create_link_from_id(game->graph, 6, 7);
    node_create_link_from_id(game->graph, 7, 8);
    node_create_link_from_id(game->graph, 9, 5);
    node_create_link_from_id(game->graph, 9, 6);
    node_create_link_from_id(game->graph, 9, 10);
    node_create_link_from_id(game->graph, 6, 10);
    node_create_link_from_id(game->graph, 6, 11);
    node_create_link_from_id(game->graph, 6, 8);
    node_create_link_from_id(game->graph, 10, 11);
    node_create_link_from_id(game->graph, 8, 11);
    node_create_link_from_id(game->graph, 11, 12);
    node_create_link_from_id(game->graph, 8, 12);
    node_create_link_from_id(game->graph, 9, 13);
    node_create_link_from_id(game->graph, 9, 14);
    node_create_link_from_id(game->graph, 10, 14);
    node_create_link_from_id(game->graph, 10, 15);
    node_create_link_from_id(game->graph, 11, 15);
    node_create_link_from_id(game->graph, 13, 14);
    node_create_link_from_id(game->graph, 14, 15);
    node_create_link_from_id(game->graph, 15, 16);
    node_create_link_from_id(game->graph, 12, 16);
}
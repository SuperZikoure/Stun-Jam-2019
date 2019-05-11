/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "game.h"

sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "game", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int main(void)
{
    game_t *game = game_create(init_window());

    vector_push_back(game->graph->nodes, node_create(100, 100, game->assets));
    vector_push_back(game->graph->nodes, node_create(200, 150, game->assets));
    vector_push_back(game->graph->nodes, node_create(200, 100, game->assets));
    node_create_link_from_id(game->graph, 0, 1);
    node_create_link_from_id(game->graph, 1, 2);
    node_create_link_from_id(game->graph, 0, 2);
    game_loop(game);
    game_destroy(game);
    return (0);
}

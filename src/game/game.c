#include "game.h"

void game_destroy(game_t game)
{
    sfRenderWindow_close(game.window->window);
    assets_destroy(game.assets);
    graph_destroy(game.graph);
}
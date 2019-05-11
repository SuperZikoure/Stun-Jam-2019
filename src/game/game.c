/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** game
*/

#include "game.h"


static void *smalloc(size_t size)
{
    void *ret;

    ret = malloc(size);
    if (!ret)
        exit(84);
    return (ret);
}

game_t *game_create(sfRenderWindow *window)
{
    game_t *new = smalloc(sizeof(game_t));

    new->assets = assets_create();
    new->graph = graph_create();
    game_fill_graph(new);
    new->window = window;
    new->should_exit = false;
    new->debug_mode = false;
    return (new);
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window) && !game->should_exit) {
        game_event(game);
        if (game->debug_mode)
            game_debug(game);
        game_draw(game);
    }
}

void game_draw(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawGraph(game->window, game->graph);
    sfRenderWindow_display(game->window);
}

void game_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void game_destroy(game_t *game)
{
    sfRenderWindow_close(game->window);
    assets_destroy(game->assets);
    graph_destroy(game->graph);
    free(game);
}

void game_debug(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    printf("mouse> x: %d || y: %d\n", mouse.x, mouse.y);
}
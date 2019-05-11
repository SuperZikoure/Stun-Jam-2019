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

    game_loop(game);
    game_destroy(game);
    return (0);
}

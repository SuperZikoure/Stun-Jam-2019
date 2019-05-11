/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "game.h"
#include "my_str.h"

sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "game", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int main(int argc, char **argv)
{
    game_t *game = game_create(init_window());

    if (argc == 2 && my_strcmp("-d", argv[1]))
        game->debug_mode = true;
    game_loop(game);
    game_destroy(game);
    return (0);
}

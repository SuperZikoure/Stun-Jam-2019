/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loop_game
*/

#include "game.h"

void game_loop(game_t *game)
{
    start_clock();
    change_stream(game);
    while (sfRenderWindow_isOpen(game->window->window) && !game->exit) {
        start_new_frame();
        if (!sfRenderWindow_hasFocus(game->window->window))
            continue;
        if (analyse_events(game))
            break;
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window->window);
        update_fetch_anim();
        sfRenderWindow_clear(game->window->window, sfBlack);
        if (get_scene()(game) == -1)
            game->exit = -1;
        game->space_pressed = 0;
        sfRenderWindow_display(game->window->window);
    }
    if (sfRenderWindow_isOpen(game->window->window))
        sfRenderWindow_close(game->window->window);
}

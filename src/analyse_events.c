/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_events
*/

#include "game.h"

int analyse_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            return 1;
        }
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyF12))
            do_screenshot(game->window);
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeySpace)) {
            game->space_pressed = 1;
        }
    }
    return 0;
}

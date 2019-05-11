/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_button
*/

#include "game.h"

static void manage_button2(button_t *button)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        button->mouse_click = 0;
    if (button->mouse_hover)
        button->display = button->hover;
    else
        button->display = button->base;
    if (button->mouse_click)
        button->display = button->click;
    display_image(button->display, button->pos);
}

static void manage_button(button_t *b, game_t *game)
{
    if (point_intersect(b->display, game->mouse_pos.x, game->mouse_pos.y))
        b->mouse_hover = 1;
    else
        b->mouse_hover = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && b->mouse_hover)
        b->mouse_click = 1;
    if (!sfMouse_isButtonPressed(sfMouseLeft) && b->mouse_hover && b->mouse_click) {
        if (game->sound)
            sfSound_play(b->click_sound->sound);
        b->trigger(game, b->option);
        b->mouse_click = 0;
    }
    manage_button2(b);
}

void show_scene_buttons(game_t *game)
{
    enum enum_scene_e scene = get_scene_id();

    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        if (game->buttons[i]->scene == scene)
            manage_button(game->buttons[i], game);
    }
}

/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loop_game
*/

#include "game.h"

static void manage_music(game_t *game, int index)
{
    static music_t *playing = NULL;
    static int play = 1;

    if (index == -2)
        play = 0;
    else if (index >= 0)
        play = 1;
    if (index == -1 && playing != NULL && game->sound && play) {
        if (!sfMusic_getLoop(playing->main))
            sfMusic_setLoop(playing->main, sfTrue);
        if (sfMusic_getStatus(playing->main) != sfPlaying)
            sfMusic_play(playing->main);
    } else if (index < MUSIC_AMOUNT && game->sound && play && playing != game->musics[index])
        playing = game->musics[index];
    if (!game->sound && playing != NULL) {
        if (sfMusic_getStatus(playing->main) == sfPlaying)
            sfMusic_setVolume(playing->main, 0);
    } else if (playing != NULL) {
        if (sfMusic_getStatus(playing->main) == sfPlaying)
            sfMusic_setVolume(playing->main, 100);
    }
    if (!play && playing != NULL)
        if (sfMusic_getStatus(playing->main) != sfStopped)
            sfMusic_stop(playing->main);
}

void set_music(game_t *game, int index)
{
    static int last_call = -1;

    for (int i = 0; i < MUSIC_AMOUNT && index >= 0; i++) {
        if (sfMusic_getStatus(game->musics[i]->main) == sfPlaying && i != last_call)
            sfMusic_stop(game->musics[i]->main);
    }
    if (index == -1)
        manage_music(game, -2);
    else
        manage_music(game, index);
    last_call = index;
}

void game_loop(game_t *game)
{
    start_clock();
    change_stream(game);
    set_music(game, MENU_MUSIC);
    while (sfRenderWindow_isOpen(game->window->window) && !game->exit) {
        start_new_frame();
        if (!sfRenderWindow_hasFocus(game->window->window)) {
                for (int i = 0; i < MUSIC_AMOUNT; i++) {
                    if (sfMusic_getStatus(game->musics[i]->main) == sfPlaying)
                        sfMusic_pause(game->musics[i]->main);
                }
            continue;
        }
        if (analyse_events(game))
            break;
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window->window);
        update_fetch_anim();
        sfRenderWindow_clear(game->window->window, sfBlack);
        if (get_scene()(game) == -1)
            game->exit = -1;
        manage_music(game, -1);
        game->space_pressed = 0;
        sfRenderWindow_display(game->window->window);
    }
    set_music(game, -1);
    if (sfRenderWindow_isOpen(game->window->window))
        sfRenderWindow_close(game->window->window);
}

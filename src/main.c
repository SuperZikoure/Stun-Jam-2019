/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <time.h>
#include "my_str.h"

static void fill_nodes(game_t *game)
{
    link_t *current = game->graph->nodes->end;
    node_t *current_content;

    current_content = (node_t*)current->prev->prev->prev->content;
    current_content->owner = PLAYER1;
    current = game->graph->nodes->end;
    current_content = (node_t*)current->content;
    current_content->owner = PLAYER2;
}

player_t fill_player(void) {
    player_t player;

    player.money = 0;
    player.skills[0] = 0;
    player.skills[1] = 0;
    player.skills[2] = 0;
    player.can_buy = 1;
    player.used[0] = 0;
    player.used[1] = 0;
    player.used[2] = 0;
    return player;
}

static game_t create_game(void)
{
    game_t game;

    game.window = create_window(0, "TVLINK");
    for (int i = 0; i < TEXT_AMOUNT; i++)
        game.texts[i] = create_text(font_size[i], font_path[i], game.window);
    for (int i = 0; i < MUSIC_AMOUNT; i++)
        game.musics[i] = load_music(music_path[i]);
    for (int i = 0; i < SOUND_AMOUNT; i++)
        game.sounds[i] = create_sound(sound_path[i]);
    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        game.buttons[i] = create_button(&info[i], game.window);
    }
    game.assets = assets_create();
    game.graph = graph_create();
    game_fill_graph(&game);
    game.mouse_pos = V2I(0, 0);
    game.sound = 1;
    game.should_exit = false;
    game.exit = 0;
    game.players[PLAYER1] = fill_player();
    game.players[PLAYER2] = fill_player();
    game.turn = 0;
    game.game_state = 0;
    game.timer = TIMER_START;
    game.countdown = COUNTDOWN_START;
    game.change = 0;
    game.win = 0;
    fill_nodes(&game);
    return (game);
}

static bool has_display_env_variable(char const *env[])
{
    for (size_t i = 0; env[i]; i++) {
        if (my_strncmp("DISPLAY", env[i], 7))
            continue;
        return true;
    }
    return false;
}

static int game_main(void)
{
    game_t game = create_game();

    srand(time(NULL));
    if (fill_image(game.window) == -1 || fill_anim(game.window) == -1)
        return 84;
    change_scene(MAIN_MENU);
    game_loop(&game);
    if (game.exit == -1)
        return 84;
    //destroy_game(&game);
    game_destroy(game);
    return 0;
}

int main(int argc, char const *argv[], char const *env[])
{
    if (argc > 1) {
        dprintf(2, "Sorry, %s does not take any arguments\n", argv[0]);
        return 0;
    }
    if (!has_display_env_variable(env)) {
        dprintf(2, "ERROR: The current DISPLAY environement varible is not supported\n");
        return 84;
    }
    return game_main();
}

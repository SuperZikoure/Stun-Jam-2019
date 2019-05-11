/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <stdio.h>
#include "game.h"
#include "my_str.h"

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
    game.mouse_pos = V2I(0, 0);
    game.sound = 1;
    game.exit = 0;
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

    if (fill_image(game.window) == -1 || fill_anim(game.window) == -1)
        return 84;
    change_scene(MAIN_MENU);
    game_loop(&game);
    if (game.exit == -1)
        return 84;
    //destroy_game(&game);
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

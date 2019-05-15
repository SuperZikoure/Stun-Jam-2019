/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** info.c
*/

#include "graph.h"
#include "macros.h"
#include "game.h"

const char *image_path[IMAGE_AMOUNT] = {
    "assets/backgrounds/main_menu.png",
    "assets/backgrounds/game_layout.png",
    "assets/backgrounds/black.png",
    "assets/animations/watch_tv.png",
    "assets/nodes/shield_0.png",
    "assets/nodes/shield_1.png",
    "assets/nodes/shield_2.png",
    "assets/nodes/boost_0.png",
    "assets/nodes/boost_1.png",
    "assets/nodes/boost_2.png",
    "assets/nodes/boosted.png"
};

const char *font_path[TEXT_AMOUNT] = {
    "assets/fonts/font.ttf",
    "assets/fonts/font.ttf",
    "assets/fonts/font.ttf"
};

const int font_size[TEXT_AMOUNT] = {
    32,
    18,
    10
};

const info_anim_t anim_info[ANIM_AMOUNT] = {
    {{30, 12}, {512, 392}, "assets/animations/change_tv.png"},
    {{1, 0}, {246, 176}, "assets/tv/player_1.png"},
    {{1, 0}, {246, 176}, "assets/tv/player_2.png"},
    {{27, 6}, {246, 176}, "assets/tv/ads_1.png"},
    {{27, 6}, {246, 176}, "assets/tv/ads_2.png"}
};


const char *music_path[MUSIC_AMOUNT] = {
    "assets/musics/Main_Menu.wav",
    "assets/musics/Game_1.wav",
    "assets/musics/Game_2.wav",
    "assets/musics/Game_3.wav",
    "assets/musics/Game_4.wav",
    "assets/musics/Pause.wav",
    "assets/musics/Win.wav",
};

const char *sound_path[SOUND_AMOUNT] = {
    "assets/sounds/click.wav",
    "assets/musics/Chrono.wav"
};

const info_button_t info[BUTTON_AMOUNT] = {
    {{50, 150}, GAME, MAIN_MENU, "play", put_scene},
    {{50, 250}, HOW_TO_PLAY, MAIN_MENU, "help", put_scene},
    {{50, 350}, 0, MAIN_MENU, "exit", exit_game},
    {{25, 650}, CREDITS, MAIN_MENU, "credits", put_scene},
    {{100, 650}, 0, MAIN_MENU, "sound", change_sound},
    {{768, 0}, 0, GAME, "end", end_turn},
    {{1180, 88}, 0, GAME, "buy", buy_skill},
    {{1180, 165}, 1, GAME, "buy", buy_skill},
    {{1180, 241}, 2, GAME, "buy", buy_skill},
    {{1080, 88}, 0, GAME, "use", use_skill},
    {{1080, 165}, 1, GAME, "use", use_skill},
    {{1080, 241}, 2, GAME, "use", use_skill}
};
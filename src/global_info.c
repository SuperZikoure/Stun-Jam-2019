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
    "assets/animations/watch_tv.png"
};

const char *font_path[TEXT_AMOUNT] = {
    "assets/fonts/font.ttf",
};

const int font_size[TEXT_AMOUNT] = {
    12,
};

const info_anim_t anim_info[ANIM_AMOUNT] = {
    {{30, 12}, {512, 392}, "assets/animations/change_tv.png"},
};


const char *music_path[MUSIC_AMOUNT] = {
    "assets/musics/Main_Menu.wav",
};

const char *sound_path[SOUND_AMOUNT] = {
    "assets/sounds/click.wav",
};

const info_button_t info[BUTTON_AMOUNT] = {
    {{50, 150}, GAME, MAIN_MENU, "play", put_scene},
    {{50, 250}, HOW_TO_PLAY, MAIN_MENU, "help", put_scene},
    {{50, 350}, 0, MAIN_MENU, "exit", exit_game},
    {{25, 650}, CREDITS, MAIN_MENU, "credits", put_scene},
    {{100, 650}, 0, MAIN_MENU, "sound", exit_game}
};
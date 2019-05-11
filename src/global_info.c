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
};

const char *font_path[TEXT_AMOUNT] = {
    "assets/fonts/font.ttf",
};

const int font_size[TEXT_AMOUNT] = {
    12,
};

const info_anim_t anim_info[ANIM_AMOUNT] = {
    {{30, 12}, {640, 360}, "assets/animations/change_tv.png"},
};


const char *music_path[MUSIC_AMOUNT] = {
    "assets/musics/Main_Menu.wav",
};

const char *sound_path[SOUND_AMOUNT] = {
    "assets/sounds/click.wav",
};

const info_button_t info[BUTTON_AMOUNT] = {
    {{50, 148}, 0, MAIN_MENU, "play", exit_game},
};
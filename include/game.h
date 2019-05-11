/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include "assets.h"
#include "graphs.h"
#include "graph.h"
#include "data.h"
#include "macros.h"
#include <stdbool.h>
#include <stdlib.h>


/*struct game {
    assets_t *assets;
    graph_t *graph;
    sfRenderWindow *window;
    bool should_exit;
}*/

struct game_s {
    window_t *window;
    text_t *texts[TEXT_AMOUNT];
    assets_t *assets;
    graph_t *graph;
    music_t *musics[MUSIC_AMOUNT];
    sound_t *sounds[SOUND_AMOUNT];
    button_t *buttons[BUTTON_AMOUNT];
    sfVector2i mouse_pos;
    int sound;
    int exit;
};

// game.c
game_t *game_create(sfRenderWindow *window);
void game_loop(game_t *game);
void game_draw(game_t *game);
void game_event(game_t *game);
void game_destroy(game_t *game);

/* fetch_anim.c */
anim_t *get_anim(int index);
void update_fetch_anim(void);
int fill_anim(window_t *window);

/* fetch_image.c */
image_t *get_image(int index);
int fill_image(window_t *window);

/* CLOCK && FPS */
size_t get_delta(void);
int start_clock(void);
void start_new_frame(void);

/* GAMELOOP && EVENTS */
void game_loop(game_t *game);
int analyse_events(game_t *game);


/* SCENES */

int (*get_scene(void))(game_t *);
enum enum_scene_e get_scene_id(void);
void change_scene(enum enum_scene_e id);

/* MANAGE BUTTONS */
button_t *create_button(const info_button_t *info, window_t *window);
button_t *find_button(game_t *game, char *name, enum enum_scene_e scene);
void show_scene_buttons(game_t *game);

/* BUTTONS FUNCTIONS */
int exit_game(game_t *game, int a);

/* INTERSECTIONS */
int image_intersect(image_t *img1, image_t *img2);
int point_intersect(image_t *img, float x, float y);
int text_intersect(sfText *text, image_t *image);

/* MENU */
int manage_menu(game_t *game);

#endif /* !GAME_H_ */

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

typedef struct player_s {
    int money;
    int skills[3];
    int can_buy;
    int used[3];
} player_t;

struct game_s {
    window_t *window;
    text_t *texts[TEXT_AMOUNT];
    assets_t *assets;
    graph_t *graph;
    music_t *musics[MUSIC_AMOUNT];
    sound_t *sounds[SOUND_AMOUNT];
    button_t *buttons[BUTTON_AMOUNT];
    player_t players[3];
    int timer;
    int turn;
    int space_pressed;
    int game_state;
    sfVector2i mouse_pos;
    bool should_exit;
    int sound;
    int exit;
};

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
int put_scene(game_t *game, int a);
int change_sound(game_t *game, int a);
int buy_skill(game_t *game, int a);
int end_turn(game_t *game, int a);
int use_skill(game_t *game, int a);

/* INTERSECTIONS */
int image_intersect(image_t *img1, image_t *img2);
int point_intersect(image_t *img, float x, float y);
int text_intersect(sfText *text, image_t *image);

#define NB_NODE 17
static const sfVector2i pos_nodes[] = {
                                    {120, 60},
                                    {250, 120},
                                    {390, 60},
                                    {550, 80},
                                    {56, 185},
                                    {115, 300},
                                    {365, 260},
                                    {497, 212},
                                    {600, 315},
                                    {50, 435},
                                    {300, 410},
                                    {480, 400},
                                    {635, 480},
                                    {80, 600},
                                    {240, 560},
                                    {430, 530},
                                    {580, 600}
};

void game_fill_graph(game_t *game);
void game_destroy(game_t game);

// graph_draw_engine.c
void sfRenderWindow_drawGraph(sfRenderWindow *window, graph_t *graph, game_t *game);

// SCENES // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/* MENU */
int manage_menu(game_t *game);
void update_menu(game_t *game);
void display_menu(game_t *game);


/* HOW TO PLAY */
int manage_htp(game_t *game);
void update_htp(game_t *game);
void display_htp(game_t *game);


/* GAME */
int manage_game(game_t *game);
void update_game(game_t *game);
void display_game(game_t *game);


/* PAUSE */
int manage_pause(game_t *game);
void update_pause(game_t *game);
void display_pause(game_t *game);


/* WIN */
int manage_win(game_t *game);
void update_win(game_t *game);
void display_win(game_t *game);


/* CREDITS */
int manage_credits(game_t *game);
void update_credits(game_t *game);
void display_credits(game_t *game);

#endif /* !GAME_H_ */

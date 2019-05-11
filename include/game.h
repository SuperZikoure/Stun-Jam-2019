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
#include <stdbool.h>
#include <stdlib.h>

struct game {
    assets_t *assets;
    graph_t *graph;
    sfRenderWindow *window;
    bool should_exit;
    bool debug_mode;
};
typedef struct game game_t;

// game.c
game_t *game_create(sfRenderWindow *window);
void game_loop(game_t *game);
void game_draw(game_t *game);
void game_event(game_t *game);
void game_destroy(game_t *game);
void game_debug(game_t *game);

// game_init.c
void game_fill_graph(game_t *game);

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

#endif /* !GAME_H_ */

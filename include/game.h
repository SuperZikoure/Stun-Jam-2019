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
};
typedef struct game game_t;

// game.c
game_t *game_create(sfRenderWindow *window);
void game_loop(game_t *game);
void game_draw(game_t *game);
void game_event(game_t *game);
void game_destroy(game_t *game);

#endif /* !GAME_H_ */

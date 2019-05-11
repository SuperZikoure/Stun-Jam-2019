/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** assets
*/

#ifndef ASSETS_H_
#define ASSETS_H_

#include <SFML/Graphics.h>
#include <stdlib.h>

enum owner {NEUTRAL, PLAYER1, PLAYER2};
enum button {IDLE, HOVER, CLICKED};

struct assets {
    sfTexture *nodes[3][3];
};
typedef struct assets assets_t;

// assets.c
assets_t *assets_create(void);
void assets_destroy(assets_t *assets);


#endif /* !ASSETS_H_ */

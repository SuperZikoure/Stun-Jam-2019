/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** assets
*/

#ifndef ASSETS_H_
#define ASSETS_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

struct assets {

};
typedef struct assets assets_t;

// assets.c
assets_t *assets_create(void);
void assets_destroy(assets_t *assets);

#endif /* !ASSETS_H_ */

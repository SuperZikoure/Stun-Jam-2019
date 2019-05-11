/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** assets
*/

#include "assets.h"

assets_t *assets_create(void)
{
    assets_t *new = malloc(sizeof(assets_t));

    return (new);
}

void assets_destroy(assets_t *assets)
{
    free(assets);
}
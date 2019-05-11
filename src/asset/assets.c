/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** assets
*/

#include "assets.h"

static void load_node_assets(assets_t *assets)
{
    assets->nodes[NEUTRAL][IDLE] = sfTexture_createFromFile("assets/nodes/green_node0.png", NULL);
    assets->nodes[NEUTRAL][HOVER] = sfTexture_createFromFile("assets/nodes/green_node1.png", NULL);
    assets->nodes[NEUTRAL][CLICKED] = sfTexture_createFromFile("assets/nodes/green_node2.png", NULL);
    assets->nodes[PLAYER1][IDLE] = sfTexture_createFromFile("assets/nodes/blue_node0.png", NULL);
    assets->nodes[PLAYER1][HOVER] = sfTexture_createFromFile("assets/nodes/blue_node1.png", NULL);
    assets->nodes[PLAYER1][CLICKED] = sfTexture_createFromFile("assets/nodes/blue_node2.png", NULL);
    assets->nodes[PLAYER2][IDLE] = sfTexture_createFromFile("assets/nodes/red_node0.png", NULL);
    assets->nodes[PLAYER2][HOVER] = sfTexture_createFromFile("assets/nodes/red_node1.png", NULL);
    assets->nodes[PLAYER2][CLICKED] = sfTexture_createFromFile("assets/nodes/red_node2.png", NULL);
}

assets_t *assets_create(void)
{
    assets_t *new = malloc(sizeof(assets_t));

    load_node_assets(new);
    return (new);
}

void assets_destroy(assets_t *assets)
{
    free(assets);
}
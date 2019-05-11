/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** node
*/

#include "graphs.h"

node_t *node_create(int x, int y, assets_t *assets)
{
    node_t *new = malloc(sizeof(node_t));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new->sprites[i][j] = sfSprite_create();
            sfSprite_setTexture(new->sprites[i][j], assets->nodes[i][j], sfTrue);
        }
    }
    new->owner = NEUTRAL;
    new->defense = 0;
    new->attack = 0;
    new->pos = (sfVector2f){x, y};
    new->links = vector_create();
    return (new);
}

void sfRenderwindow_drawNode(sfRenderWindow *window, node_t *node)
{
    sfSprite *to_draw = node->sprites[node->owner][IDLE];

    sfSprite_setPosition(to_draw, node->pos);
    sfRenderWindow_drawSprite(window, to_draw, NULL);
}

void node_destroy(node_t *node)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            sfSprite_destroy(node->sprites[i][j]);
    }
    free(node->links);
    free(node);
}
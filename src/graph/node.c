/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** node
*/

#include "graphs.h"

static void *smalloc(size_t size)
{
    void *ret;

    ret = malloc(size);
    if (!ret)
        exit(84);
    return (ret);
}

node_t *node_create(int x, int y, assets_t *assets)
{
    node_t *new = smalloc(sizeof(node_t));
    static int id = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new->sprites[i][j] = sfSprite_create();
            sfSprite_setTexture(new->sprites[i][j], assets->nodes[i][j], sfTrue);
        }
    }
    new->id = id;
    id++;
    new->owner = NEUTRAL;
    new->defense = 0;
    new->boost = 0;
    new->pos = (sfVector2f){x, y};
    new->links = vector_create();
    return (new);
}

void sfRenderWindow_drawNode(sfRenderWindow *window, node_t *node, game_t *game)
{
    sfSprite *to_draw;
    int state;

    if (node_isClicked(node, window, game))
        state = CLICKED;
    else if (node_isHover(node, window, game))
        state = HOVER;
    else
        state = IDLE;
    to_draw = node->sprites[node->owner][state];
    sfSprite_setPosition(to_draw, node->pos);
    sfRenderWindow_drawSprite(window, to_draw, NULL);
}

void sfRenderWindow_drawNodelink(sfRenderWindow *window, node_t *node)
{
    link_t *current = node->links->start;
    node_t *current_content;

    while (current) {
        current_content = (node_t*)current->content;
        sfRenderWindow_drawLine(window, node->pos, current_content->pos);
        current = current->next;
    }
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
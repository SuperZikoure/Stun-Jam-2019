/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** node_event
*/

#include "graphs.h"
#include "game.h"

bool node_isHover(node_t *node, sfRenderWindow *window, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > node->pos.x && mouse.x < node->pos.x + NODE_SIZE) {
        if (mouse.y > node->pos.y && mouse.y < node->pos.y + NODE_SIZE) {;
            if (can_be_drawn(node, game))
                return (true);
        }
    }
    return (false);
}

bool node_isClicked(node_t *node, sfRenderWindow *window, game_t *game)
{
    if (node_isHover(node, window, game) && sfMouse_isButtonPressed(sfMouseLeft))
        return (true);
    return (false);
}
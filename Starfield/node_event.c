/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** node_event
*/

#include "graphs.h"

bool node_isHover(node_t *node, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > node->pos.x && mouse.x < node->pos.x + NODE_SIZE) {
        if (mouse.y > node->pos.y && mouse.y < node->pos.y + NODE_SIZE) {;
            return (true);
        }
    }
    return (false);
}

bool node_isClicked(node_t *node, sfRenderWindow *window)
{
    if (node_isHover(node, window) && sfMouse_isButtonPressed(sfMouseLeft))
        return (true);
    return (false);
}
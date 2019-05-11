/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** graph_draw_tools
*/

#include "graphs.h"

void sfRenderWindow_drawLine(sfRenderWindow *window, sfVector2f pos1, sfVector2f pos2)
{
    sfRectangleShape *line = sfRectangleShape_create();
    pos1 = (sfVector2f){pos1.x + NODE_SIZE / 2, pos1.y + NODE_SIZE / 2};
    pos2 = (sfVector2f){pos2.x + NODE_SIZE / 2, pos2.y + NODE_SIZE / 2};
    int len = sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2));
    double angle = atan((pos2.y - pos1.y) / (pos2.x - pos1.y));

    angle = (angle * 180.0) / 3.14;
    if (pos2.x < pos1.x)
        angle += 180;
    sfRectangleShape_setSize(line, (sfVector2f){len, 10});
    sfRectangleShape_setOrigin(line, (sfVector2f){0, 5});
    sfRectangleShape_setPosition(line, pos1);
    sfRectangleShape_setRotation(line, angle);
    sfRenderWindow_drawRectangleShape(window, line, NULL);
    sfRectangleShape_destroy(line);
}
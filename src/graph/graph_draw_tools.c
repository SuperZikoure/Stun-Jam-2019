#include "graphs.h"
#define M_PI       3.14159265358979323846
#define DEG(c) (c * (180/M_PI))

void sfRenderWindow_drawLine(sfRenderWindow *window, sfVector2f pos1, sfVector2f pos2)
{
    sfRectangleShape *line = sfRectangleShape_create();
    pos1 = (sfVector2f){pos1.x + NODE_SIZE / 2, pos1.y + NODE_SIZE / 2};
    pos2 = (sfVector2f){pos2.x + NODE_SIZE / 2, pos2.y + NODE_SIZE / 2};
    int len = sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2));

    float angle = 90 - DEG(atan2(pos2.x - pos1.x, pos2.y - pos1.y));
    sfRectangleShape_setSize(line, (sfVector2f){len, 6});
    sfRectangleShape_setOrigin(line, (sfVector2f){0, 3});
    sfRectangleShape_setPosition(line, pos1);
    sfRectangleShape_setRotation(line, angle);
    sfRenderWindow_drawRectangleShape(window, line, NULL);
    sfRectangleShape_destroy(line);
}
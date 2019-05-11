/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** fetch_anim.c
*/

#include <stdlib.h>
#include <math.h>
#include "game.h"

static anim_t **fetch_anim(int flag, window_t *window)
{
    static anim_t **anims = NULL;

    if (flag != 0)
        return anims;
    anims = malloc(sizeof(anim_t) * ANIM_AMOUNT);
    if (!anims)
        return NULL;
    for (int i = 0; i < ANIM_AMOUNT; i++) {
        anims[i] = F_ANIM(i);
        if (!anims[i])
            return NULL;
    }
    return anims;
}

int fill_anim(window_t *window)
{
    if (!fetch_anim(0, window))
        return -1;
    return 0;
}

void update_fetch_anim(void)
{
    anim_t *tmp = NULL;

    for (int i = 0; i < ANIM_AMOUNT; i++) {
        tmp = get_anim(i);
        update_anim(tmp);
    }
}

anim_t *get_anim(int index)
{
    return (fetch_anim(-1, NULL)[index]);
}

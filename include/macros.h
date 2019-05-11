/*
** EPITECH PROJECT, 2019
** STUN FEST JAM
** File description:
** macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#include <SFML/Graphics.h>

/* SFML */
#define V2F(x, y) (sfVector2f){x, y}
#define V2I(x, y) (sfVector2i){x, y}
#define V2U(x, y) (sfVector2u){x, y}
#define V3F(x, y, z) (sfVector3f){x, y, z}
#define COLOR(r, g, b, a) (sfColor){r, g, b, a}
#define IRECT(l, t, w, h) (sfIntRect){l, t, w, h}


#define DESTROY_SPRITE_TEXTURE(s) \
            sfTexture_destroy((sfTexture *) sfSprite_getTexture(s));
#define DESTROY_TEXT_FONT(t) sfFont_destroy((sfFont *) sfText_getFont(t))

#define GET_MUSIC_PATHS(i) music_paths[i].main_path, music_paths[i].cover_path

/* MATHS */
#define DEG(c) (c * (180 / M_PI))
#define ABS(a) ((a < 0) ? -a : a)
#define CAM(a, b, c) ((c * a + b) / (c + 1))

#endif /* !MACROS_H_ */

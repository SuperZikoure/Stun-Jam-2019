#ifndef MACROS_H_
#define MACROS_H_

#include <SFML/Graphics.h>
#include "my_str.h"

/* STR */
#define IS_LOWER(c) (c >= 'a' && c <= 'z')
#define IS_UPPER(c) (c >= 'A' && c <= 'Z')
#define IS_NUMBER(c) (c >= '0' && c <= '9')
#define IS_ALPHA(c) (IS_LOWER(c) || IS_UPPER(c) || IS_NUMBER(c))

/* SFML */
#define V2F(x, y) (sfVector2f){x, y}
#define V2I(x, y) (sfVector2i){x, y}
#define V2U(x, y) (sfVector2u){x, y}
#define V3F(x, y, z) (sfVector3f){x, y, z}
#define COLOR(r, g, b, a) (sfColor){r, g, b, a}
#define IRECT(l, t, w, h) (sfIntRect){l, t, w, h}

#define STR_EQ(s1, s2) (!my_strcmp(s1, s2))

#define DESTROY_SPRITE_TEXTURE(s) \
            sfTexture_destroy((sfTexture *) sfSprite_getTexture(s));
#define DESTROY_TEXT_FONT(t) sfFont_destroy((sfFont *) sfText_getFont(t))

#define GET_MUSIC_PATHS(i) music_paths[i].main_path, music_paths[i].cover_path

/* MATHS */
#define DEG(c) (c * (180 / M_PI))
#define ABS(a) ((a < 0) ? -a : a)
#define CAM(a, b, c) ((c * a + b) / (c + 1))

#endif /* !MACROS_H_ */

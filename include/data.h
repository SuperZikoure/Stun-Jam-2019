/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** game
*/

#ifndef DATA_H_
#define DATA_H_

#include "assets.h"
#include "graphs.h"
#include "graph.h"
#include <stdbool.h>
#include <stdlib.h>

#define ANIM(i) anim_info[i]
#define F_ANIM(i) create_anim(ANIM(i).fps, ANIM(i).size, ANIM(i).path, window)

typedef struct game_s game_t;
typedef struct info_anim_s info_anim_t;
typedef int (*scene_swap_t)(game_t *);

#define DELETE -1
#define SCREENSHOT_FILENAME_MAX 10

struct info_anim_s
{
    sfVector2f fps;
    sfVector2i size;
    char *path;
};

enum enum_scene_e {
    MAIN_MENU,
    GAME,
    PAUSE,
    WIN,
    CREDITS,
    SCENE_NB
};

enum enum_text_e
{
    TEXT1,
    TEXT_AMOUNT
};

enum enum_sound_e
{
    SOUND1,
    SOUND_AMOUNT
};


enum enum_music_e
{
    MUSIC1,
    MUSIC_AMOUNT
};

enum enum_images_e {
    IMAGE_1,
    IMAGE_AMOUNT
};

enum enum_anims_e {
    ANIM_1,
    ANIM_AMOUNT
};

extern const char *image_path[IMAGE_AMOUNT];
extern const info_anim_t anim_info[ANIM_AMOUNT];
extern const char* font_path[TEXT_AMOUNT];
extern const char* music_path[MUSIC_AMOUNT];
extern const char* sound_path[SOUND_AMOUNT];
extern const int font_size[TEXT_AMOUNT];

#endif /* !DATA_H_ */

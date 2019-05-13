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
typedef struct info_button_s info_button_t;

#define DELETE -1
#define SCREENSHOT_FILENAME_MAX 10
#define BUTTON_PATH ("assets/buttons/")
#define BUTTON_AMOUNT 12

#define SCREEN_POS V2F(912, 404)
#define TV_POS V2F(768, 328)

#define FRAMES_TV 120

struct info_anim_s
{
    sfVector2f fps;
    sfVector2i size;
    char *path;
};

enum enum_scene_e {
    MAIN_MENU,
    HOW_TO_PLAY,
    GAME,
    PAUSE,
    WIN,
    CREDITS,
    SCENE_NB
};

struct info_button_s
{
    sfVector2f pos;
    int option;
    enum enum_scene_e scene;
    char *path;
    int (*trigger)(game_t *, int);
};

enum enum_text_e
{
    TEXT,
    SMALL,
    VERY_SMALL,
    TEXT_AMOUNT
};

enum enum_sound_e
{
    CLICK_FX,
    SOUND_AMOUNT
};


enum enum_music_e
{
    MENU_MUSIC,
    MUSIC_AMOUNT
};

enum enum_images_e {
    MENU_BG,
    GAME_BG,
    BLACK_BG,
    TV_BG,
    DEF_1,
    DEF_2,
    DEF_3,
    BOOST_1,
    BOOST_2,
    BOOST_3,
    ON_AIR,
    IMAGE_AMOUNT
};

enum enum_anims_e {
    CHANGE_CHANNEL,
    CHAN_1,
    CHAN_2,
    AD_1,
    AD_2,
    ANIM_AMOUNT
};

extern const info_button_t info[BUTTON_AMOUNT];
extern const char *image_path[IMAGE_AMOUNT];
extern const info_anim_t anim_info[ANIM_AMOUNT];
extern const char* font_path[TEXT_AMOUNT];
extern const char* music_path[MUSIC_AMOUNT];
extern const char* sound_path[SOUND_AMOUNT];
extern const int font_size[TEXT_AMOUNT];

typedef struct button_s
{
    int (*trigger)(game_t *, int);
    int option;
    char *name;
    image_t *base;
    image_t *hover;
    image_t *click;
    image_t *display;
    sound_t *click_sound;
    sfVector2f pos;
    sfVector2f display_pos;
    enum enum_scene_e scene;
    int mouse_hover;
    int mouse_click;
} button_t;

#endif /* !DATA_H_ */

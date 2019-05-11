#include "game.h"

const scene_swap_t scenes[SCENE_NB] = {
    manage_menu,
    manage_htp,
    manage_game,
    manage_pause,
    manage_win,
    manage_credits
};

static enum enum_scene_e fetch_scene_id(enum enum_scene_e flag)
{
    static enum enum_scene_e id = 0;

    if (flag != SCENE_NB) {
        id = flag;
        return 0;
    }
    return id;
}

int (*get_scene(void))(game_t *)
{
    return scenes[fetch_scene_id(SCENE_NB)];
}

enum enum_scene_e get_scene_id(void)
{
    return fetch_scene_id(SCENE_NB);
}

void change_scene(enum enum_scene_e id)
{
    fetch_scene_id(id);
}

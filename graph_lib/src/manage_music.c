#include <stdlib.h>
#include "graph.h"

static sfMusic *quick_music_create(const char *path, float vol)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (!music)
        return NULL;
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, vol);
    return music;
}

music_t *load_music(const char *main_path)
{
    music_t *music = malloc(sizeof(music_t));

    if (!music)
        return NULL;
    music->main = quick_music_create(main_path, BASE_VOLUME);
    if (!music->main)
        return NULL;
    return music;
}

void start_music(music_t *music)
{
    sfMusic_play(music->main);
}

void destroy_music(music_t *music)
{
    sfMusic_destroy(music->main);
    free(music);
}

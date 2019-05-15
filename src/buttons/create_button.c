#include <stdlib.h>
#include "game.h"
#include "my_str.h"

static int setup_button_images(button_t *button, char *path, window_t *window)
{
    button->base = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_0.png")), window);
    button->hover = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_1.png")), window);
    button->click = create_image(my_strcat_no_free(BUTTON_PATH,
my_strcat_no_free(path, "_2.png")), window);
    if (!button->base || !button->hover || !button->click)
        return -1;
    return 0;
}

button_t *create_button(const info_button_t *info, window_t *window)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button || setup_button_images(button, info->path, window) == -1)
        return NULL;
    button->scene = info->scene;
    button->display = button->base;
    button->trigger = info->trigger;
    button->click_sound = create_sound("assets/sounds/click.wav");
    if (!button->click_sound)
        return NULL;
    button->mouse_hover = 0;
    button->mouse_click = 0;
    button->option = info->option;
    button->pos = V2F(info->pos.x, info->pos.y);
    button->name = info->path;
    return (button);
}

#include "game.h"

void update_menu(game_t *game)
{

}

void display_menu(game_t *game)
{
    display_image(get_image(MENU_BG), V2F(0, 0));
    show_scene_buttons(game);
}

int manage_menu(game_t *game)
{
    update_menu(game);
    display_menu(game);
    return (0);
}
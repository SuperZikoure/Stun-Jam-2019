#include "game.h"

void update_credits(game_t *game)
{

}

void display_credits(game_t *game)
{
    display_image(get_image(MENU_BG), V2F(0, 0));
    display_text("Made for the StunJam 2019.", V2F(50, 400), game->texts[TEXT]);
    display_text("Thank you for playing!", V2F(50, 450), game->texts[TEXT]);
    display_text("By : Guilian Ganster (Zoraneus)", V2F(50, 525), game->texts[SMALL]);
    display_text("     Ghassane SEBAI (SuperZikoure)", V2F(50, 550), game->texts[SMALL]);
    display_text("Music and Art by Ghassane SEBAI.", V2F(50, 600), game->texts[SMALL]);
}

int manage_credits(game_t *game)
{
    update_credits(game);
    display_credits(game);
    return (0);
}
#include "game.h"

void update_htp(game_t *game)
{

}

void display_htp(game_t *game)
{
    static int flicker = 60;

    display_image(get_image(BLACK_BG), V2F(0, 0));
    display_text("HELP :", V2F(50, 50), game->texts[TEXT]);
    display_text("TVLink is a turn-based strategy game.", V2F(50, 150), game->texts[SMALL]);
    display_text("You will be playing as an ad company CEO. Your goal is to make money and beat your opponent.", V2F(50, 175), game->texts[SMALL]);
    display_text("To do so, you can buy time-slots for your ads on different TV channels.", V2F(50, 225), game->texts[SMALL]);
    display_text("Your ads will generate revenue every turn. The more slots you possess, the more money you make.", V2F(50, 250), game->texts[SMALL]);
    display_text("Turns last 30 seconds, you will have to think fast.", V2F(50, 275), game->texts[SMALL]);
    display_text("Every turn, you can :\n\n    - Control one additionnal time slot.\n    - Buy and use skills.", V2F(50, 325), game->texts[SMALL]);
    display_text("Skills are useful to boost your profit or slow down your opponent. But they cost money.", V2F(50, 425), game->texts[SMALL]);
    display_text("There is a channel marked as \"on air\". It generates more profit, but it will change location every few turns.", V2F(50, 450), game->texts[SMALL]);
    display_text("You win if you either reach 300$ or manage\nto steal all of your opponent's slots.", V2F(50, 500), game->texts[SMALL]);
    if (flicker <= 45)
        display_text("Press escape to go back to the Main Menu.", V2F(50, 600), game->texts[TEXT]);

    flicker -= get_delta();
    if (flicker <= 0)
        flicker = 60;
}

int manage_htp(game_t *game)
{
    update_htp(game);
    display_htp(game);
    return (0);
}
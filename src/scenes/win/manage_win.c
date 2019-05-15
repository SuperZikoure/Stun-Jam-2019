#include "game.h"

void update_win(game_t *game)
{

}

void display_win(game_t *game)
{
    display_image(get_image(BLACK_BG), V2F(0, 0));
    if (game->win == PLAYER1)
        display_text("Player 1 won the game.", V2F(425, 200), game->texts[TEXT]);
    else if (game->win == PLAYER2)
        display_text("Player 2 won the game.", V2F(425, 200), game->texts[TEXT]);
}

int manage_win(game_t *game)
{
    update_win(game);
    display_win(game);
    return (0);
}
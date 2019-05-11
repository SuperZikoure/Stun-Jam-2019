#include "game.h"

int exit_game(game_t *game, int a __attribute__((unused)))
{
    game->exit = 1;
    return (0);
}
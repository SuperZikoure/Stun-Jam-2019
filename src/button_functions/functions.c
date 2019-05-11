#include "game.h"

int exit_game(game_t *game, int a)
{
    game->exit = 1;
    return (0);
}

int put_scene(game_t *game, int a)
{
    change_scene(a);
    return (0);
}
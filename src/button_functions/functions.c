#include "game.h"

#define MONEY game->players[game->turn + 1].money

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

int change_sound(game_t *game, int a)
{
    game->sound = (game->sound) ? 0 : 1;
    return (0);
}

int buy_skill(game_t *game, int a)
{
    int prices[3] = {5, 10, 15};

    if (MONEY >= prices[a]) {
        MONEY -= prices[a];
        game->players[game->turn + 1].skills[a] += 1;
    }
    return (0);
}
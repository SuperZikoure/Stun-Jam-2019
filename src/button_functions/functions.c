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
    if (a == GAME)
        game->timer = TIMER_START;
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

int end_turn(game_t *game, int a)
{
    game->timer = 0;
    return 0;
}

int use_skill(game_t *game, int a)
{
    if (game->players[game->turn + 1].skills[a] > 0 && game->graph->skill != NULL && a == 1 && game->graph->skill->owner != NEUTRAL) {
        game->players[game->turn + 1].skills[a] -= 1;
        if (game->graph->skill->defense)
            game->graph->skill->defense -= 1;
        else
            game->graph->skill->owner = NEUTRAL;
    }
    if (game->players[game->turn + 1].skills[a] > 0 && game->graph->skill != NULL && a == 0 && game->graph->skill->defense < 3) {
        game->players[game->turn + 1].skills[a] -= 1;
        game->graph->skill->defense += 1;
    }
    if (game->players[game->turn + 1].skills[a] > 0 && game->graph->skill != NULL && a == 2 && game->graph->skill->boost < 3) {
        game->players[game->turn + 1].skills[a] -= 1;
        game->graph->skill->boost += 1;
    }
    return 0;
}
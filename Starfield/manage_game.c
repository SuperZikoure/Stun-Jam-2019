#include <stdlib.h>
#include "game.h"
#include "my_str.h"

static int get_money(game_t *game)
{
    int money = 0;
    link_t *current = game->graph->nodes->start;
    node_t *current_content = (node_t*)current->content;

    while (current) {
        current_content = (node_t*)current->content;
        if (current_content->owner == game->turn + 1)
            money += 4 * (current_content->boost + 1);
        current = current->next;
    }
    if (game->graph->stream != NULL && game->graph->stream->owner == game->turn + 1) {
        money += 2 * (4 * (current_content->boost + 1));
    }
    return money;
}

void change_stream(game_t *game)
{
    int random = rand() % NB_NODE;
    link_t *current = game->graph->nodes->start;
    node_t *current_content;

    for (int i = 0; i < random; i++) {
        current = current->next;
    }
        current_content = (node_t*)current->content;
    game->graph->stream = current_content;
    game->change = FRAMES_TV;
    get_anim(CHANGE_CHANNEL)->img = 0;
}


void update_game(game_t *game)
{
    static int timer_frames = 0;

    graph_event_clicked(game->graph, game->window->window);
    if (game->space_pressed && !game->game_state) {
        game->game_state = 1;
        game->timer = 1860;
    }
    if (game->timer - get_delta() >= 0)
        game->timer -= get_delta();
    if ((game->timer <= 0 || game->timer <= get_delta()) && game->game_state) {
        game->game_state = 0;
        game->players[game->turn + 1].money += get_money(game);
        game->turn = (game->turn == 1) ? 0 : 1;
        game->players[game->turn + 1].can_buy = 1;
        if ((rand() % 3) == 1)
            change_stream(game);
    }
    if (game->game_state) {
        if (game->graph->selected != NULL && game->players[game->turn + 1].can_buy && game->graph->selected->owner == NEUTRAL) {
            game->graph->selected->owner = game->turn + 1;
            game->players[game->turn + 1].can_buy = 0;
            game->graph->selected = NULL;
        }
    }
    if (!game->players[game->turn + 1].can_buy)
        game->graph->selected = NULL;
    if (!game->game_state) {
        game->graph->selected = NULL;
        game->graph->skill = NULL;
    }
    if (game->game_state)
        game->change -= (game->change > 0) ? get_delta() : 0;
    if (game->players[game->turn + 1].money >= 400) {
        change_scene(WIN);
    }
}

void display_skills(game_t *game) {
    display_text("Place a firewall on a channel to protect it \nfrom one attack.", V2F(800, 95), game->texts[VERY_SMALL]);
    display_text("Amount : ", V2F(800, 119), game->texts[VERY_SMALL]);
    display_text("Price : 5 $", V2F(800, 131), game->texts[VERY_SMALL]);
    display_text(my_itoa(game->players[game->turn + 1].skills[0]), V2F(850, 119), game->texts[VERY_SMALL]);
    display_text("Attack one of your opponent's channels.", V2F(800, 172), game->texts[VERY_SMALL]);
    display_text("Amount : ", V2F(800, 184), game->texts[VERY_SMALL]);
    display_text("Price : 10 $", V2F(800, 196), game->texts[VERY_SMALL]);
    display_text(my_itoa(game->players[game->turn + 1].skills[1]), V2F(850, 184), game->texts[VERY_SMALL]);
    display_text("Boost one of your channels to generate more \nmoney overtime.", V2F(800, 248), game->texts[VERY_SMALL]);
    display_text("Amount : ", V2F(800, 272), game->texts[VERY_SMALL]);
    display_text("Price : 15 $", V2F(800, 284), game->texts[VERY_SMALL]);
    display_text(my_itoa(game->players[game->turn + 1].skills[2]), V2F(850, 272), game->texts[VERY_SMALL]);

}

void display_game(game_t *game)
{
    if (game->game_state) {
        display_image(get_image(BLACK_BG), V2F(0, 0));
        display_image(get_image(GAME_BG), V2F(0, 0));
        display_image(get_image(TV_BG), TV_POS);
        display_anim(get_anim(CHAN_1 + game->turn), SCREEN_POS);
        if (game->graph->stream != NULL && game->graph->stream->owner == 1 && game->change < 60)
            display_anim(get_anim(AD_1), SCREEN_POS);
        if (game->graph->stream != NULL && game->graph->stream->owner == 2 && game->change < 60)
            display_anim(get_anim(AD_2), SCREEN_POS);
        if (game->change > 0)
            display_anim(get_anim(CHANGE_CHANNEL), TV_POS);
        display_skills(game);
        display_text(my_itoa(game->timer / 60), V2F(1050, 15), game->texts[SMALL]);
        display_text(my_itoa(game->players[game->turn + 1].money), V2F(1200, 15), game->texts[SMALL]);
        sfRenderWindow_drawGraph(game->window->window, game->graph, game);
        show_scene_buttons(game);
    } else {
        display_text("Press Space to start your turn", V2F(350, 200), game->texts[TEXT]);
        display_text("Player", V2F(550, 300), game->texts[TEXT]);
        display_text(my_itoa(game->turn + 1), V2F(675, 300), game->texts[TEXT]);
    }
}

int manage_game(game_t *game)
{
    update_game(game);
    display_game(game);
    return (0);
}
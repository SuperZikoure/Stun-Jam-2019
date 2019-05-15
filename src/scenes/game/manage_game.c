#include <stdlib.h>
#include "game.h"
#include "my_str.h"

static void check_win(game_t *game)
{
    link_t *current = game->graph->nodes->start;
    node_t *current_content;
    int nb1 = 0;
    int nb2 = 0;

    while (current) {
        current_content = (node_t*)current->content;
        if (current_content->owner == PLAYER1)
            nb1++;
        else if (current_content->owner == PLAYER2)
            nb2++;
        current = current->next;
    }
    if (nb1 == 0) {
        game->win = PLAYER2;
        change_scene(WIN);
    } else if (nb2 == 0) {
        game->win = PLAYER1;
        change_scene(WIN);
    }
    if (game->players[PLAYER1].money >= WIN_MONEY) {
        game->win = PLAYER1;
        change_scene(WIN);
    } else if (game->players[PLAYER1].money >= WIN_MONEY) {
        game->win = PLAYER2;
        change_scene(WIN);
    }
}

static int get_money(game_t *game)
{
    int money = 0;
    link_t *current = game->graph->nodes->start;
    node_t *current_content;

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
    graph_event_clicked(game->graph, game->window->window, game);
    if (game->space_pressed && game->game_state == 0) {
        game->game_state = 2;
        game->countdown = COUNTDOWN_START;
        game->timer = TIMER_START;
        if (game->sound)
            sfSound_play(game->sounds[CHRONO_FX]->sound);
        set_music(game, -1);
    }
    if (game->game_state == 1 && (int)(game->timer - get_delta()) >= 0)
        game->timer -= get_delta();
    if ((game->timer <= 0 || game->timer <= (int)get_delta()) && game->game_state == 1) {
        game->game_state = 0;
        set_music(game, PAUSE_MUSIC);
        game->players[game->turn + 1].money += get_money(game);
        game->turn = (game->turn == 1) ? 0 : 1;
        game->players[game->turn + 1].can_buy = 1;
        if ((rand() % 3) == 1)
            change_stream(game);
    }
    if (game->game_state == 1) {
        if (game->graph->selected != NULL && game->players[game->turn + 1].can_buy && game->graph->selected->owner == NEUTRAL) {
            game->graph->selected->owner = game->turn + 1;
            game->players[game->turn + 1].can_buy = 0;
            game->graph->selected = NULL;
        }
    }
    if (!game->players[game->turn + 1].can_buy)
        game->graph->selected = NULL;
    if (game->game_state == 0) {
        game->graph->selected = NULL;
        game->graph->skill = NULL;
    }
    if (game->game_state == 1)
        game->change -= (game->change > 0) ? get_delta() : 0;
    if (game->game_state == 2 && (int)(game->countdown - get_delta()) >= 0) {
        game->countdown -= get_delta();
    }
    if (game->game_state == 2 && game->countdown <= 0) {
        game->game_state = 1;
        set_music(game, GAME_1_MUSIC + rand() % 4);
    }
    if (game->game_state == 0)
        set_music(game, PAUSE_MUSIC);
    check_win(game);
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
    if (game->game_state == 1) {
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
        display_text(my_itoa((game->timer) / 60), V2F(1050, 15), game->texts[SMALL]);
        display_text(my_itoa(game->players[game->turn + 1].money), V2F(1200, 15), game->texts[SMALL]);
        sfRenderWindow_drawGraph(game->window->window, game->graph, game);
        show_scene_buttons(game);
    } else if (game->game_state == 0) {
        display_text("Press Space to start your turn", V2F(350, 200), game->texts[TEXT]);
        display_text("Player", V2F(550, 300), game->texts[TEXT]);
        display_text(my_itoa(game->turn + 1), V2F(675, 300), game->texts[TEXT]);
    } else if (game->game_state == 2) {
        if ((game->countdown / 38) > 0)
            display_text(my_itoa((game->countdown / 38)), V2F(626, 330), game->texts[TEXT]);
        else
            display_text("Get Ready !", V2F(565, 330), game->texts[TEXT]);
    }
}

int manage_game(game_t *game)
{
    update_game(game);
    display_game(game);
    return (0);
}
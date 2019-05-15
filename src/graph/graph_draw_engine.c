#include "game.h"
#include "graphs.h"

int can_be_drawn(node_t *node, game_t *game)
{
    link_t *current = node->links->start;
    node_t *current_content;

    if (node->owner == game->turn + 1)
        return 1;
    while (current) {
        current_content = (node_t*)current->content;
        if (current_content->owner == game->turn + 1)
            return 1;
        current = current->next;
    }
    return 0;
}

void sfRenderWindow_drawGraph(sfRenderWindow *window, graph_t *graph, game_t *game)
{
    link_t *current = graph->nodes->start;
    node_t *current_content;

    while (current) {
        current_content = (node_t*)current->content;
        if (current_content->owner == game->turn + 1)
            sfRenderWindow_drawNodelink(window, current_content);
        current = current->next;
    }
    current = graph->nodes->start;
    while (current) {
        current_content = (node_t*)current->content;
        if ((current_content->owner == game->turn + 1 || can_be_drawn(current_content, game))) {
            sfRenderWindow_drawNode(window, current_content, game);
            if (current_content->defense)
                display_image(get_image(DEF_1 + (current_content->defense - 1)), current_content->pos);
        if (current_content->boost)
                display_image(get_image(BOOST_1 + (current_content->boost) - 1), current_content->pos);
        }
        current = current->next;
    }
    if (graph->selected != NULL) {
        sfSprite *to_draw = graph->selected->sprites[graph->selected->owner][CLICKED];
        sfSprite_setPosition(to_draw, graph->selected->pos);
        if (graph->selected->owner == game->turn + 1 || can_be_drawn(graph->selected, game))
            sfRenderWindow_drawSprite(window, to_draw, NULL);
        graph->selected = NULL;
    }
    if (graph->skill != NULL) {
        sfSprite *to_draw = graph->skill->sprites[graph->skill->owner][CLICKED];
        sfSprite_setPosition(to_draw, graph->skill->pos);
        if (can_be_drawn(graph->skill, game))
            sfRenderWindow_drawSprite(window, to_draw, NULL);
    }
    if (graph->stream != NULL) {
        if (can_be_drawn(graph->stream, game))
            display_image(get_image(ON_AIR), V2F(graph->stream->pos.x + 32, graph->stream->pos.y + 34));
    }
}
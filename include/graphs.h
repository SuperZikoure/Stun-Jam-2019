#ifndef GRAPHS_H_
#define GRAPHS_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "my_vector.h"
#include "assets.h"

typedef struct game_s game_t;

#define NODE_SIZE 36

struct node {
    int id;
    vector_t *links;
    sfVector2f pos;
    int owner;
    int defense;
    int boost;
    sfSprite *sprites[3][3];
};
typedef struct node node_t;

struct graph {
    vector_t *nodes;
    node_t *selected;
    node_t *skill;
    node_t *stream;
};
typedef struct graph graph_t;

// graph.c
graph_t *graph_create(void);
void graph_destroy(graph_t *graph);

// graph_operation.c
node_t *graph_get_node_by_id(graph_t *graph, int id);

// graph_event.c
void graph_event_clicked(graph_t *graph, sfRenderWindow *window, game_t *game);

// node.c
node_t *node_create(int x, int y, assets_t *assets);
void sfRenderWindow_drawNode(sfRenderWindow *window, node_t *node, game_t *game);
void sfRenderWindow_drawNodelink(sfRenderWindow *window, node_t *node);
void node_destroy(node_t *node);

// node_operation.c
void node_create_link(node_t *node1, node_t *node2);
void node_create_link_from_id(graph_t *graph, int node1, int node2);

// node_event.c
bool node_isHover(node_t *node, sfRenderWindow *window, game_t *game);
bool node_isClicked(node_t *node, sfRenderWindow *window, game_t *game);

// graph_draw_tools.c
void sfRenderWindow_drawLine(sfRenderWindow *window, sfVector2f pos1, sfVector2f pos2);

#endif /* !GRAPHS_H_ */

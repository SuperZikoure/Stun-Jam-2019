/*
** EPITECH PROJECT, 2019
** Stun-Jam-2019
** File description:
** graphs
*/

#ifndef GRAPHS_H_
#define GRAPHS_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_vector.h"

enum owner {NEUTRAL, PLAYER1, PLAYER2};

struct node {
    vector_t *links;
    int owner;
    int defense;
    int attack;
};
typedef struct node node_t;

struct graph {
    vector_t *nodes;
};
typedef struct graph graph_t;

// graph.c
graph_t *graph_create(void);
void graph_destroy(graph_t *graph);

// node.c
node_t *node_create(void);
void node_destroy(node_t *node);

#endif /* !GRAPHS_H_ */

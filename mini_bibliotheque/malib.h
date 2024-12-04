//
// Created by Thomas on 24/09/2024.
//


#ifndef MALIB_H
#define MALIB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    char character;
    struct node_s* next;
}node_s;


void display_all(node_s * p_head);
int add_node(node_s ** p_head, char character);
int add_node_tail(node_s * head, unsigned char character);
int delete_node(node_s ** p_head);
int delete_node_tail( node_s **p_head);
int get_node( node_s *head, unsigned char character, node_s **p_node_get);

#endif //MALIB_H

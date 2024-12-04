//
// Created by Thomas on 26/09/2024.
//

#ifndef MALIB_H
#define MALIB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct list_s {
    char title[21];
    char description[101];
    int start_time;
    int duration;
    struct list_s *next;
}list_s;

int add_node(struct list_s **head, char *titre, char *description, int start_time, int duration);
int add_node_tail(struct list_s **p_head, char *title, char *description, int start_time, int duration);
int delete_node(struct list_s ** p_head);
int delete_node_tail(struct list_s **p_head);
int get_node(struct list_s *head, int start_time, struct list_s **p_node_get);
void display_all(struct list_s * p_head);

#endif //MALIB_H

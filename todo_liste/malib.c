#include "malib.h"

#include <string.h>


int add_node(list_s **p_head, char *title, char *description, int start_time, int duration) {

    if (p_head == NULL) {
        return -1;
    }

    if (start_time < 0 || start_time > 2359 || (start_time % 100) >= 60) {
        return -1;
    }

    if (duration < 0 || duration > 2359 || (duration % 100) >= 60) {
        return -1;
    }

    list_s* new_node = malloc(sizeof(struct list_s));
    if (new_node == NULL) {
        return -1;
    }

    strncpy(new_node->title, title, 20);
    new_node->title[20] = '\0';

    strncpy(new_node->description, description, 100);
    new_node->description[100] = '\0';

    new_node->start_time = start_time;
    new_node->duration = duration;

    new_node->next = *p_head;
    *p_head = new_node;
    return 0;
}

int add_node_tail(list_s **p_head, char *title, char *description, int start_time, int duration) {

    if (p_head == NULL) {
        return -1;
    }

    if (title == NULL || description == NULL) {
        return -1;
    }

    if (start_time < 0 || start_time > 2359 || (start_time % 100) >= 60) {
        return -1;
    }

    if (duration < 0 || duration > 2359 || (duration % 100) >= 60) {
        return -1;
    }

    list_s* new_node = malloc(sizeof(struct list_s));
    if (new_node == NULL) {
        return -1;
    }

    strncpy(new_node->title, title, 20);
    new_node->title[20] = '\0';

    strncpy(new_node->description, description, 100);
    new_node->description[100] = '\0';

    new_node->start_time = start_time;
    new_node->duration = duration;
    new_node->next = NULL;

    if (*p_head == NULL) {
        *p_head = new_node;
        return 0;
    }

    list_s *current = *p_head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return 0;
}


int delete_node(list_s ** p_head) {

    list_s * next_node = NULL;

    if (p_head == NULL || *p_head == NULL) {
        return -1;
    }

    next_node = (*p_head)->next;
    free(*p_head);
    *p_head = next_node;
    return 0;
}


int delete_node_tail(list_s **p_head) {
    if (p_head == NULL || *p_head == NULL) {
        return -1;
    }

    if ((*p_head)->next == NULL) {
        free(*p_head);
        *p_head = NULL;
        return 0;
    }

    list_s * current = *p_head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return 0;
}


int get_node(list_s *head, int start_time, list_s **p_node_get) {

    if (p_node_get == NULL) {
        return -1;
    }

    if (head == NULL) {
        *p_node_get = NULL;
        return -1;
    }

    list_s *current = head;

    while (current != NULL) {
        if (current->start_time == start_time) {
            *p_node_get = current;
            return 0;
        }
        current = current->next;
    }

    *p_node_get = NULL;
    return -1;
}


void display_all(list_s * p_head) {
    list_s* current = p_head;

    while (current != NULL) {
        printf("Titre :%s\n", current->title);
        printf("Description :%s\n", current->description);
        printf("Start time : %02d:%02d\n", current->start_time / 100, current->start_time % 100);
        printf("Duration : %02d:%02d\n", current->duration / 100, current->duration % 100);
        printf("-----------------------------\n");
        current = current->next;
    }
}

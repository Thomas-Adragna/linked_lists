
#include "malib.h"

void display_all(node_s * p_head) {
    node_s* current = p_head;

    while (current != NULL) {
        printf("%c -> ", current->character);
        current = current->next;
    }
    printf("\n");
}


int add_node(node_s ** p_head, char character) {

    if (*p_head == NULL) {
        return -1;
    }

    node_s* new_node = (node_s *) malloc(sizeof(node_s));
    if (new_node == NULL) {
        return -1;
    }

    new_node->character = character;
    new_node->next = (*p_head);
    (*p_head) = new_node;

    return 0;
}


int add_node_tail(node_s * head, unsigned char character) {

    if (head == NULL) {
        return -1;
    }

    node_s * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(node_s));
    if (current->next == NULL) {
        return -1;
    }

    current->next->character = character;
    current->next->next = NULL;

    return 0;
}


int delete_node(node_s ** p_head) {

    node_s * next_node = NULL;

    if (p_head == NULL || *p_head == NULL) {
        return -1;
    }

    next_node = (*p_head)->next;
    int character = (*p_head)->character;

    free(*p_head);
    *p_head = next_node;

    return character;
}

int delete_node_tail( node_s **p_head) {
    if (p_head == NULL || *p_head == NULL) {
        return -1;
    }

    if ((*p_head)->next == NULL) {
        free(*p_head);
        *p_head = NULL;
        return 0;
    }

    node_s * current = *p_head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return 0;
}


int get_node( node_s *head, unsigned char character, node_s **p_node_get) {

    if (p_node_get == NULL) {
        return -1;
    }

    node_s *current = head;

    while (current != NULL) {
        if (current->character == character) {
            *p_node_get = current;
            return 0;
        }
        current = current->next;
    }

    *p_node_get = NULL;
    return -1;
}

//
// Created by Thomas on 02/10/2024.
//

#include "tests.h"
#include <assert.h>
#include <stdio.h>


int main() {
    printf("Running tests for Project 1...\n");

    test_add_node();
    test_add_node_tail();
    test_delete_node();
    test_delete_node_tail();
    test_get_node();
    test_display_all();

    printf("All tests passed successfully.\n");
    return 0;
}

// Test function for add_node
void test_add_node() {
    printf("Testing add_node...\n");

    node_s* head = NULL;
    int result;

    result = add_node(&head, 'A');
    assert(result == 0);
    assert(head != NULL);
    assert(head->character == 'A');
    assert(head->next == NULL);

    result = add_node(&head, 'B');
    assert(result == 0);
    assert(head != NULL);
    assert(head->character == 'B');
    assert(head->next != NULL);
    assert(head->next->character == 'A');


    node_s* current = head;
    while (current != NULL) {
        node_s* temp = current;
        current = current->next;
        free(temp);
    }

    printf("add_node tests passed.\n");
}
//
// Created by Thomas on 02/10/2024.
//
#include "ma
lib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_add_node() {
    printf("Testing add_node...\n");

    list_s* head = NULL;
    int result;
*
    result = add_node(&head, "Task1", "Description1", 900, 100);
    assert(result == 0);
    assert(head != NULL);
    assert(strcmp(head->title, "Task1") == 0);
    assert(strcmp(head->description, "Description1") == 0);
    assert(head->start_time == 900);
    assert(head->duration == 100);
*
    result = add_node(&head, "Invalid Task", "Invalid start time", 2400, 100);
    assert(result == -1);
*
    list_s* current = head;
    while (current != NULL) {
        list_s* temp = current;
        current = current->next;
        free(temp);
    }

    printf("add_node tests passed.\n");
}

void test_add_node_tail() {
    printf("Testing add_node_tail...\n");

    list_s* head = NULL;
    int result;

    result = add_node_tail(&head, "Task1", "Description1", 900, 100);
    assert(result == 0);
    assert(head != NULL);
    assert(strcmp(head->title, "Task1") == 0);

    result = add_node_tail(&head, "Task2", "Description2", 1100, 200);
    assert(result == 0);
    assert(head->next != NULL);
    assert(strcmp(head->next->title, "Task2") == 0);

    list_s* current = head;
    while (current != NULL) {
        list_s* temp = current;
        current = current->next;
        free(temp);
    }

    printf("add_node_tail tests passed.\n");
}

// Test function for delete_node
void test_delete_node() {
    printf("Testing delete_node...\n");

    list_s* head = NULL;
    int result;

    // Test 1: Delete from empty lis
    result = delete_node(&head);
    assert(result == -1);

    add_node(&head, "Task1", "Description1", 900, 100);
    add_node(&head, "Task2", "Description2", 1100, 200);
    result = delete_node(&head); // Should remove 'Task2'
    assert(result == 0);
    assert(head != NULL);
    assert(strcmp(head->title, "Task1") == 0);

    // Clean up
    delete_node(&head); // Remove 'Task1'

    printf("delete_node tests passed.\n");
}
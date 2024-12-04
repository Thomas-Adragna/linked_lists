// tests.c

#include "lib_log.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

// Fonction de test pour initLogList
void test_initLogList() {
    printf("Test de initLogList...\n");
    LogList logList;
    initLogList(&logList);
    assert(logList.head == NULL);
    assert(logList.tail == NULL);
    assert(logList.size == 0);
    printf("initLogList fonctionne correctement.\n\n");
}

// Fonction de test pour createLogMessage
void test_createLogMessage() {
    printf("Test de createLogMessage...\n");
    const char* messageText = "Test de création de message";
    LogMessage* logMsg = createLogMessage(messageText);
    assert(logMsg != NULL);
    assert(strcmp(logMsg->message, messageText) == 0);
    assert(strlen(logMsg->timestamp) == 15);
    assert(logMsg->next == NULL);
    assert(logMsg->prev == NULL);
    free(logMsg);
    printf("createLogMessage fonctionne correctement.\n\n");
}

// Fonction de test pour addLogMessage
void test_addLogMessage() {
    printf("Test de addLogMessage...\n");
    LogList logList;
    initLogList(&logList);

    addLogMessage(&logList, "Message 1");
    assert(logList.size == 1);
    assert(logList.head == logList.tail);
    assert(strcmp(logList.head->message, "Message 1") == 0);

    addLogMessage(&logList, "Message 2");
    assert(logList.size == 2);
    assert(logList.head != logList.tail);
    assert(strcmp(logList.tail->message, "Message 2") == 0);
    assert(logList.head->next == logList.tail);
    assert(logList.tail->prev == logList.head);

    // Ajouter des messages jusqu'à dépasse la profondeur maximale
    for (int i = 3; i <= MAX_LOG_DEPTH + 2; i++) {
        char msg[20];
        sprintf(msg, "Message %d", i);
        addLogMessage(&logList, msg);
    }
    assert(logList.size == MAX_LOG_DEPTH);
    assert(strcmp(logList.tail->message, "Message 12") == 0);
    assert(strcmp(logList.head->message, "Message 3") == 0);

    clearLogList(&logList);
    printf("addLogMessage fonctionne correctement.\n\n");
}

// Fonction de test pour getCurrentTimestamp
void test_getCurrentTimestamp() {
    printf("Test de getCurrentTimestamp...\n");
    char timestamp[16];
    getCurrentTimestamp(timestamp, sizeof(timestamp));
    assert(strlen(timestamp) == 15); // Format yyyymmdd-hhmmss
    printf("Horodatage actuel : %s\n", timestamp);
    printf("getCurrentTimestamp fonctionne correctement.\n\n");
}

// fonction de test pour findLogMessageByTimestamp
void test_findLogMessageByTimestamp() {
    printf("Test de findLogMessageByTimestamp...\n");
    LogList logList;
    initLogList(&logList);

    addLogMessage(&logList, "Message pour la recherche");
    char timestampToFind[16];
    strcpy(timestampToFind, logList.tail->timestamp);

    LogMessage* foundMsg = findLogMessageByTimestamp(&logList, timestampToFind);
    assert(foundMsg != NULL);
    assert(strcmp(foundMsg->message, "Message pour la recherche") == 0);

    // Recherche avec un horodatage inexistant,
    foundMsg = findLogMessageByTimestamp(&logList, "20990101-000000");
    assert(foundMsg == NULL);

    clearLogList(&logList);
    printf("findLogMessageByTimestamp fonctionne correctement.\n\n");
}

// fonction de test pour clearLogList
void test_clearLogList() {
    printf("Test de clearLogList...\n");
    LogList logList;
    initLogList(&logList);

    addLogMessage(&logList, "Message à supprimer");
    assert(logList.size == 1);

    clearLogList(&logList);
    assert(logList.size == 0);
    assert(logList.head == NULL);
    assert(logList.tail == NULL);

    // Appeler clearLogList sur une liste qui est vide
    clearLogList(&logList); // Ne devrait pas causer d'erreur

    printf("clearLogList fonctionne correctement.\n\n");
}

// Fonction de test pour les fonction de navigation
void test_navigation_functions() {
    printf("Test des fonctions de navigation...\n");
    LogList logList;
    initLogList(&logList);

    addLogMessage(&logList, "Message 1");
    addLogMessage(&logList, "Message 2");
    addLogMessage(&logList, "Message 3");

    LogMessage* current = logList.head;
    assert(strcmp(current->message, "Message 1") == 0);

    // Test de get_next_node
    current = get_next_node(current);
    assert(strcmp(current->message, "Message 2") == 0);

    current = get_next_node(current);
    assert(strcmp(current->message, "Message 3") == 0);

    current = get_next_node(current);
    assert(current == NULL);

    // Test de get_previous_node
    current = logList.tail;
    assert(strcmp(current->message, "Message 3") == 0);

    current = get_previous_node(current);
    assert(strcmp(current->message, "Message 2") == 0);

    current = get_previous_node(current);
    assert(strcmp(current->message, "Message 1") == 0);

    current = get_previous_node(current);
    assert(current == NULL);

    clearLogList(&logList);
    printf("Les fonctions de navigation fonctionnent correctement.\n\n");
}

// Fonction de test pour displayLogMessages
void test_displayLogMessages() {
    printf("Test de displayLogMessages...\n");
    LogList logList;
    initLogList(&logList);

    // Affichage avec une liste vide
    displayLogMessages(&logList, 0); // Ne devrait rien afficher ou  liste est vide

    addLogMessage(&logList, "Message pour l'affichage");

    // Affichage du plus ancien au plus récent
    displayLogMessages(&logList, 0);

    // Affichage du plus récent au plus ancien
    displayLogMessages(&logList, 1);

    clearLogList(&logList);
    printf("displayLogMessages fonctionne correctement.\n\n");
}

// Fonction de test pour freeLogList
void test_freeLogList() {
    printf("Test de freeLogList...\n");
    LogList* logList = malloc(sizeof(LogList));
    initLogList(logList);

    addLogMessage(logList, "Message 1");
    addLogMessage(logList, "Message 2");

    freeLogList(logList);
    // Après freeLogList, logList doit être réinitialisé
    assert(logList->head == NULL);
    assert(logList->tail == NULL);
    assert(logList->size == 0);

    free(logList);
    printf("freeLogList fonctionne correctement.\n\n");
}


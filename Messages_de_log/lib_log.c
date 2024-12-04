// lib_log.c

#include "lib_log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// obtenir l'horodatage actuel au format yyyymmdd-hhmmss
void getCurrentTimestamp(char* buffer, size_t size) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buffer, size, "%Y%m%d-%H%M%S", t);
}

// créer un nouveau message de log
LogMessage* createLogMessage(const char* messageText) {
    LogMessage* newMessage = malloc(sizeof(LogMessage));
    if (newMessage == NULL) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    getCurrentTimestamp(newMessage->timestamp, sizeof(newMessage->timestamp));
    strncpy(newMessage->message, messageText, MAX_MESSAGE_LENGTH);
    newMessage->message[MAX_MESSAGE_LENGTH] = '\0'; // S'assurer que la chaîne est terminée
    newMessage->next = NULL;
    newMessage->prev = NULL;

    return newMessage;
}

// ajouter un message de log à la liste
void addLogMessage(LogList* logList, const char* messageText) {
    LogMessage* newMessage = createLogMessage(messageText);

    // Vérifier si la profondeur maximale est atteinte
    if (logList->size >= MAX_LOG_DEPTH) {
        // Supprimer le premier message
        LogMessage* temp = logList->head;
        logList->head = logList->head->next;
        if (logList->head != NULL) {
            logList->head->prev = NULL; // Mettre à jour prev du nouveau head
        }
        free(temp);
        logList->size--;
    }

    // Ajouter le nouveau message à la fin de la liste
    if (logList->tail == NULL) {
        // La liste est vide
        logList->head = newMessage;
        logList->tail = newMessage;
    } else {
        // liste pas vide
        newMessage->prev = logList->tail;
        logList->tail->next = newMessage;
        logList->tail = newMessage;
    }
    logList->size++;
}

// initialiser la liste des messages de log
void initLogList(LogList* logList) {
    logList->head = NULL;
    logList->tail = NULL;
    logList->size = 0;
}

// afficher tous les messages de log
void displayLogMessages(const LogList* logList, int order) {
    if (order == 0) {
        // du plus ancien au plus récent
        LogMessage* current = logList->head;
        printf("Messages de log du plus ancien au plus récent (%d messages) :\n", logList->size);
        while (current != NULL) {
            printf("[%s] %s\n", current->timestamp, current->message);
            current = current->next;
        }
    } else {
        // du plus récent au plus ancien
        LogMessage* current = logList->tail;
        printf("Messages de log du plus récent au plus ancien (%d messages) :\n", logList->size);
        while (current != NULL) {
            printf("[%s] %s\n", current->timestamp, current->message);
            current = current->prev;
        }
    }
}

// libérer toute la mémoire allouée à la liste
void freeLogList(LogList* logList) {
    LogMessage* current = logList->head;
    while (current != NULL) {
        LogMessage* temp = current;
        current = current->next;
        free(temp);
    }
    logList->head = NULL;
    logList->tail = NULL;
    logList->size = 0;
}

// rechercher un message de log par horodatage
LogMessage* findLogMessageByTimestamp(const LogList* logList, const char* timestamp) {
    LogMessage* current = logList->head;
    while (current != NULL) {
        if (strcmp(current->timestamp, timestamp) == 0) {
            // Horodatage correspondant trouvé
            return current;
        }
        current = current->next;
    }
    return NULL;
}


// supprimer tous les messages de log de la liste
void clearLogList(LogList* logList) {
    LogMessage* current = logList->head;
    while (current != NULL) {
        LogMessage* temp = current;
        current = current->next;
        free(temp);
    }
    logList->head = NULL;
    logList->tail = NULL;
    logList->size = 0;
}

// obtenir le message de log suivant
LogMessage* get_next_node(LogMessage* current) {
    if (current != NULL) {
        return current->next;
    }
    return NULL;
}

//  obtenir le message de log précédent
LogMessage* get_previous_node(LogMessage* current) {
    if (current != NULL) {
        return current->prev;
    }
    return NULL;
}




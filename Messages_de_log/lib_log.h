// lib_log.h

#ifndef LIB_LOG_H
#define LIB_LOG_H

#include <stddef.h>

#define MAX_MESSAGE_LENGTH 32
#define MAX_LOG_DEPTH 10

// Structure pour un message de log
typedef struct LogMessage {
    char timestamp[16]; // Format: yyyymmdd-hhmmss (15 caractères + '\0')
    char message[MAX_MESSAGE_LENGTH + 1]; // texte limité à 32 caractères
    struct LogMessage* next; // Pointeur vers le prochain message
    struct LogMessage* prev; // Vers le précédent message
} LogMessage;

// Structure pour la liste des messages de log
typedef struct {
    LogMessage* head; // Premier message
    LogMessage* tail; // Dernier message
    int size;         // Nombre actuel de messages
} LogList;


void initLogList(LogList* logList);
void displayLogMessages(const LogList* logList, int order);
void freeLogList(LogList* logList);
void getCurrentTimestamp(char* buffer, size_t size);
LogMessage* createLogMessage(const char* messageText);
void addLogMessage(LogList* logList, const char* messageText);
LogMessage* findLogMessageByTimestamp(const LogList* logList, const char* timestamp);
void clearLogList(LogList* logList);
LogMessage* get_next_node(LogMessage* current);
LogMessage* get_previous_node(LogMessage* current);


#endif // LIB_LOG_H

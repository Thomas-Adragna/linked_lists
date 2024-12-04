// main.c

#include "lib_log.h"
#include <stdio.h>
#include <string.h>
#include "tests.h"

int main() {
    LogList logList;
    initLogList(&logList);

    // Ajout de messages de log
    addLogMessage(&logList, "Démarrage du système");
    addLogMessage(&logList, "Connexion établie avec le serveur");
    addLogMessage(&logList, "Erreur: Échec de l'authentification");
    addLogMessage(&logList, "Tentative de reconnexion");
    addLogMessage(&logList, "Reconnexion réussie");
    addLogMessage(&logList, "Transfert de données en cours");
    addLogMessage(&logList, "Transfert de données terminé");
    addLogMessage(&logList, "Déconnexion du serveur");
    addLogMessage(&logList, "Arrêt du système");
    addLogMessage(&logList, "Système arrêté avec succès");

    // Afficher les messages du plus ancien au plus récent
    printf("\nAffichage du plus ancien au plus récent :\n");
    displayLogMessages(&logList, 0);

    // Afficher les messages du plus récent au plus ancien
    printf("\nAffichage du plus récent au plus ancien :\n");
    displayLogMessages(&logList, 1);

    // Navigation avec get_next_node et get_previous_node
    printf("\nNavigation à travers les messages de log :\n");
    LogMessage* current = logList.head;
    printf("Parcours du plus ancien au plus récent :\n");
    while (current != NULL) {
        printf("[%s] %s\n", current->timestamp, current->message);
        current = get_next_node(current);
    }

    current = logList.tail;
    printf("\nParcours du plus récent au plus ancien :\n");
    while (current != NULL) {
        printf("[%s] %s\n", current->timestamp, current->message);
        current = get_previous_node(current);
    }

    char question;
    printf("\nVoulez-vous effectuer les tests ? o / n : ");
    scanf("%c", &question);
    if (question == 'o')
    {
        test_initLogList();
        test_createLogMessage();
        test_addLogMessage();
        test_getCurrentTimestamp();
        test_findLogMessageByTimestamp();
        test_clearLogList();
        test_navigation_functions();
        test_displayLogMessages();
        test_freeLogList();
        printf("Tous les tests ont été passés avec succès.\n");
    } else {
        printf("Les tests n'ont pas été exécutés.\n");
    }



    // Libérer la mémoire
    freeLogList(&logList);

    return 0;
}

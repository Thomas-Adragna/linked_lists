
#include "malib.h"
#include <stdio.h>

int main() {
    struct list_s* head = NULL;

    add_node(&head,"meeting", "meeting avec les clients", 900, 2222);
    add_node(&head, "Dejeuner", "Dejeuner avec le client", 1200, 130);
    add_node(&head, "Rapport", "Redaction du rapport mensuel", 1430, 200);
    display_all(head);

    printf("#######################################\n");

    add_node_tail(&head, "Debut meet", "debut meeting", 400, 525);
    display_all(head);

    printf("#######################################\n");

    delete_node(&head);
    display_all(head);

    printf("#######################################\n");
    delete_node_tail(&head);
    display_all(head);

    printf("#######################################\n");

    struct list_s *found_node = NULL;
    int search_time = 1200;

    int result = get_node(head, search_time, &found_node);
    if (result == 0) {
        printf("Tache trouvee :\n");
        printf("Titre : %s\n", found_node->title);
        printf("Description : %s\n", found_node->description);
        printf("Heure debut : %02d:%02d\n", found_node->start_time / 100, found_node->start_time % 100);
        printf("Duree : %02d:%02d\n", found_node->duration / 100, found_node->duration % 100);
    } else {
        printf("Aucune tache trouvee avec l'heure de debut %02d:%02d.\n", search_time / 100, search_time % 100);
    }

    printf("#######################################\n");

    int res = add_node(&head, "Invalid Task", "Invalid duration", 1000, 1260);
    if (res == -1) {
        printf("Erreur duree invalide.\n");
    }

    res = add_node(&head, "Invalid Task", "Invalid start time", 2400, 100);
    if (res == -1) {
        printf("Invalid start hour.\n");
    }

    char question;
    printf("\nVoulez-vous effectuer les tests ? o / n : ");
    scanf("%c", &question);
    if (question == 'o')
    {
        void test_add_node();
        void test_add_node_tail();
        void test_delete_node();
        printf("Tous les tests ont été passés avec succès.\n");
    } else {
        printf("Les tests n'ont pas été exécutés.\n");
    }


}

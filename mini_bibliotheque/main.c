#include "malib.h"
#include "tests.h"

int main() {


    node_s* head = NULL;
    node_s* found_node = NULL;
    head = (node_s*) malloc(sizeof(node_s));
    if (head == NULL) {
        return 1;
    }
    head->character = 'A';
    head->next = NULL;

    head->next = (node_s*) malloc(sizeof(node_s));
    if (head->next == NULL) {
        return 2;
    }

    head->next->character = 'B';
    head->next->next = NULL;

    display_all(head);

    add_node_tail(head, 'D');
    display_all(head);

    add_node(&head, 'G');
    display_all(head);

    delete_node(&head);
    display_all(head);

    delete_node_tail(&head);
    display_all(head);

    if (get_node(head, 'A', &found_node) == 0) {
        printf("Noeud trouve : %c\n", found_node->character);
    } else {
        printf("Noeud non trouve\n");
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

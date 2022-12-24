#include "table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//
// Fonctions elementaires de manipulation de la table
//

struct table {
    char *str;
    int nb_occurrence;
    Table suivant;
};

/* Creation d'une table vide */
Table creer_table(void) {
    return NULL;
}

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table *table, char *elt) {
    Table previous, current;
    int rescmp;
    for (previous = NULL, current = *table;
         current != NULL; previous = current, current = current->suivant) {
        rescmp = strcmp(current->str, elt);
        if (rescmp == 0) {
            return ++current->nb_occurrence;
        } else if (rescmp > 0) {
            break;
        }
    }
    int nbOccurrence = 1;
    Table nouvel_element = (Table) malloc(sizeof(struct table));
    nouvel_element->str = strdup(elt);
    nouvel_element->nb_occurrence = nbOccurrence;
    nouvel_element->suivant = current;
    if (previous != NULL) { // On insère entre le previous et le current
        previous->suivant = nouvel_element;
    } else { // on insère au début de la table
        *table = nouvel_element;
    }
    return nbOccurrence;
}

static void imprimer_message_table(char * str, int entier){
    printf("str : %s, nombre d'occurrences : %d", str, entier);
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
    appliquer_table(table, imprimer_message_table);
}

/* Appel d'une fonction sur chacun des éléments de la table */
void appliquer_table(Table table, t_fonction fonction) {
    Table t = table;
    while (t != NULL) {
        fonction(t->str, t->nb_occurrence);
        t = t->suivant;
    }
}

/* Recherche du nombre d'occurrences d'un élément */
int rechercher_table(Table table, char *elt) {
    Table t = table;
    int rescmp;
    while (t != NULL) {
        rescmp = strcmp(t->str, elt);
        if (rescmp == 0) {
            return t->nb_occurrence;
        } else if (rescmp > 0) {
            break;
        }
        t = t->suivant;
    }
    return 0;
}

/* Destruction d'une table */
void detruire_table(Table *table) {
    Table courant, suivant;
    for (courant = *table; courant != NULL; courant = suivant) {
        suivant = courant->suivant;
        free(courant->str);
        free(courant);
    }
    //free(table); // pas sûr

}

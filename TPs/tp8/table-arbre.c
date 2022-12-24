#include "table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct table {
    char *mots;
    int nb_occurrence;
    struct table *left;
    struct table *right;
};

//
// Fonctions elementaires de manipulation de la table
//

/* Creation d'une table vide */
Table creer_table(void) {
    return NULL;
}

static Table add(Table t, char *v, Table *node) {
    if (!t) {  // ⇔ t == NULL
        // create a new tree with a single value
        t = malloc(sizeof(struct table));
        if (!t) {
            printf("Allocation error\n");
            exit(1);
        }
        t->mots = strdup(v);
        t->nb_occurrence = 1;
        t->left = t->right = NULL;
        *node = t;  // Retain the node where v lies
    } else {
        // we have a tree
        int comp = strcmp(v, t->mots);
        if (comp == 0) {
            // incrementer t->nb
            t->nb_occurrence += 1;
            *node = t;  // Retain the node where v lies
        } else if (comp < 0)
            // insérer à gauche
            t->left = add(t->left, v, node);
        else
            // insérer à droite
            t->right = add(t->right, v, node);
    }
    return t;
}

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table *table, char *elt) {
    Table item;
    *table = add(*table, elt, &item);
    // On est sûr que item est ≠ NULL
    return item->nb_occurrence;
}

static void imprimer_message_table(char *str, int entier) {
    printf("str : %s, nombre d'occurrences : %d\n", str, entier);
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
    appliquer_table(table, imprimer_message_table);
}

/* Appel d'une fonction sur chacun des éléments de la table */
void appliquer_table(Table table, t_fonction fonction) {
    if (table == NULL) {
        return;
    }
    appliquer_table(table->left, fonction);
    fonction(table->mots, table->nb_occurrence);
    appliquer_table(table->right, fonction);
}

/* Recherche du nombre d'occurrences d'un élément */
int rechercher_table(Table table, char *elt) {
    if (table == NULL) {
        return 0;
    }
    int rescmp = strcmp(table->mots, elt);
    if (rescmp == 0) {
        return table->nb_occurrence;
    } else if (rescmp < 0) {
        return rechercher_table(table->right, elt);
    } else {
        return rechercher_table(table->left, elt);
    }
}

/* Destruction d'une table */
void detruire_table(Table *table) {
    if (*table != NULL) {
        detruire_table(&(*table)->left);
        detruire_table(&(*table)->right);
        free((*table)->mots);
        free(*table);
    }
}

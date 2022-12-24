#include "table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_TABLEAU_MOT_INITIAL 4
struct mot {
    char *str;
    int nb_occurrence;
};

struct table {
    struct mot *mot;
    int taille_table;
    int nb_elements;
};
//
// Fonctions elementaires de manipulation de la table
//

/* Creation d'une table vide */
Table creer_table(void) {
    Table table = (Table) malloc(sizeof(struct table));
    struct mot *mots = (struct mot *) malloc(TAILLE_TABLEAU_MOT_INITIAL * sizeof(struct mot));
    if (mots == NULL) {
        printf("erreur allocation dynamique");
        exit(-1);
    }
    table->mot = mots;
    table->nb_elements = 0;
    table->taille_table = TAILLE_TABLEAU_MOT_INITIAL;
    return table;
}

static int add_word(Table *table, int index, char *str) {
    Table T = *table;
    struct mot *mots = T->mot;
    int i, nb = T->nb_elements;
    int size = T->taille_table;

    if (nb == size) {
        // La table est pleine, la "rallonger" avant d'essayer d'insérer str
        size *= 1.5;
        mots = realloc(mots, size * sizeof(struct mot));

        if (!mots) {
            fprintf(stderr, "cannot reallocate memory\n");
            return 0;
        }

        // conserver les nouvelles valeurs dans la table
        T->mot = mots;
        T->taille_table = size;
    }

    // Créer une copie du mot passé en paramètre
    char *mot = strdup(str);

    if (!mot) {
        fprintf(stderr, "cannot make a copy of '%s'\n", str);
        return 0;
    }

    // Décaler l'intervalle [i .. nb[ d'une case à droite
    for (i = nb; i > index; i--) {
        mots[i] = mots[i - 1];
    }

    // Insérer le nouveau mot à la position index
    mots[index].str = mot;
    mots[index].nb_occurrence = 1;

    // On a un mot de plus dans la table
    T->nb_elements += 1;

    return 1;  // car ce mot apparaît une fois
}

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table *table, char *elt) {
    Table T = *table;
    struct mot *mots = T->mot;
    int i, res, nb = T->nb_elements;

    // Chercher dans "tab" le mot "elt"
    for (i = 0; i < nb; i++) {
        res = strcmp(elt, mots[i].str);
        if (res < 0)
            break;
        if (res == 0)  // trouvé ⇒ incrémenter le nombre d'occ. et terminer
            return ++mots[i].nb_occurrence;
    }

    // Si on est là, ajouter une un nouvel élément à mettre à l'indice i
    return add_word(table, i, elt);
}

/* Appel d'une fonction sur chacun des éléments de la table */
void appliquer_table(Table table, t_fonction fonction) {
    for (int i = 0; i < table->nb_elements; i++) {
        fonction(table->mot[i].str, table->mot[i].nb_occurrence);
    }
}

static void imprimer_message_table(char *str, int entier) {
    printf("str : %s, nombre d'occurrences : %d", str, entier);
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
    appliquer_table(table, imprimer_message_table);
}


/* Recherche du nombre d'occurrences d'un élément */
int rechercher_table(Table table, char *elt) {
    int rescmp;
    for (int i = 0; i < table->nb_elements; i++) {
        rescmp = strcmp(table->mot[i].str, elt);
        if (rescmp == 0) {
            return table->mot[i].nb_occurrence;
        } else if (rescmp > 0) {
            break;
        }
    }
    return 0;
}

/* Destruction d'une table */
void detruire_table(Table *table) {
    Table t = *table;
    for (int i = 0; i < t->nb_elements; i++) {
        free(t->mot[i].str);
    }
    free(t->mot);
    free(t);
    free(table); // pas sûr
}

//
// Created by Michel K on 04/12/2022.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node *Tree;

Tree create_empty_tree(void) { // créer un nouvel arbre vide
    Tree noeud = (Tree) malloc(sizeof(*noeud));
    if (noeud == NULL) {
        return NULL;
    }
    noeud->right = NULL;
    noeud->left = NULL;
    return noeud;
}

Tree
add_tree(Tree t, int v) // ajouter v dans l'arbre t. Cette fonction renvoie l'arbre dans lequel v a été ajouté.`{.c}
{
    if (t == NULL) { // créer arbre et ajouter à la racine
        t = create_empty_tree();
        t->value = v;
    } else {
        if (t->value < v) {
            t->right = add_tree(t->right, v);
        } else if (t->value >= v) {
            t->left = add_tree(t->left, v);
        }
    }
    return t;
}

void print_tree(Tree t) { // afficher l'arbre t (dans l'ordre)
    if (t != NULL) {
        if (t->left != NULL) print_tree(t->left);
        printf("%d ", t->value);
        if (t->right != NULL)
            print_tree(t->right);
    } // On pourrait seulement check t->left != NULL car arbre de recherche
}

Tree find_tree(Tree t, int v) { // Renvoyer l'arbre de racine v (NULL si absent)
    if (t != NULL) {
        if (v == t->value) {
            return t;
        } else if (v < t->value) {
            return find_tree(t->left, v);
        } else {
            return find_tree(t->right, v);
        }
    } else {
        return NULL;
    }
}

void free_tree(Tree t) { // Libérer l'espace occupé par t
    if (t != NULL) {
        free_tree(t->left);
        free_tree(t->right);
        printf("Freeing space for key : %d\n", t->value);
        free(t);
    }
}

int main(void) {
    Tree t = create_empty_tree();
// Création de l'arbre du sujet
    t = add_tree(t, 8);
    t = add_tree(t, 3);
    t = add_tree(t, 10);
    t = add_tree(t, 1);
    t = add_tree(t, 6);
    t = add_tree(t, 7);
    t = add_tree(t, 4);
    t = add_tree(t, 14);
    t = add_tree(t, 13);
// Impression de l'arbre (trié)
    printf("Valeurs dans l'arbre: ");
    print_tree(t);
    printf("\n");
// Recherches
    printf("\nRecherches:\n");
    for (int i = 0; i < 20; i++) {
        printf("%2d: %s, ", i, find_tree(t, i) ? "oui" : "non");
        if (i % 5 == 4) printf("\n");
    }
// Free
    printf("\nLibération mémoire de l'arbre:\n");
    free_tree(t);
    return 0;
}


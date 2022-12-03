//
// Created by Michel K on 03/12/2022.
//

#include <stdio.h>
#include <stdlib.h>

struct element {
    int valeur;
    struct element *suivant;
};
typedef struct element Element;
typedef Element **List;


// Imprimer la liste lst
void print_list(List lst) {
    Element *element = *lst;
    while (element != NULL) {
        printf("%d\n", element->valeur);
        element = element->suivant;
    }
}

// Ajouter la valeur v au début de la liste lst
void prepend_element(List lst, int v) {
    (*lst)->suivant = NULL;
    Element *element = (Element *) malloc(sizeof(Element));
    if (element != NULL) {
        element->valeur = v;
        element->suivant = *lst;
        *lst = element;
    }
}

// Ajouter la valeur v à la fin de la liste lst
void append_element(List lst, int v) {
    if (lst == NULL || (*lst) == NULL) {
        return;
    } else if ((*lst)->suivant == NULL) {
        Element *element = (Element *) malloc(sizeof(Element));
        element->valeur = v;
        element->suivant = NULL;
        (*lst)->suivant = element;
    } else {
        append_element(&(*lst)->suivant, v);
    }
}

// Ajouter la valeur v dans la liste ordonnée lst
void insert_element(List lst, int v) {
    if (lst == NULL || (*lst) == NULL) {
        return;
    } else if (((*lst)->suivant)->valeur >= v) {
        Element *element = (Element *) malloc(sizeof(Element));
        element->valeur = v;
        element->suivant = (*lst)->suivant;
        (*lst)->suivant = element;
    } else {
        insert_element(&(*lst)->suivant, v);
    }
}

// Supprimer la (première) valeur égale à v de la liste lst
void delete_element(List lst, int v) {
    if (lst == NULL || (*lst) == NULL) {
        return;
    } else if ((*lst)->valeur == v) {
        *lst = (*lst)->suivant;
    } else {
        delete_element(&(*lst)->suivant, v);
    }
}

// Supprimer tous les éléments égaux à v dans la liste lst
void delete_elements(List lst, int v) {
    if (lst == NULL || (*lst) == NULL) {
        return;
    } else if ((*lst)->valeur == v) {
        *lst = (*lst)->suivant;
        delete_elements(lst, v);
    } else {
        delete_elements(&(*lst)->suivant, v);
    }
}

// Tester si la valeur v est dans liste lst
int find_element(List lst, int v) {
    if (lst == NULL || (*lst) == NULL) {
        return -1;
    } else if ((*lst)->valeur == v) {
        return 1;
    } else {
        return find_element(&(*lst)->suivant, v);
    }
}

int main(void) {
    Element *liste = (Element *) malloc(sizeof(Element));
    liste->valeur = 2;
    prepend_element(&liste, 5);
    printf("prepend :\n");
    print_list(&liste);
    append_element(&liste, 8);
    printf("append :\n");
    print_list(&liste);
    printf("find : %d\n", find_element(&liste, 1));
    insert_element(&liste, 8);
    printf("insert :\n");
    print_list(&liste);
    delete_element(&liste, 5);
    printf("delete :\n");
    print_list(&liste);
    delete_elements(&liste, 8);
    printf("delete_all_occurrences :\n");
    print_list(&liste);
}
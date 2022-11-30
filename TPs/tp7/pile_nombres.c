//
// Created by Michel K on 28/11/2022.
//

#include <stdio.h>
#include <stdlib.h>

struct element {
    int valeur;
    struct element *suivant;
};
typedef struct element Element;

void push_item(Element *stack, int value) {
    stack->suivant = NULL; // 2 NULL
    Element *element = (Element *) malloc(sizeof(Element));
    if (element != NULL) {
        element->valeur = value; // 5
        element->suivant = stack; // 5 2 NULL
        stack = element;
    }
}

void print_stack(Element *liste) {
    if (liste != NULL) {
        printf("%d\n", liste->valeur);
        print_stack(liste->suivant);
    }
}

int main(void) {
    Element *element = (Element *) malloc(sizeof(Element));
    element->valeur = 2;
    push_item(element, 5);
    print_stack(element);
}

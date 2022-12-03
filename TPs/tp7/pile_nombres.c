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

void print_stack(Element *liste) {
    if (liste != NULL) {
        printf("%d\n", liste->valeur);
        print_stack(liste->suivant);
    }
}

void push_item(Element **stack, int value) {
    (*stack)->suivant = NULL;
    Element *element = (Element *) malloc(sizeof(Element));
    if (element != NULL) {
        element->valeur = value;
        element->suivant = *stack;
        *stack = element;
    }
}

void pop_item(Element **stack) {
    *stack = (*stack)->suivant;
}

int top_value(Element **stack) {
    return (*stack)->valeur;
}


int main(void) {
    Element *element = (Element *) malloc(sizeof(Element));
    element->valeur = 2;
    push_item(&element, 5);
    printf("Push :\n");
    print_stack(element);
    pop_item(&element);
    printf("Pop :\n");
    print_stack(element);
    top_value(&element);
    printf("Top value :\n");
    print_stack(element);
}

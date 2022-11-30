//
// Created by Michel K on 11/11/2022.
//

#include <stdio.h>

int main(void) {
    int puissanceCourante = 1;
    int premierOperande = 0;
    int partieDecimalePremierOperande = 0;
    int deuxiemeOperande = 0;
    int partieDecimaleDeuxiemeOperande = 0;

    char operateur = ' ';

    char str[100];
    int indexStr = 0;

    char strPremierOperande[50];
    int sizeStrPremierOperande = 0;
    char strPartieDecimalePremierOperande[50];
    int sizeStrPartieDecimalePremierOperande = 0;

    double realDecimalPartiePremierOperande;

    char strDeuxiemeOperande[50];
    int sizeStrDeuxiemeOperande = 0;
    char strPartieDecimaleDeuxiemeOperande[50];
    int sizeStrPartieDecimaleDeuxiemeOperande = 0;

    double realDecimalPartieDeuxiemeOperande;

    int isPremierOperandeEntier;
    int isDeuxiemeOperandeEntier;
    char c;
    int i, j;

    int indiceTableauPremierOperande;
    int indiceTableauDeuxiemeOperande;
    while (1) {
        indexStr = 0;
        while ((c = getchar()) != '\n') {
            if (c != EOF && c != ' ' && c != '\t' &&
                ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '.')) {
                str[indexStr] = c;
                indexStr++;
            }
        }
        isPremierOperandeEntier = 1;
        isDeuxiemeOperandeEntier = 1;
        premierOperande = 0;
        deuxiemeOperande = 0;
        indiceTableauPremierOperande = 0;
        indiceTableauDeuxiemeOperande = 0;
        i = 0;
        while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
            if (str[i] == '.') {
                isPremierOperandeEntier = 0;
                sizeStrPremierOperande = i;
                i++;
                j = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    strPartieDecimalePremierOperande[j] = str[i];
                    i++;
                    j++;
                }
                sizeStrPartieDecimalePremierOperande = j;
                break;
            }
            strPremierOperande[indiceTableauPremierOperande] = str[i];
            indiceTableauPremierOperande++;
            i++;
        }
        if (isPremierOperandeEntier) {
            sizeStrPremierOperande = indiceTableauPremierOperande;
        }
        puissanceCourante = 1;
        for (int k = sizeStrPremierOperande - 1; k >= 0; k--) {
            premierOperande += ((strPremierOperande[k] - '0') * puissanceCourante);
            puissanceCourante *= 10;
        }
        puissanceCourante = 1;
        for (int k = sizeStrPartieDecimalePremierOperande - 1; k >= 0; k--) {
            partieDecimalePremierOperande += ((strPartieDecimalePremierOperande[k] - '0') * puissanceCourante);
            puissanceCourante *= 10;
        }
        if (isPremierOperandeEntier) {
            realDecimalPartiePremierOperande = 0.0;
        } else {
            realDecimalPartiePremierOperande = ((double) (partieDecimalePremierOperande)) / (puissanceCourante);
        }


        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
            operateur = str[i];
            i++;
        }
        while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
            if (str[i] == '.') {
                isDeuxiemeOperandeEntier = 0;
                sizeStrDeuxiemeOperande = indiceTableauDeuxiemeOperande;
                i++;
                j = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    strPartieDecimaleDeuxiemeOperande[j] = str[i];
                    i++;
                    j++;
                }
                sizeStrPartieDecimaleDeuxiemeOperande = j;
                break;
            }
            strDeuxiemeOperande[indiceTableauDeuxiemeOperande] = str[i];
            indiceTableauDeuxiemeOperande++;
            i++;
        }
        if (isDeuxiemeOperandeEntier) {
            sizeStrDeuxiemeOperande = indiceTableauDeuxiemeOperande;
        }
        puissanceCourante = 1;
        for (int k = sizeStrDeuxiemeOperande - 1; k >= 0; k--) {
            deuxiemeOperande += (strDeuxiemeOperande[k] - '0') * puissanceCourante;
            puissanceCourante *= 10;
        }
        puissanceCourante = 1;
        for (int k = sizeStrPartieDecimaleDeuxiemeOperande - 1; k >= 0; k--) {
            partieDecimaleDeuxiemeOperande += (strPartieDecimaleDeuxiemeOperande[k] - '0') * puissanceCourante;
            puissanceCourante *= 10;
        }
        if (isDeuxiemeOperandeEntier) {
            realDecimalPartieDeuxiemeOperande = 0.0;
        } else {
            realDecimalPartieDeuxiemeOperande = ((double) (partieDecimaleDeuxiemeOperande)) / (puissanceCourante);
        }

        printf("%f", premierOperande + realDecimalPartiePremierOperande);
        printf("%c", operateur);
        printf("%f = ", deuxiemeOperande + realDecimalPartieDeuxiemeOperande);
        if (operateur == '+') {
            printf(" = %f\n", (premierOperande + realDecimalPartiePremierOperande) +
                              (deuxiemeOperande + realDecimalPartieDeuxiemeOperande));
        } else if (operateur == '*') {
            printf(" = %f\n", (premierOperande + realDecimalPartiePremierOperande) *
                              (deuxiemeOperande + realDecimalPartieDeuxiemeOperande));
        } else if (operateur == '-') {
            printf(" = %f\n", (premierOperande + realDecimalPartiePremierOperande) -
                              (deuxiemeOperande + realDecimalPartieDeuxiemeOperande));
        } else if (operateur == '/') {
            if (deuxiemeOperande + realDecimalPartieDeuxiemeOperande == 0.0) {
                continue;
            }
            printf(" = %f\n", (premierOperande + realDecimalPartiePremierOperande) /
                              (deuxiemeOperande + realDecimalPartieDeuxiemeOperande));

        }


        for (int v = 0; v < i; v++) {
            str[v] = '\0';
        }
        for (int v = 0; v < sizeStrPremierOperande; v++) {
            strPremierOperande[v] = '\0';
        }
        for (int v = 0; v < sizeStrDeuxiemeOperande; v++) {
            strDeuxiemeOperande[v] = '\0';
        }
        for (int v = 0; v < sizeStrPartieDecimalePremierOperande; v++) {
            strPartieDecimalePremierOperande[v] = '\0';
        }
        for (int v = 0; v < sizeStrPartieDecimaleDeuxiemeOperande; v++) {
            strPartieDecimaleDeuxiemeOperande[v] = '\0';
        }
    }
}
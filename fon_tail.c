#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tail.h"

void ouvrir(FILE **fic, char *fichier) {
    *fic = fopen(fichier, "r");
    if (*fic == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n", fichier);
        exit(1);
    }
}

char *alloc() {
    char *A = (char *)malloc(100 * sizeof(char));
    if (A == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }

    return A;
}

int compteur(FILE *fic, int n) {
    int nbr_ligne = 0;
    char chaine[100];

    // Compter le nombre total de lignes dans le fichier
    while (fgets(chaine, 100, fic) != NULL) {
        nbr_ligne++;
    }

    // Calculer le nombre de lignes à ignorer à partir de la fin
    int lignes_a_ignorer = nbr_ligne - n;
    if (lignes_a_ignorer < 0) {
        lignes_a_ignorer = 0; // Si n est plus grand que le nombre de lignes dans le fichier
    }

    return lignes_a_ignorer;
}

int cast(char *arg) {
    return atoi(arg);
}

void tail(FILE *fic, int nbr_ligne) {
    char chaine[100];
    int a = 0;

    while (fgets(chaine, 100, fic) != NULL) {
        a++;
        if (a > nbr_ligne) {
            printf("%s", chaine);
        }
    }
}

void afficher_tail(FILE *fic, int nbr_ligne, int n, char *file_name) {
    char chaine[100];
    int a = 0;

    printf("==> %s <==\n", file_name);
    while (fgets(chaine, 100, fic) != NULL) {
        a++;
        if (a > nbr_ligne - n) {
            printf("%s", chaine);
        }
    }
}

void traiter_options(int argc, char *argv[]) {
    int n = 10; // Valeur par défaut pour -n
    char *file_name = NULL;
    FILE *fic = NULL;

    if (strcmp(argv[1], "-v") == 0) {
        if (argc >= 3) {
            file_name = argv[2];
        } else {
            printf("Arguments incorrects pour l'option -v\n");
            exit(1);
        }
    } else if (strcmp(argv[1], "-n") == 0) {
        if (argc >= 4) {
            n = cast(argv[2]);
            file_name = argv[3];
        } else {
            printf("Arguments incorrects pour l'option -n\n");
            exit(1);
        }
    } else {
        // Aucune option spécifiée, le premier argument est le nom du fichier
        file_name = argv[1];
    }

    ouvrir(&fic, file_name);
    int nbr_ligne = compteur(fic, n);
    fclose(fic);

    ouvrir(&fic, file_name);
    if (strcmp(argv[1], "-v") == 0) {
        afficher_tail(fic, nbr_ligne, n, file_name);
    } else {
        tail(fic, nbr_ligne);
    }
    fclose(fic);
}

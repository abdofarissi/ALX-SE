#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant{
    char nom[20];
    int age;
    float moyenne;
    struct Etudiant *suivant;
}Etudiant;

Etudiant *CreeEtudiant(char nom[10], int age, float moyenne)
{
    Etudiant *newEtu;
    newEtu = (Etudiant *) malloc(sizeof(Etudiant));
    if (newEtu == NULL)
    {
        printf("Erreur : allocation memoire echoue \n");
        exit(1);
    }
    strcpy(newEtu ->nom , nom);
    newEtu ->age = age;
    newEtu ->moyenne = moyenne;
    newEtu ->suivant = NULL;
    return newEtu;
}


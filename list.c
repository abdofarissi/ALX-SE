#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant{
    char nom[20];
    int age;
    int moyenne;
    struct Etudiant *suivant;
}Etudiant;

Etudiant *CreeEtudiant(char nom[20], int age, int moyenne)
{
    Etudiant *newEtu;
    newEtu = (Etudiant *) malloc(sizeof(Etudiant));
    strcpy(newEtu ->nom , nom);
    newEtu ->age = age;
    newEtu ->moyenne = moyenne;
    newEtu ->suivant = NULL;
    return newEtu;
}

int main()
{
    Etudiant * head ;
    Etudiant *first = CreeEtudiant("abdo", 20, 15);
    Etudiant *second = CreeEtudiant("Dunya", 19, 10);
    Etudiant *tail = CreeEtudiant("Sakai", 24, 17);

    head = first;
    first ->suivant = second;
    second ->suivant = tail;
    tail ->suivant = NULL;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant{
    char nom[20];
    int age;
    float moyenne;
    struct Etudiant *suivant;
}Etudiant;

Etudiant *CreeEtudiant(char nom[20], int age, int moyenne)
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
void afficher(Etudiant *head)
{
    Etudiant *courant = head;
    while (courant != NULL)
    {
        printf("Nom : %s \n ", courant ->nom);
        printf("Age : %d \n", courant ->age);
        printf("Moyenne : %.2f \n", courant ->moyenne);
        courant =courant -> suivant;
    }
    

}
void Recherche(Etudiant *head, char nom[20])
{
    Etudiant *piv = head;
    while (piv != NULL)
    {
        if (strcmp(nom , piv ->nom ) == 0)
        {
            printf("l'etudiant trouvee ! \n");
            printf("Nom : %s \n ", piv ->nom);
            printf("Age : %d \n", piv ->age);
            printf("Moyenne : %.2f \n", piv ->moyenne);
            break;
        }
        piv = piv ->suivant;
    }
}
void R_indice(Etudiant *head, int indice)
{
    Etudiant *temp = head;
    int i = 0;
    while (temp != NULL && i < indice)
    {
            temp = temp ->suivant;
            i++;
        if (temp != NULL)
        {
             printf("l'etudiant trouvee ! \n");
            printf("Nom : %s \n ", temp ->nom);
            printf("Age : %d \n", temp ->age);
            printf("Moyenne : %.2f \n", temp ->moyenne);
        }
        
    }
    

}

int main()
{
    Etudiant * head ;
    Etudiant *first = CreeEtudiant("Abdo", 20, 15);
    Etudiant *second = CreeEtudiant("Dunya", 19, 10);
    Etudiant *tail = CreeEtudiant("Sakai", 24, 17);

    head = first;
    first ->suivant = second;
    second ->suivant = tail;
    tail ->suivant = NULL;
    int i ;
    printf("rechercher par indice : ");
    scanf("%d", &i);
    R_indice(head , i);
}




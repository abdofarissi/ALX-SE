#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Chanson
{
    int id;
    char titre [30];
    float duree;
    struct Chanson * suivant ;
}Chanson;

Chanson * ajouterChanson(Chanson *head, int id, char tit[30], float dure)
{
    Chanson * new = (Chanson *)malloc(sizeof(Chanson));
    new ->id = id;
    new ->duree = dure;
    strcpy(new ->titre, tit);
    if (head == NULL)
    {
       new ->suivant = head;
       return new;
    }
    Chanson * courant = head;
    while (courant ->suivant != head)
    {
        courant = courant ->suivant;
    }
    courant ->suivant = new;
    new ->suivant = head;
    return head;
}

Chanson * supprimerChanson(Chanson * head)
{   
    int r ;
    printf("saisir la chonson a supprimer par id:");
    scanf("%d",&r);
    if (head == NULL)
    {
        printf("Playlist est vide \n");
        return head;
    }
    if (head ->suivant == head )
    {
        free(head);
        return NULL;
    }
    Chanson * courant = head;
   while (courant ->suivant != head && courant->suivant ->id == r)
   {
        courant = courant ->suivant;
   }
   Chanson * temp = courant ->suivant;
   courant ->suivant = temp ->suivant;
   free(temp);
   return head;
}
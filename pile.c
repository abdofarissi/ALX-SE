#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int valeur ;
    struct Node * suivant;
}Node;
typedef Node *Pile ;

void Empiler(Pile *sommet , int  val)
{
    Node * nouveau = (Node *) malloc(sizeof(Node));
    if (nouveau == NULL)
    {
        printf("allocation de memoir echouee");
        return ;
    }
    nouveau ->valeur = val;
    nouveau ->suivant = *sommet ;
    *sommet = nouveau;
}
int depiler(Pile * sommet)
{   
    if (*sommet == NULL)
    {
        printf("la pile est deja vide vide \n ");
    }
    Node * temp = *sommet ;
    int val = temp ->valeur;
    *sommet = temp ->suivant;
    free(temp);

    return val;
}
void afficherPile(Pile sommet) {
    Node *courant = sommet;
    printf("Contenu de la pile : ");
    while (courant != NULL) 
    {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}
int main ()
{
    Pile sommet = NULL;
    Empiler(&sommet , 58);
    Empiler(&sommet , 23);
    Empiler(&sommet , 14);
    int val = depiler (&sommet);
    afficherPile(sommet);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int prix ;
    struct Node * suivant;
}Node;
typedef Node *Pile ;

void ajouterPrix(Pile * sommet )
{
    Node * new = (Node *)malloc (sizeof(Node));
    if (new == NULL)
    {
       printf("allocation memoire echouee \n");
       return;
    }
    float prix;
    printf("ajouter un article . Prix : ");
    scanf("%f", &prix);
    new ->prix = prix;
    new ->suivant = *sommet;
    *sommet = new;
}
int annulerSaisie(Pile * sommet)
{
    if ( *sommet == NULL)
    {
       printf("acunne commende a supprime !\n");
       return 0;
    }
    Node * temp = *sommet;
    float prix = temp ->prix;
    *sommet = temp ->suivant;
    free(temp);

    return prix;
}
void afficherCommande(Pile *sommet)
{
    Node * courant = *sommet;
    int i = 1;
    while (courant != NULL)
    {
        printf("le Prix d'article %d : %.2f", i, courant ->prix );
        i++;
        courant = courant ->suivant;
    }
    printf("NULL \n");

}

int main ()
{
    Pile sommet = NULL;
    while (1)
    {
        ajouterPrix(&sommet);
        
    }
    


    return 0;
}
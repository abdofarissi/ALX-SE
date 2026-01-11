#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tache
{
    int id, statue;
    float duree ;
    struct Tache * suiv;
    struct Tache * prec;
}Tache;
Tache * CreeTache(int id, int statue, float duree)
{
  Tache * new = (Tache *)malloc(sizeof(Tache));
    if (new == NULL )
    {
        printf("allocation echouee");
        exit(1);
    }   
    new ->id = id;
    new ->duree = duree;
    new ->statue = statue;
    new ->suiv = NULL;
    new ->prec = NULL;
}
Tache * ajouterTacheFin(Tache* head)
{
    int id, statue ;
    float duree;
    Tache * new = (Tache *)malloc(sizeof(Tache));
    if (new == NULL )
    {
        printf("allocation echouee");
        exit(1);
    }
    printf("saisir l'id  :");
    scanf("%d", &id);
   do
    {
        printf("saisir statut : ");
        scanf("%d", &statue);
    }while (statue < 0 || statue > 2);
    printf("saisir la dure :");
    scanf("%f", &duree);

    new ->id = id;
    new ->duree = duree;
    new ->statue = statue;
    if (head == NULL)
    {
        new ->suiv = NULL;
        new ->prec = NULL;
        return new;
    }
    Tache * courant = head;
    while (courant ->suiv != NULL)
    {   
        courant = courant ->suiv;
    }
    courant->suiv = new;
    new->prec = courant;
    return head;
}
Tache * Supprimer(Tache * head)
{
    if (head == NULL)
    {
        printf("liste deja vide \n");
        return head;
    }
    int id ;
    printf("entre l'id de tache a supprimer : ");
    scanf("%d", &id);
    Tache *courant = head;
    while (courant != NULL && courant ->id != id)
    {
        courant = courant ->suiv;
    }
    if (courant == NULL)
    {
        printf("tache non trouvee\n");
        return head;
    }
    if (courant ->prec == NULL)
    {
        head = courant ->suiv;
        if (head != NULL)
        {
            head ->prec = NULL;
        }
    }
    else
    {
        courant ->prec->suiv = courant ->prec;
    }
    free(courant);
    printf("Tache Supprimee !! \n");
    return head;
}

void Afficher (Tache * head)
{
    if (head == NULL)
    {
        printf("la liste est Vide \n");
    }
    Tache * courant = head; 
    int i = 1;
    while (courant!= NULL)
    {
        printf("Tache num %d :\n", i);
        printf("id : %d  ", courant ->id );
        printf("Statue : %d  ", courant ->statue );
        printf("duree : %.2f  \n", courant ->duree);
        i++;
        courant = courant -> suiv;
    }

}
int main ()
{
    Tache *head;
    Tache * first = CreeTache(556, 0, 5);
    Tache * second = CreeTache(548, 1, 4.2);
    Tache * Tail = CreeTache (221, 2, 6);

    head = first;
    first ->prec = NULL;
    first ->suiv = second;
    second ->prec = first ;
    second ->suiv = Tail;
    Tail ->prec = second ; 
    Tail->suiv = NULL;

    head = Supprimer(head);
    Afficher(head);
    return 0;
}   
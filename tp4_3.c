#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int id ;
    int poids ;
    struct Noeud * suivant;
    struct Noeud * precedent;
}Noeud;

Noeud * CreeNoeud(int id, int poids)
{
    Noeud * new = (Noeud*)malloc(sizeof(Noeud));
    if (new == NULL)
    {
        printf("allocation memoire echouee \n");
        exit(1);
    }
    new ->id = id;
    new ->poids = poids;
    new->precedent=new->suivant = NULL;
    return new;
}

Noeud * ajouterNoeud(Noeud * head, int id)
{
    Noeud * new = (Noeud*)malloc(sizeof(Noeud));
    if (new == NULL)
    {
        printf("allocation memoire echouee \n");
        exit(1);
    }
    int Npoid ;
    printf("entrer le poids du noeud :");
    scanf("%d", &Npoid);
    while (Npoid <5 || Npoid > 10)
    {
        printf("le poids doit etre entre 5<= poids <= 10");
        printf("entrer le poids du noeud :");
        scanf("%d", &Npoid);
    } 
    new ->id = id;
    new ->poids = Npoid;
    new->precedent=new->suivant = NULL;
    if (head == NULL)
    {
        new ->suivant = new;
        new ->precedent = new;
        return new;
    }
    Noeud * last = head ->precedent;
    last ->suivant= new;
    new ->precedent = last;

    new ->suivant = head;
    head ->precedent = new;

    return head;
}

Noeud * supprimerNoeudParId(Noeud* head, int id)
{
    Noeud * courant = head;
    if (head == NULL)
    {
       printf("la liste est vide \n");
       return NULL;
    }
    if (head ->suivant == head)
    {
        if (head->id == id)
        {
            free(head);
            return NULL;
        }
        else{
            printf("id non trouveé \n");
            return head;
        }
        
    }
    do {
        if (courant->id == id) 
        break;
        courant = courant->suivant;

    } while (courant != head);
    if (courant->id != id)
    {
        printf("id non trouve\n");
        return head;
    }
    Noeud *last = head ->precedent;
    if (courant == head)
    {
        Noeud * newhead = head->suivant;
        last ->suivant = newhead;
        newhead ->precedent = last;
        free(head);
        return newhead;
    }
    else if (courant == last)
    {
        Noeud * newlast = last->precedent;
        newlast ->suivant = head;
        head ->precedent = newlast;
        free(last);
        return head;
    }
    else 
    {
        courant->precedent->suivant = courant->suivant;
        courant->suivant ->precedent = courant->precedent;
        free(courant);
        return head;
    }
    
}
void Afficher(Noeud * head)
{
    Noeud * courant = head;
    int i = 1;
    do
    {
        printf("le parcour num %d :\n", i);
        printf("id : %d\n", courant->id);
        printf("poids : %d\n",courant ->poids);
        courant= courant->suivant;
        i++;
    } while (courant !=head );
    
}

int main ()
{
    Noeud * head =NULL;
    Noeud *first = CreeNoeud(12, 6);
    Noeud *second = CreeNoeud(13, 7);
    Noeud *last = CreeNoeud(42, 9);

    head = first;
    first ->precedent= last;
    first ->suivant = second;
    second->suivant = last;
    second ->precedent= first;
    last ->precedent = second;
    last ->suivant = head;


    head = ajouterNoeud(head, 12);
    Afficher(head);
    head = supprimerNoeudParId(head, 13);
    printf("apres deletion \n");
    Afficher(head);

    return 0;
}
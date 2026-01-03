#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valeur;
    struct Node * suivant;
}Node;

typedef struct
{
   Node *Tete;
   Node *Queue;
}File;

void initFile(File *f)
{
    f->Tete = NULL;
    f->Queue = NULL;
}

void enfiler(File * f, int val)
{
    Node * new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
    {
       printf("allocation memoire echouee \n");
       exit(1);
    }
    new ->valeur = val ;
    new ->suivant =NULL;
    if (f ->Queue == NULL)
    {
        f->Tete = f->Queue = new;
    }
    else
    {
        f->Queue->suivant = new;
        f->Queue = new;
    }
}

int defiler(File *f)
{
    if (f->Tete == NULL)
    {
        printf("la file est Vide , Impossible a Defiler \n");
        return -1;
    }
    Node *temp = f->Tete;
    int val = temp ->valeur;
    f->Tete = temp ->suivant;
    if (f->Tete == NULL)
    {
        f->Queue = NULL;
    }
    free(temp);
    return val;
}

void Afficher(File f)
{
    Node * courant = f.Tete;
    while (courant != NULL)
    {
        printf("%d-> ",courant->valeur);
        courant = courant ->suivant;
    }
    printf("NULL\n");
    
}

int main ()
{
    File f;
    initFile(&f);
    enfiler(&f, 18);
    enfiler(&f, 20);
    enfiler(&f, 13);
    Afficher(f);
    int val = defiler(&f);
    Afficher(f);
    return 0;
}
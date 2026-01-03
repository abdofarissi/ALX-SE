#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char nom[25];
    struct Node * suivant;
}Node;

typedef struct
{
   Node *Tete;
   Node *Queue;
}File;

void InitFile(File *f)
{
    f->Tete = NULL;
    f->Queue = NULL;
}
void AjouterP(File *f, char Nom[25])
{
    Node *nouveau = (Node *)malloc(sizeof(Node));
    if (nouveau == NULL)
    {
        printf("allocation memoire echouee\n");
        exit(1);
    }
    strcpy(nouveau ->nom, Nom);
    nouveau ->suivant = NULL;
    if (f->Queue == NULL)
    {
        f->Tete = f->Queue = nouveau;
    }
    else
    {
        f->Queue ->suivant = nouveau;
        f->Queue = nouveau;
    }
}
void afficher(File *f)
{
    Node *courant = f->Tete;
    int i = 1;
    while (courant != NULL)
    {
       printf("la Patient num %d : %s\n",i, courant ->nom);
        i++;
        courant = courant ->suivant;
    }
}
void Nombre(File f)
{
    int num = 0;
    Node *courant = f.Tete;
    while (courant != NULL)
    {
        num++;
        courant = courant ->suivant;
    }
    printf("le nombre des Patient est %d", num);
}
int  SupprimerparNom(File *f )
{
    char nom[25];
    if (f->Tete == NULL)
    {
        printf("la file est vide\n");
        return 0;
    }
    printf("saisir le nom de patient : ");
    scanf("%s",nom);

    Node *courant = f->Tete;
    Node *precedent = NULL;

    while (courant != NULL)
    {
        if (strcmp(courant ->nom, nom) == 0)
        {
            if (precedent == NULL)
            {
               f->Tete = courant->suivant;
               if (f->Tete == NULL)
               {
                    f->Queue = NULL;
               }
            }
            else
            {
                precedent ->suivant = courant->suivant;
                if (courant == f->Queue)
                {
                    f->Queue = precedent;
                }
                
            }
            free(courant);
            printf("Patient a supprimer \n");
            return 1;
            
        }
        precedent = courant;
        courant = courant ->suivant;

    }
    printf("Patient %s non trouvee\n", nom);
    return 0; 
}
int Nombreavant(File *f)
{
    char nom[25];
    if (f->Tete == NULL)
    {
        printf("la file est vide\n");
        return 0;
    }
    printf("saisir le nom de patient : ");
    scanf("%s",nom);
    Node *courant = f->Tete;
    int sum = 0;
    while (courant != NULL)
    {
         if (strcmp(courant ->nom, nom)== 0)
        {
            printf("la nombre des patient avant %s est %d", nom, sum);
            return 1;
        }
        sum++;
        courant = courant ->suivant;
    }
    return 0;
}

int main()
{
    File f;
    InitFile(&f);
    AjouterP(&f, "Abdo");
    AjouterP(&f, "Dunya");
    AjouterP(&f, "Marwa");
    AjouterP(&f, "Juan");
    afficher(&f);
    Nombreavant(&f);
    return 0;
}
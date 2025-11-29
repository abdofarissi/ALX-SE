#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Etudiant
{
   char nom [30];
   float note ;
   char filiere [50];
};
void affichage(struct Etudiant T[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("----l'etudiant %d----\n", i +1);
        printf("Nom : %s\n", T[i].nom);
        printf("Filiere  : %s\n", T[i].filiere);
        printf("la Moyenne : %.2f\n", T[i].note);
    }
}

int main()
{
    int n;
    printf("saisir le nombre des etudiant : ");
    scanf("%d",&n);
    struct Etudiant *T;
    T = malloc(n * sizeof(struct Etudiant));

    for (int i = 0; i < n; i++)
    {
        printf("L'etudiant num %d\n", i +1);
        printf("nom : ");
        scanf("%s", T[i].nom);
        printf("Filiere : ");
        scanf("%s", T[i].filiere);
        printf("Note : ");
        scanf("%f", &T[i].note);
    }
    affichage(T, n);
    char temp[50];
    printf("saisir le nom d'etudiant a rechercher : ");
    scanf("%s", temp);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(temp, T[i].nom) == 0 )
        {
            printf("Modifier son nom : ");
            scanf("%s", T[i].nom);
        }
    }
    affichage(T, n);

    free(T);
    return 0;
}


#include<stdio.h>
#include<stdlib.h>

int main ()
{
    struct Equipe 
    {
        char nom_equipe [50];
        int victoires;
        int defaites;
        int points;
    };
    int n ;
    printf("saisir le nombre d'equipes :");
    scanf("%d", &n);
    struct Equipe e[n];

    for (int i = 0; i < n; i++)
    {
       printf("-----l'equipe num %d-----\n", i + 1);
       printf("le nom de l'equipe : ");
       scanf("%s",e[i].nom_equipe ) ;
       printf("le nombre des victoires : ");
       scanf("%d", &e[i].victoires);
       printf("le nombre des defaites : ");
       scanf("%d", &e[i].defaites);
    }
    for (int i = 0; i < n; i++)
    {
        printf("-----l'equipe num %d-----\n", i + 1);  
        printf("le nom de l'equipe : %s\n", e[i].nom_equipe);
        printf("le nombre des victoires : %d\n", e[i].victoires);
        printf("le nombre des defaites : %d\n", e[i].defaites);
        e[i].points =(e[i].victoires)* 2 + e[i].defaites; 
        printf("le nombre des  points : %d pts\n", e[i].points);
    }
    return 0;
}
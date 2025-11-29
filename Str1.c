#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    struct Personne
    {
        char nom [30];
        int anne ;
        char ville [30];
    };

    struct Personne e;
    printf("le nom du personne : ");
    scanf("%s", e.nom);
    printf("l'anne de naissance : ");
    scanf("%d", &e.anne);
    printf(" son ville : ");
    scanf("%s", e.ville);

    printf("La personne 1 \n");
    printf("son  nom %s\n", e.nom);
    printf("sa date de naissance : %d\n", e.anne);
    printf("son ville : %s\n", e.ville);
}
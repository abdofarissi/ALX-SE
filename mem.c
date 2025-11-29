#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n ;
    int *p;
    printf("saisir le nombre d'elements : ");
    scanf("%d", &n);

    p = malloc(n *sizeof(int));
    if (p == NULL)
    {
        printf("la memoir n'est pas alloué");
        return 0;
    }
    else {
            for (int i = 0; i < n; i++)
        {
            printf("T[%d] = ", i );
            scanf("%d", p + i);
        }
        int Somme = 0;
        for (int i = 0; i < n; i++)
        {
        Somme = Somme + *(p + i) ;
        }
        float moyenne = Somme/n ;
        printf("la somme des element est %d \nla moyenne des elements est  %.2f", Somme, moyenne);
        free(p);
    }
    return 0;
}
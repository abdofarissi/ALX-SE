#include<stdio.h>

int main()
{
    int n;
    printf("entrer la dimension des vecteurs : ");
    scanf("%d", &n);

    int U[n] , V[n];
    for (int i = 0; i < n ; i++)
    {
        printf("U[%d]= ", i);
        scanf("%d", &U[i]);
    }
    for (int i = 0; i < n ; i++)
    {
        printf("V[%d]= ", i);
        scanf("%d", &V[i]);
    }
    int PS = 0;
    for (int i = 0; i < n ; i++)
    {
        PS += U[i]* V [i];
    }
    printf("le produit scalaire de U et V = %d", PS);

    return 0;
}
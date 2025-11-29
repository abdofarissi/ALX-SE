#include <stdio.h>

int main()
{
    int N; 

    printf("entrer le nombre des elements : ");
    scanf("%d", &N);
    int T[N];
    for (int i = 0; i < N; i++)
    {
        printf("T[%d]= ", i);
        scanf("%d", &T[i]);
    }
    int S = 0;
    for (int i = 0; i < N; i++)
    {
        S += T[i];
    }

    printf("la somme des elements de tableau est %d.\n", S);
    int compteur = 0;
    for (int i = 0; i < N; i++) 
    {
        if (T[i] == N) 
        {
            compteur++;
        }
    }
    printf("L'element %d apparait %d fois dans le tableau.\n", N, compteur);
    int max = T[0];
    int pos = 0;
    for(int i = 0; i < N ; i++ )
    {
        if (T[i]> max)
        {   
            max = T[i];
            pos = i;
        }
    } 
    printf("le plus grand elements du tableau est %d sa position est  %d\n", max, pos); 
    int min = T[0];
    int pos2 = 0;
    for(int i = 0; i < N ; i++ )
    {
        if (T[i]< min)
        {   
            min = T[i];
            pos2 = i;
        }
    } 
    printf("le plus petit elements du tableau est %d sa position est  %d\n", min, pos2); 

    return 0;
}
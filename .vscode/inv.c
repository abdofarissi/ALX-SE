#include <stdio.h>

int main()
{
    int T[5];int V[5];
    for(int i = 0; i < 5; i++)
    {
        printf("T[%d]= ", i);
        scanf("%d", &T[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        V[5 - i-1]= T[i];
    }
    for (int i = 0; i < 5; i++)
    {
        printf("T[%d]= %d ,",i , T[i]);

    }
        printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("V[%d]= %d ,",i , V[i]);
    }
    return 0;
}
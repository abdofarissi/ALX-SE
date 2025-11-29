#include <stdio.h>

int echanger(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Tri_bulle(int T[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        
        for (int j = 0; j < n -i -1; j++)
        {
            /*> pour order Croissant et < pour decroissant*/
            if (T[j]> T[j + 1])
            {
                echanger(&T[j], &T[j +1]);
            }
            
        }
        
    }
}

int main()
{
    int n = 6;
    int T[]= {2, 5, 8, 1, 14, 0};
    Tri_bulle(T , n);
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", T[i]);
    }
    
    return 0;
}
#include <stdio.h>

void Tri_insert( int T[] , int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = T[i];
        int j = i -1;
        while (temp > T[j] && j>= 0 )
        {
            T[j + 1] = T[j];
            j--;
        }
        T[j + 1 ]=  temp;
    }
    
}

int main()
{
    int n = 6;
    int T[]= {2, 5, 8, 1, 14, 0};
    Tri_insert(T , n);
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", T[i]);
    }
    
    return 0;
}
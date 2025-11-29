#include<stdio.h>

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int T[], int low , int high)
{
    int pivot = T[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (T[j] <= pivot)
        {
            i++;
            exchange(&T[i], &T[j]);
        }
        
    }
    exchange(&T[i + 1], &T[high]);
    return (i +1) ;
    
}
void Sort(int T[], int low, int high)
{  
   if (low < high)
   {
        int pivot = partition(T, low , high);
        Sort(T, low, pivot -1);
        Sort(T, pivot +1 , high);
   }
}

int main()
{
    int n = 10;
    int T[]= {2, 5, 8, 1, 14, 0,20, 25, 9, 3};
    Sort(T, 0 , n -1);
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", T[i]);
    }
    
    return 0;
}
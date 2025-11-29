#include<stdio.h>
#include<stdlib.h>


struct Produit {
    int reference_piece;
    char categorie [20];
    char libelle [20];
    int prix ;
    int quantite_stock ;
   };

void echanger( int *a , int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
void Tri(struct Produit T[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
            int min = i;
            for (int j = i +1; j < n; j++)
            {
               if (T[j].reference_piece < T[min].reference_piece)
               {
                    min = j;
               }
               echanger(&T[min].reference_piece, &T[i].reference_piece);
            }
            
    }
}
int PrixT(struct Produit T[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += T[i].prix;
        }
        return sum;
    } 

int main ()
{   
   int n1, n2;
   printf("saisir la taille de T1 : ");
   scanf("%d", &n1);
   printf("saisir la taille de T2 : ");
   scanf("%d", &n2);
   struct Produit *T1;
   struct Produit *T2;

    T1 = malloc(n1 * sizeof(struct Produit));
    T2 = malloc(n2 * sizeof(struct Produit));

   Tri(T1, n1);
   Tri(T2, n2);

   PrixT(T1, n1);
   PrixT(T2 , n2);
   int n = n1 + n2;
   struct Produit Tf[n];
   int nfusion = 0;
   for (int i = 0; i < n1; i++)
   {
        Tf[nfusion++]= T1[i];
   }
   for (int i = 0; i < n2; i++)
   {
        Tf[nfusion++]= T2[i];
   }
   Tri(Tf, n);
   
   for (int i = 0; i < n; i++)
   {
        printf("-----Produit num %d\n-----", i);
        printf("le numéro de reference : %d\n", Tf[i].reference_piece);
        printf("la Categorie : %s\n", Tf[i].categorie);
        printf("libelle : %s\n", Tf[i].libelle);
        printf("le prix : %d dh\n", Tf[i].prix);
        printf("la quantité de stock : %d", Tf[i].quantite_stock);
   }
   
   return 0;

}
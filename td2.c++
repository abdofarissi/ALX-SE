#include <iostream>
using namespace std;


void saisie(int t[], int n){
   for (int i = 0; i < n; i++)
        do{
            cout << "t["<<i <<"]= ";
            cin >> t[i];
        
        if (t[i]< 0)
        {
            cout << "entrer un entier positive "<< endl;
        }
    }while(t[i]< 0);
}

void affiche(int t[], int n)
{
    cout << "le contenu du tableau  : "<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << "t["<<i <<"]= "<< t[i] << endl;
    }
    
}
int maximum(int t[], int n)
{
    int max = t[0];
    for (int i = 1; i < n; i++)
    {
       if (t[i] > max)
       {
         max = t[i];
       }  
    }
    return max;
}
void affiche_8(int t[], int n)
{   
    for (int i = 0; i < n; i++)
    {
        int dernier = t[i]%10; 
        if (dernier == 8)
        {
            cout << "t["<<i <<"]= "<< t[i] << endl;
        }  
    }
    
}
void nombre_3(int t[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i]% 3 == 0)
        {
           cout << "t["<<i <<"]= "<< t[i] << endl;
           sum += t[i];
        }
    }
    cout << "la somme des multiples de 3 est : "<<sum<< endl;

}
void ajout_dernier_chiffre(int t[], int n)
{
    for (int  i = 0; i < n; i++)
    {
        int last = t[i]%10;
        if (last == 2)
        {
            t[i] +=5; 
        }
    }
}
void occurrence_max(int t[], int n)
{
    int valeur_max = t[0];
    int max_occ = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (t[j] == t[i])
            {
                count ++;
            }
            
        }
        if (count > max_occ)
        {
            max_occ = count;
            valeur_max = t[i];
        }
    }
    cout << "Valeur la plus repetee = " << valeur_max << endl;
    cout << "Occurrences = " << max_occ << endl;

}
void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void tri_decroissant(int t[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (t[j] > t[min])
            {
                min = j;
            }
            
        }
        swap(&t[min], &t[i]);
    }
    cout<< "table triee en ordre decroissant "<<endl;
}


int main(){
    int taille;
    cout<< "saisir la taille du tableau : ";
    cin >> taille;
    int *t = new int[taille];

    saisie(t, taille);
    cout <<"le maximum est :" <<maximum(t, taille)<< endl;
    tri_decroissant(t, taille);
    affiche(t, taille);



    return 0;
}
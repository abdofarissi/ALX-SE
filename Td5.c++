#include <iostream>
using namespace std;

class pile_entier{
    int *pile;
    int hauteur, taille ;
    public :
        pile_entier(int t =20)
        {
            taille = t ;
            hauteur = 0;
            pile = new int[taille];
        }
        pile_entier(const pile_entier &p)
        {
            taille = p.taille;
            hauteur = p.hauteur;
            pile = new int [taille];

            for (int i = 0; i < hauteur; i++)
            {
                pile[i] = p.pile[i];
            }   
        }
        ~pile_entier()
        {
            delete [] pile;
        }
        int pleine()
        {
            if (hauteur == taille)
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        }
        int vide()
        {
            if (hauteur == 0)
            {
                return 1;
            }
            else 
            {
                return 0;
            }
            
        }
        void empiler(int val)
        {
            if (pleine() == 1)
            {
                cout<< "la pile est plein "<<endl;
            }
            else
            {
                pile[ hauteur] = val;
                hauteur ++;
            }
        }
        int depile()
        {
            if (vide()== 1)
            {
                cout<<"la pile est vide "<<endl;
                return -1;
            }
            else{
                int val = pile[hauteur -1];
                hauteur --;
                return val;
            }
        }
        int sommet ()
        {
            if (vide())
            {
               cout<<"la pile est vide "<<endl;
               return 0;
            }
            return pile[hauteur -1];
        }
        int longueur ()
        {
            return hauteur;
        }
        int rechercher(int val)
        {
            for (int i = 0; i < hauteur; i++)
            {
                if (pile[i]== val)
                {
                    cout<< "valeur trouvée a la position :"<<i<<endl;
                    return 1;
                }
            }   
            return 0;
                
        }
        void vider()
        {
            hauteur = 0;
        }
        void afficher()
        {   
            for (int i = 0; i < hauteur; i++)
            {
               cout<<"P["<<i<<"] = "<<pile[i]<<endl;
            }
        }
};

int main (){
    pile_entier p ;
    p.empiler(12);
    p.empiler(17);
    p.empiler(15);
    p.empiler(1468);
    p.afficher();
    p.depile();
    p.rechercher(15);
    p.afficher();
    cout<<"la longueur du pile est :" <<p.longueur()<<endl;
    return 0;
}
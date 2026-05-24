#include <iostream>
using namespace std;

class file_float {
    float *file;
    int taille, debut, fin, nb;

    public : 
        file_float(int t =20){
            taille = t;
            file = new float[taille];
            debut = 0;
            fin = 0;
            nb = 0;
        }
        file_float(const file_float &f)
        {
            taille = f.taille;
            debut = f.debut;
            fin = f.fin;
            nb = f.nb;
            for (int i = 0; i < nb; i++)
            {
                file[i] = f.file[i];
            }
        }
        ~file_float()
        {
            delete []file;
        }
        int pleine()
        {
            if (nb == taille)
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
            if (nb == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        void enfiler(float val)
        {
            if (pleine())
            {
                cout<<"la file est pleine"<<endl;
            }
            else
            {
                file[fin] = val;
                fin = (fin + 1) % taille;
                nb ++;
            }
        }
        float defiler()
        {
            if (vide())
            {
                cout<<"la file est vide"<<endl;
                return -1;
            }
            else
            {
                float val = file[debut ];
                debut = (debut -1)% taille;
                nb--;
                return val;
            }
        }
        float tete()
        {
            if (vide())
            {
                cout<<"la file est vide"<<endl;
                return -1;
            }
            return file[debut];
        }
        float queue()
        {
            if (vide())
            {
                cout<<"la file est vide"<<endl;
                return -1;
            }
            return file[fin];
        }
        int longueur()
        {
            return nb;
        }
        void afficher()
        {
            if (vide())
            {
                cout<<"la file est vide"<<endl;
            }
            else
            {
                for (int i = 0; i < nb; i++)
                {
                    cout<<"F["<<i<<"] = "<<file[i]<<endl;
                }
            }
        }
        int rechercher(float var)
        {
            for (int i = 0; i < nb; i++)
            {
                if (file[i] == var)
                {
                    cout<<"la valeur"<<var<< "trouvée a la position "<<i<<endl;
                    return 1;
                }
            }
            cout<< "la valeur non trouvée"<<endl;
            return 0;
        }
        float maximum()
        {
            
        }

};

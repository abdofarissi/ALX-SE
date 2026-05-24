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
            file = new float[taille];
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
                debut = (debut+ 1)% taille;
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
            int dernier = (fin - 1 + taille) % taille;
            return file[dernier];
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
                    int pos = (debut + i) % taille;
                    cout<<"F["<<pos<<"] = "<<file[pos]<<endl;
                }
            }
        }
        int rechercher(float var)
        {
            for (int i = 0; i < nb; i++)
            {
                int pos = (debut + i) % taille;
                if (file[pos] == var)
                {
                    cout<<"la valeur "<<var<< "trouvée a la position "<<pos<<endl;
                    return 1;
                }
            }
            cout<< "la valeur non trouvée"<<endl;
            return 0;
        }
        float maximum()
        {
             if (vide())
            {
                cout << "la file est vide" << endl;
                return -1;
            }
            float max = file[debut];
            for (int i = 1; i < nb; i++)
            {
                int pos = (debut + i) % taille;
                if (file[pos]> max)
                {
                    max = file[pos];
                }              
            }
            return max;
        }
        float minimum()
        {
            if(vide())
            {
                cout << "la file est vide" << endl;
                return -1;
            }
            float min = file [debut];
            for (int i = 0; i < nb; i++)
            {
                int pos = (debut + i)% taille;
                if (file[pos]< min)
                {
                    min = file[pos];
                }
            }
            return min;         
        }
        void vider()
        {
            nb = 0;
            fin = 0;
            debut = 0;
        }
};
int main()
{   
    file_float f;
    f.enfiler(12);
    f.enfiler(25);
    f.enfiler(47.35);
    f.enfiler(7);
    f.enfiler(87);
    f.enfiler(67);
    f.enfiler(8);
    f.afficher();
    f.rechercher(67);
    f.defiler();
    cout<<"le maximum est : "<<f.maximum()<<endl;
    cout<<"le minimum est : "<<f.minimum()<<endl;
    cout<<"la longeur est : "<<f.longueur()<<endl;
    cout<<"la téte est : "<<f.tete()<<endl;
    f.afficher();
}

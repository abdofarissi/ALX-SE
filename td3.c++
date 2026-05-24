    #include <iostream>
    #include <math.h>
    using namespace std ;

    class Complexe {
    
        float re , im;
        public : 
            Complexe (float reel , float imaginaire = 0){
                re = reel;
                im = imaginaire;
            }
        ~Complexe(){}
        float reel(){
        return re ;
        }
        float imaginaire()
        {
            return im;
        }
        float norme ()
        {
            return sqrt(re*re + im* im);
        } 
        void afficher(){
            cout<<"le nombre complexe est : "<<re<<" + "<<im<<"i"<< endl;
        }
        Complexe conjugue()
        {
            return Complexe(re, -im); 
        }
        Complexe somme(Complexe &z2)
        {
            return Complexe((re + z2.re) , (im +z2.im));
        }
        Complexe difference(Complexe &z2){
            return Complexe((re - z2.re) , (im - z2.im));
        }
        Complexe produit (Complexe &z2)
        {
            return Complexe((re * z2.re - im * z2.im) , (re * z2.im + im* z2.re ));
        }
    };

   int main()
{
    Complexe A(17, 5);
    Complexe B(3, 2);

    // Affichage des nombres
    cout << "A = ";
    A.afficher();

    cout << "B = ";
    B.afficher();

    // Norme
    cout << "Norme de A : " << A.norme() << endl;

    // Conjugue
    Complexe C = A.conjugue();
    cout << "Conjugue de A = ";
    C.afficher();

    // Somme
    Complexe S = A.somme(B);
    cout << "A + B = ";
    S.afficher();

    // Difference
    Complexe D = A.difference(B);
    cout << "A - B = ";
    D.afficher();

    // Produit
    Complexe P = A.produit(B);
    cout << "A * B = ";
    P.afficher();

    return 0;
}
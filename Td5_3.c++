#include <iostream>
#include <cstring>
using namespace std;

class chaine
{
    char *str;
    int longueur;
    public :
        chaine(const char *c = "")
        {
            longueur = strlen(c);
            str = new char[longueur +1];
            for (int i = 0; i < longueur; i++)
            {
                str[i] = c[i];
            }
        }
        chaine(const char *ch)
        {
            if (ch == nullptr)
            {
                str = new char[1]; 
                str[0] = '\0';
            }
            else
            {
                str = new char[strlen(ch) + 1];
                strcpy(str , ch);
            }
        }
        chaine(const chaine &ch)
        {
            longueur = ch.longueur;
            str = new char[longueur + 1];
            for (int i = 0; i < longueur; i++)
            {
                str[i]= ch.str[i];
            }
            str[longueur] = '\0';
        }
        ~chaine()
        {
            delete []str;
        }
        
        
};
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int valeur ;
    struct tree * g;
    struct tree * d;    
}tree;

tree * CreateN(int val)
{
    tree * new = (tree *)malloc(sizeof(tree));
    if (new == NULL)
    {
        printf("allocation memoire echouee");
        exit(1);
    }
    new ->valeur = val;
    new ->d = NULL;
    new ->g = NULL;
    return new;
}

tree * CreateTree()
{   
    tree * racine = CreateN(8);
    racine ->g = CreateN(3);
    racine ->d = CreateN(10);
    racine ->g->g = CreateN(1);
    racine ->g->d = CreateN(6);
    racine ->d ->d = CreateN(14);
    racine ->d ->d ->g = CreateN(13);
    racine ->g ->d->g = CreateN(4);
    racine ->g ->d ->d= CreateN(7);
    return racine;
}

int haut(tree * n)
{
    if (n == NULL)
    {
        return 0;
    }
    int g = haut(n ->g);
    int d = haut(n ->d);
    if (g > d)
    {
        return g + 1;
    }
    else
    {
        return d +1 ;
    }
}
tree* recherche(tree * r , int val)
{
    if (r ==NULL)
    {
        return NULL;
    }
    if (r ->valeur == val)
    {
        return r ;
    }
    tree * trouve_g = recherche(r ->g, val);
    if (trouve_g != NULL)
    {
       return trouve_g;
    }
    return recherche(r ->d , val);

}

int prof(tree * r, int val, int prof_actuell)
{
    if (r == NULL)
    {
       return -1;
    }
    if (r ->valeur == val)
    {
        return prof_actuell;
    }
    int P_g = prof(r->g , val, prof_actuell +1);
    if (P_g != -1)
    {
       return P_g;
    }
    return prof(r->d, val , prof_actuell +1);
}
void afficher_pro_haut(tree * r,int val)
{
    tree * Cible = recherche(r, val);
    if (Cible == NULL)
    {
        printf("le noeud a valeur %d non trouvee \n", val);
        return;
    }
    
    printf("la hateur du noeud a valeur %d est :%d \n", val, haut(Cible));
    printf("la profondeur du noeud a valeur %d est :%d \n",val,prof(r, val,0));
}
tree * trouver_par(tree * r, int val)
{
    if (r == NULL || r ->valeur == val)
    {
        return NULL;
    }
    if ((r ->g || r->g->valeur == val )&& (r->d || r->d->valeur == val))
    {
        return r;
    }
    if (val < r->valeur )
    {
        return trouver_par(r->g, val);
    }
    else
    {
        return trouver_par(r->d, val);
    }

}
int trouver_frere(tree * r, int val)
{
    tree * parent = trouver_par(r, val);
    if (parent == NULL)
    {
        return -1;
    }
    if (parent->g && parent->g->valeur == val)
    {
        if (parent ->d)
        {
            return parent->d->valeur;
        }
        else 
        {
            return -1;
        }
    }
    if (parent ->d && parent ->d->valeur == val)
    {
       if (parent->g)
       {
            return parent ->g ->valeur;
       }
       else
       {
        return -1;
       }
       
    }
    return -1;
}

int main ()
{
    tree * racine = CreateTree();
    afficher_pro_haut(racine, 8);
}
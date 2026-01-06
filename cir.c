#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int valeur;
    struct Node * suivant ;
}Node;

Node * Cree(int val)
{
    Node * new = (Node* )malloc(sizeof(Node));
    new ->valeur = val;
    new ->suivant = NULL;
    return new;

}
void afficher (Node *head)
{
    if (head == NULL)
    {
       printf("la liste deja vide \n");
    }
    else 
    {
        Node *courant = head;
        do{
            printf("%d ->", courant ->valeur);
            courant = courant ->suivant;
        }while (courant != head);

        printf("(Retourn a la head)\n");
    }
}
int Taille(Node *head)
{
    int taille =0;
    if (head == NULL)
    {
       printf("la liste deja vide \n");
    }
    else 
    {
        Node *courant = head;
        do
        {
            taille++;
           courant = courant ->suivant;
        } while (courant != head);
    }
    return taille;
}

void Recherche(Node * head, int val)
{
    if (head == NULL)
    {
        printf("la liste est vide \n");
    }
    else
    {
        Node *courant = head;
        int pos = 0;
        do
        {
            pos++;
            if (val == courant ->valeur)
            {
                printf("l'element %d trouvee dans la noeud num %d\n", courant->valeur , pos);
                return;
            }
            courant = courant ->suivant;

        } while (courant != head);
        printf("l'element non trouvee\n");
    }
    
}

Node * InsererM(Node *head, int val)
{
    int pos ;
    printf("ajouter a la position  : ");
    scanf("%d", &pos);
    Node * new = Cree(val);
    int t = Taille(head);
    if (head == NULL)
    {
        printf("la liste est vide \n");
        new ->suivant = new;    
        return new;
    }
    Node *cour = head;
    if (pos <1 || pos > t +1)
    {
        printf("position invalide \n");
    }

    if (pos == 1)
    {
        while (cour ->suivant != head)
        {
            cour = cour ->suivant;
        }
        new ->suivant = head;
        cour ->suivant = new;
        return new;
        
    }
    do
    {
        for (int i = 0; i < pos -2; i++)
        {
            cour = cour ->suivant;
        }
        new ->suivant = cour ->suivant;
        cour ->suivant = new;
        return head;
    } while (cour != head);
    return new;
}
int main ()
{
    Node *head = NULL;
    Node *First = Cree(25);
    Node *Second = Cree(45);
    Node *tail = Cree (742);

    head = First;
    First ->suivant = Second;
    Second ->suivant = tail;
    tail ->suivant = head;

    afficher(head);
    InsererM(head, 14);
    afficher(head);

}

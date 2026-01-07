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
Node * InsererD(Node * head, int val)
{
    Node * new = (Node* )malloc(sizeof(Node));
    new ->valeur = val;
    if (head == NULL)
    {
        new ->suivant = new;
        return new;
    }
    Node * courant = head;
    while (courant->suivant != head)
    {
       courant = courant ->suivant;
    }
    new ->suivant = head;
    courant ->suivant = new;
    return new;
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
    if (pos <1 || pos > t+1)
    {
        printf("position invalide \n");
        free(new);
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
    for (int i = 1; i < pos - 1; i++)
        {
            cour = cour ->suivant;
        }
        new ->suivant = cour ->suivant;
        cour ->suivant = new;
        return head;
}
Node * I_fin(Node *head, int val)
{
    Node * new = Cree(val);
    if (head == NULL)
    {
       new ->suivant = new;
       return new;
    }
    Node *courant = head;
    while (courant ->suivant != head)
    {
       courant = courant ->suivant;
    }
    courant ->suivant = new; 
    new ->suivant = head;
    return head;
}
Node * SupprimerD(Node *head)
{
    if (head == NULL)
    {
        printf("la liste est deja vide \n");    
        return NULL;
    }
    if (head ->suivant == head)
    {
       free(head);
       return NULL;
    }
    
    Node * courant = head;
    while (courant->suivant != head)
    {
       courant = courant ->suivant;
    }
    Node * newhead = head->suivant;
    courant ->suivant = newhead;
    free(head);
    return newhead;
}
Node * SuppF(Node * head)
{
    if (head == NULL)
    {
       printf("la liste est deja vide \n");
       return NULL;
    }
    if (head ->suivant == head)
    {
       free(head);
       return NULL;
    }
    Node * courant = head;
    while (courant ->suivant->suivant != head)
    {
        courant = courant ->suivant ;
    }
    Node * temp = courant ->suivant;
    courant ->suivant = head;
    free(temp);
    return head;

}
Node * SuppM(Node * head)
{
    int p ;
    printf("saisir la position a supprimer : ");
    scanf("%d", &p);
    int t = Taille(head);
    if (head == NULL)
    {
        printf("la liste est deja vide \n");
        return head;
    }
    if (head ->suivant == head)
    {
       free(head);
       return NULL;
    }
    if (p < 1 || p > t )
    {
        printf("Position invalide \n");
        return NULL;
    }
    if (p == 1)
    {
        Node * courant = head;
        while (courant->suivant != head)
        {
            courant = courant ->suivant;
        }
        Node * newhead = head->suivant;
        courant ->suivant = newhead;
        free(head);
        return newhead;
    }
    if (p == t)
    {
        Node * courant = head;
        while (courant ->suivant->suivant != head)
        {
            courant = courant ->suivant ;
        }
        Node * temp = courant ->suivant;
        courant ->suivant = head;
        free(temp);
        return head;
    }
    Node * courant = head;
    for (int i = 1; i < p -1; i++)
    {
       courant = courant ->suivant;
    }
    Node * temp = courant ->suivant;
    courant ->suivant = temp ->suivant;
    free(temp);
    return head;
    
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
    head =  SuppM(head);
    afficher(head);
}

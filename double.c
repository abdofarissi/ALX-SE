#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int valeur;
    struct Node * suivant;
    struct Node * precedent;
}Node;

Node * Cree(Node *head, int val)
{
    Node* new = (Node*)malloc (sizeof(Node));
    if (new == NULL)
    {
       printf("allocation dynamique echouee \n");
       exit(1);
    }
    new ->valeur = val;
    new ->suivant = NULL;
    new ->precedent = NULL;
}
Node * Supprimer(Node * head, int val)
{
    Node * courant = head;
    while (courant != NULL && courant->valeur != val)
    {
        courant = courant->suivant;
    }
    if (courant == NULL)
    {
       printf("la valeur non trouvee \n");
       return head;
    }
    if (courant == head)
    {
        head = head->suivant;
        if (head != NULL)
        {
            head->precedent = NULL;
        }
        free(courant);
        return head;
    }
    else if (courant ->suivant != NULL)
    {
        courant->suivant ->precedent  = courant ->precedent;
    }
    courant ->precedent ->suivant = courant ->suivant;
    free(courant);
    return head;
}

void afficher(Node * head)
{
    if (head == NULL)
    {
       printf("la liste est vide \n");
    }
    Node * courant = head;
    while (courant != NULL)
    {
        printf("%d ->", courant ->valeur);
        courant = courant ->suivant;
    }
    printf("NULL\n");

}
int taille(Node * head)
{
    int t = 0;
    Node * courant = head ;
    while (courant != NULL)
    {
        t++;
        courant = courant ->suivant;
    }
    return t;

}
Node * AjouterD(Node * head, int val)
{
    Node * new = (Node*)malloc (sizeof(Node));
    new ->valeur = val;
    if (head != NULL)
    {
        new ->suivant = head;
        new ->precedent = NULL;
    }
    head = new ;
    return head;
}
Node * AjouterM(Node *head, int val)
{
    Node * new = (Node*)malloc (sizeof(Node));
    new ->valeur = val;
    int p ;
    printf("saisir la position :");
    scanf("%d", &p);
    int t = taille(head);
    if (p < 1 || p > t +1)
    {
       printf("Position invalide \n");
       return NULL;
    }
    if (p == 1)
    {
        new ->suivant = head;
        head = new;
        return head ;
    }
    
    Node * courant = head;
    for (int i = 1; i < p -1 ; i++)
    {
        courant = courant ->suivant;
    }
    new ->suivant = courant ->suivant;
    new ->precedent = courant ;
    courant->suivant->precedent = new; 
    return head;

}
int main()
{
    Node * head;
    Node * first = Cree(head, 58);
    Node * second = Cree(head, 45);
    Node * tail = Cree(head, 30);

    head = first ;
    first ->suivant = second;
    second ->precedent = first ;
    second ->suivant = tail;
    tail ->precedent = second ;

    afficher(head);
    head = Supprimer(head, 30);
    afficher(head);

    return 0;
}
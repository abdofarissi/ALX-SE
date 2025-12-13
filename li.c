#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int donne;
    struct Node *suivant;
} Node;

Node *Cnode(int donne)
{
    Node *newN = (Node*) malloc(sizeof(Node));
    newN->donne = donne;
    newN->suivant = NULL;
    return newN;
}

void afficher(Node *head)
{
    Node *courant = head;
    while (courant != NULL)
    {
        printf("%d -> ", courant->donne);
        courant = courant->suivant;
    }
}

int main()
{
    Node *head = NULL;
    Node *first = Cnode(6);
    Node *second = Cnode(12);
    Node *tail = Cnode(24);

    head = first;
    first->suivant = second;
    second->suivant = tail;

    afficher(head);

    return 0;
}

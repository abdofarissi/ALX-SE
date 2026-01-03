#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant{
    char nom[20];
    int age;
    float moyenne;
    struct Etudiant *suivant;
}Etudiant;

Etudiant *CreeEtudiant(char nom[10], int age, float moyenne)
{
    Etudiant *newEtu;
    newEtu = (Etudiant *) malloc(sizeof(Etudiant));
    if (newEtu == NULL)
    {
        printf("Erreur : allocation memoire echoue \n");
        return NULL;
    }
    strcpy(newEtu ->nom , nom);
    newEtu ->age = age;
    newEtu ->moyenne = moyenne;
    newEtu ->suivant = NULL;
    return newEtu;
}
void afficher(Etudiant *head)
{
    Etudiant *courant = head;
    while (courant != NULL)
    {
        printf("Nom : %s \n ", courant ->nom);
        printf("Age : %d \n", courant ->age);
        printf("Moyenne : %.2f \n", courant ->moyenne);
        courant =courant -> suivant;
    }
    

}
int taille(Etudiant *head)
{
    int taille = 0;
    Etudiant *courant = head;
    while (courant != NULL)
    {
        courant = courant ->suivant;
        taille ++;
    }
    return taille;
}
void Recherche(Etudiant *head, char nom[10])
{
    Etudiant *piv = head;
    while (piv != NULL)
    {
        if (strcmp(nom , piv ->nom ) == 0)
        {
            printf("l'etudiant trouvee ! \n");
            printf("Nom : %s \n ", piv ->nom);
            printf("Age : %d \n", piv ->age);
            printf("Moyenne : %.2f \n", piv ->moyenne);
            break;
        }
        piv = piv ->suivant;
    }
}
void R_indice(Etudiant *head, int indice)
{
    Etudiant *temp = head;
    int i = 0;
    while (temp != NULL && i < indice)
    {
        temp = temp->suivant;
        i++;
    }

    if (temp != NULL)
    {
        printf("etudiant trouve !\n");
        printf("Nom : %s\n", temp->nom);
        printf("Age : %d\n", temp->age);
        printf("Moyenne : %.2f\n", temp->moyenne);
    }
    else
    {
        printf("Indice invalide : étudiant non trouvé\n");
    }
}
Etudiant *Supprimer(Etudiant * head)
{
    if (head == NULL)
    {
       printf("la list est deja vide .\n");
       return NULL;
    }
        Etudiant *temp = head;
        head = head -> suivant;
        free(temp);
        return head;

}
Etudiant *SuppF(Etudiant * head)
{
    if (head == NULL)
    {
        printf("le list est deja vide \n");
        return NULL;
    }
    Etudiant *courant = head;
    if (courant ->suivant == NULL)
    {
        free(courant);
        return NULL;
    }
    while (courant->suivant->suivant != NULL)
    {
        courant = courant -> suivant;
        free(courant ->suivant);
        courant ->suivant = NULL;
        return head;
    }
}
Etudiant* insererD(Etudiant *head , char nom[10], int age, float moyenne)
{
    Etudiant *newEtu;
    newEtu = (Etudiant *) malloc(sizeof(Etudiant));
    strcpy(newEtu ->nom , nom);
    newEtu ->age = age;
    newEtu ->moyenne = moyenne;
    newEtu ->suivant = NULL;
    if (head != NULL)
    {
        newEtu ->suivant = head ;
    }
    head = newEtu;
    return head;
}
Etudiant *insererF(Etudiant *head , char nom[10], int age, float moyenne)
{
    Etudiant *newEtu = malloc(sizeof(Etudiant));
    if (newEtu == NULL)
    {
       return newEtu;
    }
        strcpy(newEtu ->nom , nom);
        newEtu ->age = age;
        newEtu ->moyenne = moyenne;
        newEtu ->suivant = NULL;
    if (head == NULL)
    {
        return newEtu;
    }
    Etudiant * courant = head ;
    while (courant->suivant != NULL)
    {
        courant = courant ->suivant;
    }
    courant->suivant = newEtu;
    return head;
}
Etudiant *SuppM(Etudiant *head, int pos)
{
    if(head == NULL)
    {
       printf("la liste est deja vide ");
       return NULL; 
    }
    int taille = 0;
    Etudiant *courant = head;
    while (courant != NULL)
    {
        courant = courant ->suivant;
        taille ++;
    }
    if (pos <  1 || pos > taille)
    {
        printf("position invalide \n");
        return head;  
    }   
    Etudiant  *temp = head ;
    if (pos == 1)
    {
        head = head ->suivant;
        free(temp);
        return head;
    }
    Etudiant *courant2 = head;
    for (int i = 1; i < pos -1 ; i++)
    {
        courant2 = courant2 ->suivant;
    }
        temp =courant2 ->suivant;
        courant2 ->suivant = temp ->suivant;
        free(temp);
        return head;

}
Etudiant *Modifier(Etudiant *head)
{
    char nom [50];
    int age ;
    float Moyenne;
    printf("Modifier le nom : ");
    scanf("%s", nom);
    printf("Modifier l'age : ");
    scanf("%d", &age );
    printf("Modifier la moyenne :");
    scanf("%f",&Moyenne );
    if (head == NULL)
    {
        printf("la list est vide ");
        return NULL;
    }
    strcpy(head ->nom , nom); 
    head ->age = age;
    head ->moyenne = Moyenne;
    return head;

}
Etudiant *insererM(Etudiant *head ,char nom[20], int age , float Moyenne)
{
    int pos ;
    printf("entre la position : ");
    scanf("%d", &pos);
    if(head == NULL)
    {
        printf("la liste est vide \n");
        return NULL;
    }
    Etudiant *new ;
    new = (Etudiant *)malloc(sizeof(Etudiant));
        strcpy(new ->nom , nom);
        new ->age = age;
        new ->moyenne = Moyenne;
        new ->suivant = head;
    int taille = 0;
    Etudiant * comp = head;
    while (comp != NULL)
    {
       comp = comp ->suivant ;
       taille ++;
    }
    if (pos <1 || pos > taille)
    {
        printf("position invalide \n");
        return NULL;
    }
    if (pos == 1)
    {   
        new ->suivant = head;
        return new;
    }
    Etudiant *courant = head;
        for (int i = 0; i < pos -1; i++)
        {
            courant = courant->suivant;
        }
        new ->suivant = courant ->suivant;
        courant ->suivant = new;
        return head;

}
Etudiant *ModifierM(Etudiant * head)
{
    int p ;
    printf("Saisir la position :");
    scanf("%d", &p);
    if (head == NULL)
    {
        printf("la liste est vide \n");
        return head;
    }
    int a = taille(head);
    if (p < 1 || p > a)
    {
        printf("position invalide \n");
        return head;
    }
    char N_nom[20];
    int N_age ;
    float N_moyenne;
    if (p == 1)
    {
        printf("Nouveau nom : ");
        scanf("%s", N_nom);
        printf("Nouvel age : ");
        scanf("%d", &N_age);
        printf("Nouvelle moyenne : ");
        scanf("%f", &N_moyenne);
        strcpy(head ->nom, N_nom);
        head ->age = N_age;
        head ->moyenne = N_moyenne;
        return head;
    }
    Etudiant *courant = head;
    for (int  i = 1; i < p ; i++)
    {
        courant = courant ->suivant;
      
    }
        printf("Nouveau nom : ");
        scanf("%s", N_nom);
        printf("Nouvel age : ");
        scanf("%d", &N_age);
        printf("Nouvelle moyenne : ");
        scanf("%f", &N_moyenne);

        strcpy(courant ->nom, N_nom);
        courant ->age = N_age;
        courant ->moyenne = N_moyenne;
    
         return head;
}

int main()
{
    Etudiant * head ;
    Etudiant *first = CreeEtudiant("Abdo", 20, 15);
    Etudiant *second = CreeEtudiant("Simo", 19, 10);
    Etudiant *tail = CreeEtudiant("Sakai", 24, 17);

    head = first;
    first ->suivant = second;
    second ->suivant = tail;
    tail ->suivant = NULL;
    head = ModifierM(head);
    afficher(head);
   
}
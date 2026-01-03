#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct article
{
    int code;
    int categoriee;
    char nom[20];
    float prix;
    int quantite; 
    struct article *suiv;
}liste;

liste* creerArticle(int code, int categorie, char nom[], float prix, int quantite)
{
    liste *new = (liste *)malloc(sizeof(liste));
    if (new == NULL)
        return NULL;

    new->code = code;
    new->categoriee = categorie;
    strcpy(new->nom, nom);
    new->prix = prix;
    new->quantite = quantite;
    new->suiv = NULL;

    return new;
}
void affichage(liste *head)
{
    if (head == NULL)
    {
        printf("La liste est vide.\n");
        return;
    }

    liste *courant = head;
    int num = 1;

    while (courant != NULL)
    {
        printf("\n========== Article %d ==========\n", num);
        printf("Nom       : %s\n", courant->nom);
        printf("Code      : %d\n", courant->code);
        printf("Categorie : %d\n", courant->categoriee);
        printf("Prix      : %.2f\n", courant->prix);
        printf("Quantite  : %d\n", courant->quantite);

        courant = courant->suiv;
        num++;
    }

    printf("\n=================================\n");
}
liste * ajouterFin(liste * head)
{
    int ncode , ncateg, nquant;
    char Nnom [20];
    float nprix;
    printf("Ajout d'un article \n");
    printf("le Nom : ");
    scanf ("%s", Nnom);
    printf("le code :");
    scanf("%d", &ncode);
    printf("la categorie : ");
    scanf("%d", &ncateg);
    printf("la quantite : ");
    scanf("%d", &nquant);
    printf("le prix : ");
    scanf("%f", &nprix);

    liste * new = (liste *)malloc(sizeof(liste));
    if (new == NULL)
    {
        return new;
    }
    strcpy(new ->nom , Nnom);
    new ->code =ncode;
    new ->categoriee = ncateg;
    new ->quantite = nquant;
    new ->prix = nprix ;
    if (head == NULL )
    {
        return new;
    }
    liste * courant = head;
    while (courant ->suiv != NULL)
    {
       courant = courant ->suiv;
    }
    courant ->suiv = new;
    return head;
}
liste * ModifierparCode(liste * head)
{
    int car;
    printf("saisir le code d'article a rechercher : ");
    scanf("%d", &car);
    liste * courant = head;
    if (head == NULL)
    {
        printf ("la liste est deja vide \n");
        return head;
    }
    float Nprix;
    int Nquantite;
    while (courant != NULL)
    {
        if (courant ->code == car)
        {
            printf("Modifier le prix :");
            scanf("%f", &Nprix);
            printf("Modifier la quantite :");
            scanf("%d", &Nquantite);
            courant ->prix = Nprix;
            courant ->quantite = Nquantite;
            return head;
        }
        courant = courant ->suiv;    
    }
}
liste * SupprimerparCode(liste *head)
{
     int car;
    printf("saisir le code d'article a supprimer  : ");
    scanf("%d", &car);
    if (head == NULL)
    {
        printf ("la liste est deja vide \n");
        return head;
    }
    liste * courant = head;
    liste *temp = NULL;
    while (courant != NULL)
    {
        if (courant ->code  == car)
        {
            if (temp == NULL)
            {
                head = courant ->suiv;
            }
            else
            {
                temp ->suiv = courant ->suiv;
            }
            free(courant);
            printf("l'article supprimee !! \n");
            return head;
        }
        temp = courant;
        courant = courant ->suiv;
    }
    printf("L'article non trouvee \n");
    return head ;
}
void Calculer(liste *head)
{
    int sum = 0;
    liste * courant = head ;
    if (head == NULL)
    {
        printf("la liste est vide \n");
    }
    while (courant != NULL)
    {
        sum = sum + courant ->quantite;
        courant = courant ->suiv;
    }
    printf ("la quantite totale du stock est : %d", sum);
}
liste * moyenne(liste *head)
{
    liste * temp = head;
    if (head == NULL)
    {
        printf("la liste est vide \n ");
        return head;
    }
    while (temp != NULL)
    {
        int cat = temp->categoriee;
        int totalArticle = 0;
        float PrixTotale = 0;
        liste *courant = head;
        while (courant != NULL)
        {
            if (courant ->categoriee == cat)
            {
                totalArticle ++;
                PrixTotale +=  courant ->prix;
            }
            courant = courant ->suiv;
        }
        float moyenne = (totalArticle > 0) ? PrixTotale / totalArticle : 0;
        printf("Categorie %d : Moyenne des prix = %.2f\n", cat, moyenne);
        temp = temp->suiv;
    }
}

int main()
{
    liste * head ;
    liste * first = creerArticle(523, 3, "Sbat", 150,200);
    liste * second = creerArticle(420,2 , "cuira", 700, 620);
    liste * tail = creerArticle (751, 2 , "Jacket", 400, 1000);
    int choix ;
    head = first ;
    first -> suiv = second;
    second -> suiv = tail;
    tail ->suiv = NULL;

do
    {
        printf("\n===== MENU =====\n");
        printf("1. Afficher la liste des articles \n");
        printf("2. Ajouter un article a la fin\n");
        printf("3. Modifier un article par code\n");
        printf("4. Supprimer article par Code \n");
        printf("5. Calculer la quantite totale \n");
        printf("6. La moyenne de prix de chaque categorie\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                affichage(head);
                break;
            
            case 2:
                head = ajouterFin(head);
                break;

            case 3:
                head = ModifierparCode(head);
                break;
            case 4:
                head = SupprimerparCode(head);
                break;
            case 5 :
                Calculer(head);
                break;
            case 6 :
                head = moyenne(head);
                break;
            case 0:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide !\n");
        }

    } while (choix != 0);

    return 0;

}

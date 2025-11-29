#include <stdio.h>
#include<string.h>

typedef struct {
    char marque[50];
    char modele[50];
    int annee;
    float prix;
} Voiture;

void SaisirVoiture(Voiture *v) {
    printf("Entrez la marque de la voiture : ");
    scanf("%s", v->marque);
    printf("Entrez le modèle de la voiture : ");
    scanf("%s", v->modele);
    printf("Entrez l'année de fabrication : ");
    scanf("%d", &v->annee);
    printf("Entrez le prix de la voiture : ");
    scanf("%f", &v->prix);
}
void AffichezVoiture(Voiture *v)
{
    printf("la marque de la voiture est  %s\n", v->marque);
    printf("le modele de la voiture est  %s\n", v->modele);
    printf("l'anne  de fabrication est  %d\n", v->annee);
    printf("la prix de la voiture est  %f\n", v->prix);
}
void SaisirListeVoiture(Voiture v[], int taille)
{
    for(int i = 0; i < taille ; i++)
    {
        printf("Entrez la marque de la voiture : ");
        scanf("%s", v[i].marque);
        printf("Entrez le modele de la voiture : ");
        scanf("%s", v[i].modele);
        printf("Entrez l'annee de fabrication : ");
        scanf("%d", &v[i].annee);
        printf("Entrez le prix de la voiture : ");
        scanf("%f", &v[i].prix);
    }
}
void AfficherListeVoitures(Voiture v[], int taille)
{
    for (int i = 0; i < taille ; i++)
    {
        printf("la marque de la voiture est  %s\n",v[i].marque);
        printf("le modele de la voiture est  %s\n",v[i].modele);
        printf("l'anne  de fabrication est  %d\n",v[i].annee);
        printf("la prix de la voiture est  %.2f\n",v[i].prix);
    }
}
void RechercherVoiturePlusChere(Voiture v[], int taille)
{
    int max = 0;
    for(int  i = 1; i < taille; i++)
    {
       if(v[max].prix < v[i].prix){
           max = i;
       }
       printf("la voiture la plus cher est %s modele :%s cout %.2f \n", v[max].marque, v[max].modele, v[max].prix);
    }
   
}
void RechercherVoitureParMarque(Voiture v[], int taille)
{
    char cher[30];
    printf("entrer la marque du voiture :");
    scanf("%s", cher);
    int trouver = 0;
    for(int i = 0; i < taille ; i++)
    {
        if (strcmp(v[i].marque, cher)== 0)
        {
            printf("la marque est %s , son Modele est %s, l'anne de fabrication %d, Prix = %.2f\n",v[i].marque, v[i].modele, v[i].annee, v[i].prix);
            trouver = 1;
            break;
        }
        if (!trouver)
        {
            printf("la marque n'a pas ete trouver dans le tableau\n");
        }

    }
}
int main()
{  
    int n;
    printf("entrer le nombre des voitures : ");
    scanf("%d", &n);
    Voiture voitures[n]; 
    SaisirListeVoiture(voitures, n);
    AfficherListeVoitures(voitures, n);
    RechercherVoiturePlusChere(voitures, n);
    RechercherVoitureParMarque(voitures, n);

    return 0;
}


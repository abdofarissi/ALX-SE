#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max 100

typedef struct
{
    char Nom[30];
    char adresse[50];
    char email[30];
    char Num[20];  
    char Code[10]; 
    char DateN[20];
} Contact;

    FILE *F;   

void ajouter_enregistrement(Contact *r)
{
    printf("Entrer le numero telephonique : ");
    scanf("%s", r->Num); 
    
    printf("Entrer le nom du personne : ");
    scanf("%s", r->Nom);
    
    printf("Entrer l'adresse : ");
    scanf(" %[^\n]", r->adresse); 
    
    printf("Entrer la date de naissance (JJ/MM/AAAA) : ");
    scanf("%s", r->DateN);
    
    printf("Entrer l'adresse e_mail : ");
    scanf("%s", r->email);
    
    printf("Entrer le Code de departement : ");
    scanf("%s", r->Code);
    F = fopen("Contacts.txt", "a");
    if (F == NULL)
        {
            printf("Erreur lors de l'ouverture du fichier.\n");
        }
    else 
    {
        fprintf(F, "Nom : %s \n",r->Nom);
        fprintf(F, "Num : %s \n",r->Num);
        fprintf(F, "date de naissance : %s \n",r->DateN);
        fprintf(F, "Adresse : %s \n",r->adresse);
        fprintf(F, "email : %s \n",r->email);
        fprintf(F, "Code de departement : %s \n",r->Code);
        fclose(F);
    }
}

int contient(Contact R[], int taille, char nom[], char code[])
{
    for (int i = 0; i < taille; i++)
    {
        if(strcmp(R[i].Nom, nom) == 0 && strcmp(R[i].Code, code) == 0)
        {
            return i;
        }
    }
    return -1;
}

int annuaireInvers(Contact R[], int taille, char telephone[], char nom[], char code[])
{
    for (int i = 0; i < taille; i++)
    {
        if(strcmp(R[i].Num, telephone) == 0)
        {
            strcpy(nom, R[i].Nom);
            strcpy(code, R[i].Code);
            return 1;
        }
    }
    return 0;
}
int enlever_par_nom(Contact R[], int *taille, char nom[], char code[])
{
    int index = contient(R, *taille, nom, code);
    for (int i = index; i < *taille; i++)
    {
        R[i]= R[i+1];
    }
    (*taille)--;
    return 1;
}
int enlever_par_num(Contact R[], int *taille, char telephone[])
{
    for (int i = 0; i < *taille; i++)
    {
        int index = (strcmp(R[i].Num, telephone) == 0);
        for (int j = index; j < *taille; j++)
        {
            R[j]= R[j++];
        }
    }
    (*taille)--;
    return -1;

}
int comparerContacts(const void *a, const void *b) {
    const Contact *A = (const Contact *)a;
    const Contact *B = (const Contact *)b;
    
    int cmpNom = strcmp(A->Nom, B->Nom);
    if (cmpNom != 0) 
    return cmpNom;
    
    int cmpDept = strcmp(A->Code,B->Code);
    if (cmpDept != 0) 
    return cmpDept;
    
    return strcmp(A->Num,B->Num);
}

void trier(Contact R[], int *taille)
{
   for (int i = 0; i < *taille; i++)
   {
       qsort(R, *taille, sizeof(Contact), comparerContacts);
   }
   printf("Contacts trieé avec succees");
}
void afficherContact(const Contact *contact,int *taille)
{
    for (int i = 0; i < *taille; i++)
    {
        printf("le Contact num %d :\n", i+1);
        printf("Nom : %s\n", contact[i].Nom);
        printf("Numero  : %s\n", contact[i].Num);
        printf("adresse : %s\n", contact[i].adresse);
        printf("email : %s\n", contact[i].email);
        printf("Code de departement : %s\n", contact[i].Code);
    }

}

int main()
{
    Contact repertoire[Max];
    int nb_contacts = 0;
    int choix;
    
    do {
        printf("\n=====Menu=====:\n");
        printf("1. Ajouter un contact\n");
        printf("2. Rechercher par nom et departement\n");
        printf("3. Recherche inversee par telephone\n");
        printf("4. Supprimer par nom et departement\n");
        printf("5. Supprimer par numero\n");
        printf("6. Trier le repertoire\n");
        printf("7. Afficher tous les contacts\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                if(nb_contacts < Max) {
                    ajouter_enregistrement(&repertoire[nb_contacts]);
                    nb_contacts++;
                    printf("Contact ajoute avec succes!\n");
                } else {
                    printf("Repertoire plein!\n");
                }
                break;
                
            case 2: {
                char nom[30], code[10];
                printf("Nom: ");
                scanf("%s", nom);
                printf("Code departement: ");
                scanf("%s", code);
                
                int index = contient(repertoire, nb_contacts, nom, code);
                if(index != -1) {
                    printf("Contact trouve:\n");
                } else {
                    printf("Contact non trouve.\n");
                }
                break;
            }
                
            case 3: {
                char tel[20], nom[30], code[10];
                printf("Numero telephone: ");
                scanf("%s", tel);
                
                if(annuaireInvers(repertoire, nb_contacts, tel, nom, code)) {
                    printf("Nom: %s\n", nom);
                    printf("Departement: %s\n", code);
                } else {
                    printf("Numero non trouve.\n");
                }
                break;
            }
            case 4:{
                char Nom[30], Code[10];
                printf("Entrer le Nom : ");
                scanf("%s", Nom);
                printf("Entrer le Code : ");
                scanf("%s", Code);
                if (enlever_par_nom(repertoire, &nb_contacts, Nom, Code))
                {
                    printf("Contact Supprimee \n");
                }
                else 
                {
                    printf("Contact non Trouve.\n");
                }
                break;
            }
            case 5: 
            {
                char num[20];
                printf("Numero de telephone : ");
                scanf("%s", num);
                if (enlever_par_num(repertoire, &nb_contacts, num))
                {
                    printf("Contact Supprimee \n");
                }
                else 
                {
                    printf("Contact non Trouve.\n");
                }
                break;
            }
            case 6: 
            {
                trier(repertoire, &nb_contacts);
                break;
            }
            case 7: 
            {
                afficherContact(repertoire, &nb_contacts);
                break;
            }
        }
    } while(choix != 0);
    
    return 0;
}
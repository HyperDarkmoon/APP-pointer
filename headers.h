#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char d[20],type[20];
    int q;
}aide;
typedef struct {
    char dele[20];
    int CIN,nbr;
}famille;




int verifier_exit( aide TA[], int nA, char designation[]);
void saisir_aide(aide *A);
void ajouter_aide(aide TA[],int *nA,aide A);
void afficher_aide(aide TA[],int nA);
void remplir_famille(famille TF[], int nF);
void afficher_famille(famille TF[], int nF);
void max_min_aide(aide TA[],int nA,int *minn,int *maxx);
int max_membre(famille TF[],int nF);
void supprimer(famille TF[],int *nF,int pos);
void affecter_aide(famille TF[],int *nF,aide TA[],int nA);
void controler_stock(aide TA[],int nA,aide TStock[],int *nS);


#include "headers.h"
#include <string.h>

int verifier_exit( aide TA[], int nA, char designation[]) {
    int i,p;
    p=-1;
    for (i=0;i<nA;i++) {
        if (strcmp(TA[i].d,designation)==0) {
            p=i;
        }
    }
    return(p);
}

void saisir_aide(aide *A) {
    printf("donner la designation \n");
    scanf("%s",A->d);
    do {
        printf("donner le type \n");
        fflush(stdin);
        gets(A->type);
        fflush(stdin);
    } while((strcmp(A->type,"couverture")!=0)&&(strcmp(A->type,"denre alimentaire")!=0)&&(strcmp(A->type,"matelas")!=0));
    printf("donner la quantite \n");
    scanf("%d",&A->q);
}

void ajouter_aide(aide TA[],int *nA,aide A) {
    int k;
    k=verifier_exit(TA,*nA,A.d);
    if (k==-1) {
        TA[*nA]=A;
        *nA=*nA+1;
    }
    else
        TA[k].q=TA[k].q+A.q;
}

void afficher_aide(aide TA[],int nA) {
    int i;
    for (i=0;i<nA;i++) {
        printf("l aide N : %d \n",i+1);
        printf("la designation est : %s \n",TA[i].d);
        printf("le type est : %s \n",TA[i].type);
        printf("la quantite est  : %d \n",TA[i].q);
    }
}

void remplir_famille(famille TF[], int nF) {
    int i;
    for(i=0;i<nF;i++) {
        printf("donner la CIN \n");
        scanf("%d",&(TF[i].CIN));
        printf("donner le nombre de famille \n");
        scanf("%d",&TF[i].nbr);
        printf("donner la delegation \n");
        fflush(stdin);
        gets(TF[i].dele);
        fflush(stdin);
    }
}

void afficher_famille(famille TF[], int nF) {
    int i;
    for(i=0;i<nF;i++) {
        printf("la CIN est : %d\n",TF[i].CIN);
        printf("le nombre de famille est : %d \n",TF[i].nbr);
        printf("la delegation est :%s \n",TF[i].dele);
    }
}

void max_min_aide(aide TA[],int nA,int *minn,int *maxx) {
    int i;
    (*maxx)=TA[0].q;
    (*minn)=TA[0].q;
    for (i=1;i<nA;i++) {
        if (TA[i].q>(*maxx)) {
            (*maxx)=TA[i].q;
        }
        if (TA[i].q<(*minn)) {
            (*minn)=TA[i].q;
        }
    }
}

int max_membre(famille TF[],int nF) {
    int i,max,pos;
    max=TF[0].nbr;
    pos=0;
    for (i=0;i<nF;i++) {
        if (TF[i].nbr>max) {
            max=TF[i].nbr;
            pos=i;
        }
    }
    return pos;
}

void supprimer(famille TF[],int *nF,int pos) {
    int i;
    for (i=pos;i<(*nF)-1;i++) {
        TF[i]=TF[i+1];
    }
    *nF=*nF-1;
}

void affecter_aide(famille TF[],int *nF,aide TA[],int nA) {
    int max,i;
    char c[50];
    max=max_membre(TF,*nF);
    do {
        printf("donner le type \n");
        fflush(stdin);
        gets(c);
        fflush(stdin);
    } while((strcmp(c,"couverture")!=0)&&(strcmp(c,"denre alimentaire")!=0)&&(strcmp(c,"matelas")!=0));
    for (i=0;i<nA;i++) {
        if ((TA[i].q>0) && strcmp(c,TA[i].type)) {
            if (TA[i].q<TF[max].nbr) {
                TF[max].nbr=TF[max].nbr-TA[i].q;
            }
            else {
                TA[i].q=TA[i].q-TF[max].nbr;
                supprimer(TF,nF,max);
            }
        }
    }
}


void controler_stock(aide TA[],int nA,aide TStock[],int *nS) {
    int i;
    for (i=0;i<nA;i++) {
        if (TA[i].q<=5) {
            TStock[*nS]=TA[i];
           *nS=*nS+1;
        }
    }
}

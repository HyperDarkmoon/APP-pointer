#include "headers.h"

int main() {
    aide TA[100];
    aide A;
    aide TStock[100];
    famille TF[100];
    int choix,nA=0,nF,nS=0,minn,maxx,i;
    do {
        printf("Saisir votre choix \n");
        printf("1- ajouter une aide \n");
        printf("2- afficher le tableau des aides \n");
        printf("3- remplir le tableau de famille \n");
        printf("4- afficher les familles  \n");
        printf("5- Trouver l'aide la plus demander et la moins \n");
        printf("6- affecter une aide a une famille \n");
        printf("7- Controle des stock des aides \n");
        printf("0-Quitter\n");
        printf("donner votre choix \n");
        scanf("%d",&choix);
        switch(choix)
        {
            case 1:
                saisir_aide(&A);
                ajouter_aide(TA,&nA,A);
                break;
            case 2:
                afficher_aide(TA,nA);
                break;
            case 3:
                printf("donner le nombre de famille \n");
                scanf("%d",&nF);
                remplir_famille(TF,nF);
                break;
            case 4:
                afficher_famille(TF,nF);
                break;
            case 5:
                max_min_aide(TA,nA,&minn,&maxx);
                printf("Le max daide = %d\nLe min daide = %d\n",minn,maxx);
                break;
            case 6:
                affecter_aide(TF,&nF,TA,nA);
                printf("Opreation termine\n");
                break;
            case 7:
                controler_stock(TA,nA,TStock,&nS);
                printf("Operation termine\n");
                printf("Le tableau de control de stock:\n");
                for (i=0;i<nS;i++) {
                    printf("quantite:%d\n",TA[i].q);
                }
                break;
            case 0:
                printf("Program termine\n");
                break;
            default :
                printf("choix invalid\n");
                break;
        }
    } while (choix!=0);
    return 0;
}

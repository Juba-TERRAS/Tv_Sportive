#include "TV_LLC_BIBLIO.c"
#include "TV_LLC_BIBLIO.h"
int main()
{
    struct Calendrier *P,*Q;
    struct RANG *T;
    struct llceq *R,*S;
    int choix,inter=0,bool=0;/*inter et bool1 sont des booleen qui vont nous servir de repere
    par exemple si un utilisateur remplit le calendrier des matchs alors inter se mettra a 1
    comme sa si l utilisateur veut afficher le contenu du calendrier alors il ne vas pas remplir a nouveau le
    calendrier par contre si il affiche le calendrier sans l avoir remplit alors il est automatiquement redirigé vers
    le remplissage*/
 system("color 15");/*canger la couleur du fond de la console*/
 system("mode con LINES=35 COLS=130");/*redimensioner la console*/
 loading();
 acceil();
  do
 {
    system("cls");
    affich_menu();
    Sleep(200);
    printf("Veillez introduire votre choix : ");/*lecture du choix*/
    scanf("%d",&choix);/*On lis le choix de l'utilisateur*/
    switch(choix)
    {
    case 1:
        Affichage_classement();
    Color(14,1);
    printf("\n                                                         Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
    break;
/*********************************************************************************************************************************************/
    case 2:
    Remplissage_Rang();
    Color(14,1);
    printf("\n                                                        Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
    break;

/*********************************************************************************************************************************************/
    case 3:
    Affichage_Rang();
    Color(14,1);
    printf("\n                                                        Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
    break;

/*********************************************************************************************************************************************/
    case 4:
    R=creation_llceq();
    affichage_llceq(R);
    Color(14,1);
    printf("\n                                                         Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
    break;

/*********************************************************************************************************************************************/
    case 5:
    P=Remplissage_Calendrier();
    Color(14,1);
    printf("\n                                                        Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
    inter=1;/*pour le match a difuser c est a dire l utilisateur  a remplit le calendrier*/
    break;

/*********************************************************************************************************************************************/
    case 6:
     if(inter==1)/*l utilsateur a deja cré le calendrier*/
     {
     Affichage_planing(P);
     }
     else
     {
      P=Remplissage_Calendrier();/*sinon il est redirigé vers la creation*/
      Affichage_planing(P);
      inter=1;
     }
    Color(14,1);
    printf("\n                                                        Appuyez sur n'import quelle touche pour terminer l'operatione ");
    getch();
    break;

/*********************************************************************************************************************************************/
    case 7:
        if(inter==1)
        {
            R=creation_llceq();
            match_a_difuser(R);
        }
        else
        {
         R=creation_llceq();
         P=Remplissage_Calendrier();
         match_a_difuser(R);
         inter=1;
        }
    Color(14,1);
    printf("\n                                                         Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
    break;

/*********************************************************************************************************************************************/
    case 8:
        if(inter==1 )/*l utilsateur a deja cré le calendrier*/
        {
           Q=saisit_resultats(P);
           bool=1;
        }
        else
        {
        P=Remplissage_Calendrier();/*sinon il est redirigé vers la creation*/
        Q=saisit_resultats(P);
        inter=1;
        bool=1;
        }
    Color(14,1);
    printf("\n                                                         Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
        break;

/*********************************************************************************************************************************************/
    case 9 :
        if(inter==1 && bool==0)/*si l utilsateur a juste cree le calendrier*/
        {
          R=creation_llceq();
          Q=saisit_resultats(P);
          S=mise_a_jour_llceq(R,Q);
          tableau_llceq(S);
        }
         if(inter==1 && bool==1)/*si l utilsateur a  cree le calendrier et saisi les resultats des matchs*/
        {
          R=creation_llceq();
          S=mise_a_jour_llceq(R,Q);
          tableau_llceq(S);
        }
        else
        {
           R=creation_llceq();
           P=Remplissage_Calendrier();
           Q=saisit_resultats(P);
           S=mise_a_jour_llceq(R,Q);
           tableau_llceq(S);
        }
    Color(14,1);
    printf("\n                                                         Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
    break;

/*********************************************************************************************************************************************/
    case 10:
        Affichage_new_Rang();
    Color(14,1);
    printf("\n                                                         Appuyez sur n'import quelle touche pour terminer l'operation ");
    getch();
    break;

/*********************************************************************************************************************************************/
    case 11:
        Color(2,1);
        printf("\n\n");
        printf("                               MERCI DE VOTRE ATTENTION EST PASSEZ UNE AGREABLE JOURNEE  ");
        Sleep(2000);
    break;

/*********************************************************************************************************************************************/
    default:
        Color(12,1);
        printf("\n\n");
        printf("                                      CHOIX INVALID! VEILLEZ REESSAYER SVP \n\n");
        Sleep(1000);
        break;

/*********************************************************************************************************************************************/
}
}while(choix!=11);
 thanks();
 Color(15,1);
    return 0;
}


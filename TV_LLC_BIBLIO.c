#include "TV_LLC_BIBLIO.h"

 /*******************************************************************************************************************************************************************/
                                                               /*CREATION FICHIER RANG*/
 /*******************************************************************************************************************************************************************/
/*---------------------------------------------------------PARTIE DECLARATION DES FONCTION UTILISES ----------------------------------------------------------------*/
 /*******************************************************************************************************************************************************************/
/*procedure qui va permetre d afficher le classement du championat actuel*/
void Affichage_classement()
            {
                int cpt=0;/*compteur pour la place de lequipe dans le championat*/
                char text[256];/* text est une chaine de caractere*/
                FILE *fich=fopen("equipe.txt","r");/*On ouvre le fichier equipe.txt qui contient les noms des equipes selon leur classement actuel du championat en lecture*/
                Color(11,1);
                printf("----------------------------------------------------------------------------------------------------------------------------\n");
                Color(13,1);
                printf("|                                             CLASSEMENT DU CHAMPIONAT                                                     |\n");
                Color(11,1);
                printf("----------------------------------------------------------------------------------------------------------------------------\n");
                while(fgets(text,255,fich)!=NULL)/*on procede a la lecture de ligne par ligne jusqu a arriver a null c est a dire a
                    la fin du fichier*/
                {
                 Sleep(500);
                 cpt++;
                 Color(14,1);
                 printf("%d",cpt);
                 Color(13,1);
                 printf(")");
                 Color(11,1);
                 printf("-");
                 Color(15,1);
                 printf(" %s\n",text);/*On ecrit le nom de l equipe ainsi que sa place dans le chmpionat*/
                 }
                printf("---------------------------------------------------------------------------------------------------------------------------\n");
            }
 /*******************************************************************************************************************************************************************/
/*procedure qui va permettre le remplissage du fichier rang.txt*/
void Remplissage_Rang()
             {
               int i,npt,nbj,nbg,nbn,nbp,BP,BC,cpt=0;
               char mot[26];
               FILE *fich=fopen("equipe.txt","r");/*On ouvre en lecture le fichier contanant les noms des equipes afin
               de les extraire*/
               FILE *fichier=fopen("rang.txt","w");/*On ouvre le fichier rang.txt en ecriture afin de pouvoir ecrire les differentes
               données des equipes*/
               Color(11,1);
               printf("---------------------------------------------------------------------------------------------------------------------------\n");
               Color(13,1);
               printf("                                   REMPLISSAGE DU FICHIER RANG \n");
               Color(11,1);
               printf("---------------------------------------------------------------------------------------------------------------------------\n");
               printf("\n");
               for(i=0;i<16;i++)/*un boucle pour de 16 iterations soit 16 equipes*/
               {   cpt++;/*un compteur pour le classment*/
               Color(13,1);
               printf("                                             %d du classement\n",cpt);/*affichage*/
               Color(11,1);
               printf("---------------------------------------------------------------------------------------------------------------------------\n",cpt);
               /*On lit les differnetes donnes concernat chaque equipe*/
               Color(15,1);
               printf("1- donnez LE NOMBRE TOTAL DES POINTS : ");
               scanf("%d",&npt);
               printf("\n");
               printf("2- donnez LE NOMBRE DE MATCHS JOUES : ") ;
               scanf("%d",&nbj) ;
               printf("\n");
               printf("3- donnez LE NOMBRE DE MATCHS GAGNES : ");
               scanf("%d-",&nbg) ;
               printf("\n");
               printf("4- donnez LE NOMBRE DE MATCHS NULS : ");
               scanf("%d-",&nbn) ;
               printf("\n");
               printf("5- donnez LE NOMBRE DE MATCHS PERDUS : ");
               scanf("%d",&nbp) ;
               printf("\n");
               printf("6- donnez LE NOMBRE DES BUTS MARQUES : ");
               scanf("%d",&BP) ;
               printf("\n");
               printf("7- donnez LE NOMBRE DES BUTS ENCASSES : ");
               scanf("%d",&BC) ;
               printf("\n");
               /*On ecrit les differnetes information de chaque equipe dans le fichier rang.txt grace a la fonction fprintf*/
               fprintf(fichier ,"%d ",i+1);
               fgets( mot,255,fich);/*On extrait le nom de l equipe du fichier equipe.txt*/
               fprintf(fichier,"%s                        ",mot);
               fprintf(fichier,"%d  ",npt);
               fprintf(fichier,"%d  ",nbj);
               fprintf(fichier,"%d  ",nbj);
               fprintf(fichier,"%d  ",nbn);
               fprintf(fichier,"%d  ",nbp);
               fprintf(fichier,"%d  ",BP);
               fprintf(fichier,"%d  ",BC);
               fprintf(fichier,"%d\n",(BP-BC));

    }
                fclose(fichier);
                fclose(fich);
 }
 /*******************************************************************************************************************************************************************/
 /*procedure qui va permettre d afficher le contenu du fichier rang.txt*/
void Affichage_Rang()
{
                int i,cpt=0,rang;
                char mot [255];
                FILE *fich=fopen("rang.txt","r");/*ouverture en lecture du fichier rang.txt*/
                Color(11,1);
                printf("---------------------------------------------------------------------------------------------------------------------------\n");
                Color(13,1);
                printf("|                                           LE CONTENU DU FICHIER RANG                                                    |\n");
                Color(11,1);
                printf("---------------------------------------------------------------------------------------------------------------------------\n");
                for(i=0;i<16;i++)
                {
                    fscanf(fich,"%d",&rang);/*on lit le rang de l equipe qui est en premeir*/
                    Color(11,1);
                    fgets(mot,255,fich);/*on lit le nom de l equipe*/
                    Color(14,1);
                    Sleep(500);
                    printf(" %s",mot);/*on affiche le nom de l equipe*/
                    Color(11,1);
                    Sleep(500);
                    fgets(mot,255,fich);/*on lit la ligne contenant les diverses informations*/
                    printf(" %s\n",mot);/*on affiche le contenu de la ligne precedente*/
                    printf("---------------------------------------------------------------------------------------------------------------------------\n");
                }
               fclose(fich);/*fermeture du fichier*/
}
 /*******************************************************************************************************************************************************************/
                                                                      /*CREATION DE LLCEQ*/
 /*******************************************************************************************************************************************************************/
/*--------------------------------------------------------PARTIE IMPLEMENTATION DES FONCTIONS DE LA MACHINE ABSTRAITE-----------------------------------------------*/
 /*******************************************************************************************************************************************************************/

/*la fonction ALLOUER1 permet de reserver un espace memoire pour une structure de type llceq*/
struct llceq *ALOUER1()
{
    return((struct llceq*)malloc(sizeof(struct llceq)));
};

/*la focntion ALLOUER2 permet de reserver un espace memoire pour une structure de type RANG*/
struct RANG *ALOUER2()
{
    return((struct RANG*)malloc(sizeof(struct RANG)));
};

/*la fonction AFF_ADR_B permet d affecter une adresse au champs bah de llceq*/
void AFF_ADR_B(struct llceq *P,struct llceq*Q)
{
    P->bah=Q;
}

/*la fonction AFF_ADR_D permet d affecter une adresse au champs droit de llceq*/
void AFF_ADR_D(struct llceq *P,struct RANG *Q)
{
    P->droit=Q;
}

/*la fonction AFF_ADR permet d affecter une adresse au champs suivant de RANG*/
void AFF_ADR(struct RANG *P,struct RANG *Q)

{
   P->suivant=Q;
}

/*retourne l adresse contenu dans le champs suivant de RANG*/
struct RANG *SUIVANT(struct RANG *P)
{
    return (P->suivant);
};

/*retourne l adresse contenu dans le champs bah de llceq*/
struct llceq *BAH(struct llceq *P)
{
    return (P->bah);
};

/*retourne l adresse contenu dans le champs droit de llceq*/
struct llceq *DROIT(struct llceq *P)
{
    return (P->droit);
};
/*******************************************************************************************************************************************************************/
/*---------------------------------------------------------PARTIE DECLARATION DES FONCTION UTILISES ----------------------------------------------------------------*/
 /*******************************************************************************************************************************************************************/
struct llceq *creation_llceq()/*fonction de creation de llceq*/
{
/*1)-Partie declaration des variables utilises:*/

   struct llceq *P,*Q,*tete=NULL;/*P,Q,et tete sont tous des pointeurs vers la structure llceq*/
   struct RANG *S,*R;/*S et R sont des pointerus vers la structure RANG*/
   char c;int i,j=0;/*i et j sont des variable de controle de boucle tant dit que c est un caractere dont nous allons nous
                     servir afin d extraire d un fichier contenat les lettre de l alphabet afin de remplir les maillons de type
                     llceq avec ces lettres*/
   char mot[256];/*mot  est une chaine de caracteres dont nous allons nous servir afin d extraire
                                  les noms des equipes du fichier rang.txt*/
   int rang,npt,nbj,nbg,nbn,nbp,bp,bc,diff,inter;/*inter est un entier dont nous allons nous servir comme d un booleen
                                                  tandit que les autres entiers vont faire references de varibles qui vont
                                                  contenir les differentes informations lues a partie du fichier rang.txt
                                                  comme npt:nombre de points,nbj:nombre de matchs joues...*/

   FILE *fichier=fopen("lettre.txt","r+");/*fichier est un pointeur vers le fichier contenat les lettres de l alphabet*/

/*2)-la partie creations de la liste des maillons de alphabet:*/

   for(i=0;i<26;i++)/*un boucle pour allant de 1 a 26 soit 26 lettre de l alphabet*/
   {
        P=ALOUER1();/*on alloue un espace memoire pour un maillon de type llceq*/
        c=fgetc(fichier);/*on procede a la lecture d un caractere du fichier contenat les lettres de alphabet*/
        P->lettre=c;/*on affecte c au champs lettre de llceq qui est de type caractere*/
        AFF_ADR_B(P,NULL);/*on affecte NULL au champs bah de P*/
        AFF_ADR_D(P,NULL);/*on affecte NULL au champs droit de P*/
        if(tete==NULL)
        {
            tete=P;
            Q=P;
        }       /*creation standard d une llc*/
        else
        {
            AFF_ADR_B(Q,P);
            Q=P;
        }
   }
    fclose(fichier);/*on procede a la fermeture du fichier contant les lettres de l aplhabet */

/*3)- Partie creation des maillons de type RANG et chainage avec les maillons de type llceq*/

    P=tete;/*On initialise P a tete afin de pouvoir manipuler la liste*/

    while(P!=NULL)
    {
        inter=0;/*On initialise notre inter a 0*/
        c=P->lettre;/*on lit la lettre stockée dans le maillon llceq*/
        FILE *fich=fopen("rang.txt","r+");/*fich est un pointeur vers le fichier rang.txt contenat les noms des equipes ainsi que leurs informations*/

        for(i=0;i<16;i++)
        {
            fscanf(fich,"%d",&rang);/* On lit la premiere donnée du fichier rang.txt qui est le rang de l equipe dans le championat*/
            fgets(mot,50,fich);/* On lit la dexieme donnée du fichier rang.txt qui est le nom de l equipe et on la stocke dans mot*/
            fscanf(fich,"%d %d %d %d %d %d %d %d",&npt,&nbj,&nbg,&nbn,&nbp,&bp,&bc,&diff);/* On lit les autres données du fichier rang.txt*/
            if(c==mot[1])/*Si on retrouve que "c" et la premiere lettre du mot sont identique alors on entre dans la boucle de creation*/
            {
                  S=ALOUER2();/*On alloue un espace memoire pour un maillon de type RANG*/
                  AFF_ADR(S,NULL);/*On affecte NULL au champs suivant de RANG*/
                  if(inter==0)/*le role du booleen ici est de faire en sorte que l affectation des adresses entre maillon
                    de type llceq et maillon de type RANG se fasse q une seule fois car c est un cas particulier*/
                   {
                    inter=1;/*une fois entré dans la boucle on le met a 1 pour ne pas revenir dans cette boucle car on aura
                    chainé les deux maillons de types differents mais les suivants seront de meme type c est a dire tous de type RANG*/
                    strcpy(S->Eq,mot);/*on copie le nom de l equipe dans le champs Eq*/
                    S->Rang=rang;
                    S->NpT=npt;
                    S->NbJ=nbj;
                    S->NbG=nbg;
                    S->NbN=nbn;/*c est valable pour les autres informations */
                    S->NbP=nbp;
                    S->bp=bp;
                    S->bc=bc;
                    S->Diff=diff;
                    AFF_ADR_D(P,S);/*on affecte a P de type llceq l adresse du premier maillon de type RANG afin de proceder au chainage*/
                    R=S;/*On postione aussi R qui est un pointeur sur maillon de type RANG pour avancer dans le chainage*/

                  }
                  else/*un fois le inter a 1 on force toujours la boucle a entrer dans le sinon*/
                  {
                    S->Rang=rang;
                    S->NpT=npt;
                    S->NbJ=nbj;
                    S->NbG=nbg;/*meme chose on procede a l affectations des informations aux champs du maillons de type RANG*/
                    S->NbN=nbn;
                    S->NbP=nbp;
                    S->bp=bp;
                    S->bc=bc;
                    S->Diff=diff;
                    strcpy(S->Eq,mot);
                    AFF_ADR(R,S);/*par contre ici l affectation se fait entre deux maillon de meme type c est a dire on met l adress du nouveau maillon
                    de type RANG crée dans le champs suivant du maillon precedent de meme type */
                    R=S;/*On postione aussi R qui est un pointeur sur maillon de type RANG pour avancer dans le chainage*/
                  }
            }

        }

        fclose(fich);/*le but de fermer ici le fichier c est que pour chaque lettre d alphabet on procede a la lecture de toute  les equipes
        ce qui implique l arrive a la fin du fichier donc on aura besoin de recommencer de 0 donc on ferme et a la prochaine iteration le fichier s ouvre de
        nouveau*/
        P=BAH(P);/*On aura besoin d avancer dans la liste des maillon contenat l alphabet et cella se fait grace a la fonction Bah*/
    }
    printf("\n");
 return tete;/*On retourna la l adresse de la tete de llceq pour pouvoir la manipuler plus tard*/
}
 /*******************************************************************************************************************************************************************/
void Color(int couleurDuTexte,int couleurDeFond) /* fonction d'affichage de couleurs*/
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
 /*******************************************************************************************************************************************************************/

void affichage_llceq(struct llceq *tete)/*afficher le contenu de llceq*/
{
    struct llceq *P;/*P est un pointeur vers un maillon de type llceq*/
    struct RANG *S;/*S est un pointeur vers un maillon de type RANG*/
    P=tete;/*le pointeur P recevera la tete pour pouvoir manipuler la liste*/
         Color(11,1);
         printf("  ----------------------------------------------------------------------------------------------------------------------\n");
         Color(13,1);
         printf("  |                                                        LISTE EQ                                                    |\n");/*affichage*/
         Color(11,1);
         printf("  ----------------------------------------------------------------------------------------------------------------------\n");
        int  i=0;
    while(P!=NULL)
    {
        if(DROIT(P)!=NULL)/*ici le but de faire cette condition est d empecher l affichage des maillons
            de l alphabet n ayant aucun maillon de type RANG chainé avec lui c est a dire dans le champs droit c est NULL*/
        {
        printf("\n");
        Sleep(1000);
        S=DROIT(P);/*On affecte a S le contenu du champs droit de P*/
        Color(11,1);
        printf("----\n");
        Color(14,1);
        printf("%c |\n",P->lettre);/*On affiche la lettre correspendante au maillon de type llceq*/
        Color(11,1);
        printf("----\n");
        while(S!=NULL)/*tant que S est different de NULL :on va commencer le parcours des maillons de type RANG*/
        {
          Color(11,1);
          printf(" -");
          Color(15,1);
          printf("%s",S->Eq);/*On affiche le nom de l equipe correspendante*/
          S=SUIVANT(S);/*On avance dans la lecture des maillons de type RANG grace a la fonction SUIVANT*/
        }
        }

        P=BAH(P);/*On avances dans les maillons de type llceq grace a la fonction BAH*/
    }
    printf("\n");
    Color(11,1);
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    Color(15,1);

}
 /*******************************************************************************************************************************************************************/
                                                                /*CREATION DU CALENDRIER*/
 /*******************************************************************************************************************************************************************/
/*-------------------------------------------------------PARTIE IMPLEMENTATION DES FONCTIONS DE LA MACHINE ABSTRAITE------------------------------------------------*/
 /*******************************************************************************************************************************************************************/
/*la fonction allouer: reserver un espace memoire pour un maillon de type calendrier*/
struct Calendrier *ALLOUER()
{
return((struct Calendrier*)malloc(sizeof(struct Calendrier)));
}

/*la fonction aff-adr_cal :affecter une adress au champs suivant d un maillon de type calendrier*/
void AFF_ADR_CAL(struct Calendrier *P,struct Calendrier *Q)
{
    P->suivant=Q;
}

/*la fonction SUIVANT:retourne l adress du stockée dans le champs suivant du maillon de type calendrier */
struct Calendrier *SUIVANT_CAL(struct Calendrier *P)
{
    return(P->suivant);
};
 /*******************************************************************************************************************************************************************/
/*---------------------------------------------------------------PARTIE DECLARATION DES FONCTIONS UTILISES----------------------------------------------------------*/
 /*******************************************************************************************************************************************************************/
/*fonction qui va permetre le remplissage de la liste calendrier*/
struct Calendrier *Remplissage_Calendrier()
{
/*1)-Partie declaration des variables utilises:*/

      int choix;/*pour laisser le choix a lutilisateur soit remplir le calendrier automatiquement ou manuellement*/
      int cpt=0,i=0,j=0;/*cpt un compteur et i et j sont des variables de controle de boucle*/
      Calendrier *P,*Q,*tete=NULL;/*P ,Q et tete sont des pointeurs vers des maillons de type Calendrier*/
      char inter1[256];char inter2[256];/*inter 1 et 2 sont des mots intermediaire pour stocker les noms des equipes*/
      char c;
      system(" color 15");
      system("mode con LINES=35 COLS=130");
do/*le but de la boucle pour c est de se deparasser du cas ou l utilisateur introduit un choix different de 1 ou 2*/
{
      Color(11,1);
      printf("----------------------------------------------------------------------------------------------------------------------------\n");
      Color(13,1);
      printf("|                                               REMPLISSAGE DU CALENDRIER                                                  |\n");/*affichage*/
      Color(11,1);
      printf("----------------------------------------------------------------------------------------------------------------------------\n");
      Color(3,1);
      Color(14,1);
      printf("Donnez votre choix: \n");/*On laisse le choixa lutilisateur*/
      Color(3,1);
      printf("-------------------\n\n");
      Color(11,1);
      printf("             1) Saisir manuelement les noms des equipes.\n\n");
      printf("             2) Lire les noms des equipes a partir d un fichier.\n\n");
      Color(3,1);
         printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
      Color(15,1);
/*2)-Partie remplissage des nom des equipes qui vont s affronter:*/
     printf("Saisisez votre choix :  ");
      scanf("%d",&choix);/*on effectue un lecture*/
if (choix==1)/*Si l utilisateur a choisis 1 c est a dire remplir manuellement*/
{
         FILE *fich=fopen("planing.txt","w");/*On ouvre le un fichier nommé planing.txt .A chaque fois quon lit
         le nom d une equipe on l ecrit dans ce fichier afin d etre utilise plut tard dans le match a difuser*/
         for (i=0;i<8;i++)/*un boucle pour de 8 iteration chaque iteration pour deux equipes soit  16 equipes*/
         {
            cpt++;/*pour numeroter les matchs*/
            P=ALLOUER();/*Reservation d un espace memoire pur un maillon de type Calendrier*/
            printf("------------\n");
            Color(14,1);
            printf("MATCH num %d:  \n",cpt);
            Color(15,1);
            printf("------------\n");
            Color(11,1);
            printf("Donnez le nom de l equipe recevante: ");/*On commence par ecrire le nom de l equipes recevante*/
            Color(15,1);
                      do/*une boucle repeter qui va s arreter lorsque l utilisateur aura rentrer un point*/
                      {
                            c=getche();/*on lit a chaque fois caractere par caractere grace a la fonction getche*/
                            if(c=='.')/*Si l utilsateur a introduit un points on arrete la boucle de lecture*/
                            {
                                inter1[j]='\0';/*On marque la fin du mot inter1*/
                                fprintf(fich," %s\n",inter1);/*On ecrit le nom de la premiere equipe dan le fichier planing.txt
                                en laissant un vide ce vide sera primordiale pour l execution du programme.On a preocede ainsi
                                pour des soucis d execeution du programme*/
                                j=0;
                            }
                            else
                            {
                                inter1[j]=c;/*On construit notre inter1*/
                                j++;/*On avance dans le tableau de caractere qui est inter 1*/
                            }
                     }while(c!='.');
            Color(11,1);
            printf("\n");
            printf("Donnez le nom de l equipe visiteuse: ");/*On lit le nom de l equipes visiteuse*/
            Color(15,1);
                    do/*On repete le meme traitement precedent sauf qu au lieu d utiliser inter 1 on utilise inter 2 et on ecrit
                        le nom de la dexieme equipe dans planing.txt*/
                    {
                           c=getche();
                           if(c=='.')
                            {
                               inter2[j]='\0';
                               fprintf(fich," %s\n",inter2);
                               j=0;
                            }
                            else
                            {
                              inter2[j]=c;
                              j++;
                            }
                     }while(c!='.');

                     printf("\n");
        }
                      fclose(fich);/*On ferme le fichier planing.txt*/
                      fich=fopen("planing.txt","r");/*On ouvre le fichier planing.txtx afin d y extraire le noms des equipes*/
        for (i=0;i<8;i++)/*un boucle pour de 8 iteration chaque iteration pour deux equipes soit  16 equipes*/
         {
                     P=ALLOUER();/*Reservation d un espace memoire pur un maillon de type Calendrier*/
                     fgets(P->Eq1,25,fich);/*On extrait le nom de la premiere equipe et on l affecte a P->Eq1*/
                     fgets(P->Eq2,25,fich);/*On extrait le nom de la premiere equipe et on l affecte a P->Eq2*/
                     AFF_ADR_CAL(P,NULL);/*On affecte au champs suivant de P : NULL*/
                     if(tete==NULL)/*creation standard de liste*/
                     {
                     tete=P;
                     P->Res=00;/*On affecte a RES:00*/
                     Q=P;
                     }
                     else
                     {
                     AFF_ADR_CAL(Q,P);
                     P->Res=00;/*On affecte a RES:00*/
                     Q=P;
                     }
        }
        fclose(fich);
}
if (choix==2)/*Si l utilisateur a choisis de remplir le calendrier automatiquement*/
{
          FILE *fichier=fopen("Calendrier.txt","r");/*On ouvre le fichier nommée Calendrier.txt contenant les noms des equipes qui vont s affronter*/
          FILE *fich=fopen("planing.txt","w");/*On ouvre le fichier planing.txt en ecriture ce qui vas effacer son contenu
          ainsi on purra ecrire le nom des equipes qui vont s affronter pour le match a difuser*/
          for(i=0;i<8;i++) /*il y a 8 matchs chaque jour */
          {
              P=ALLOUER(); /*reservation d espace memoire pour un maillon  de type calendrier  **/
              fgets(P->Eq1,25,fichier);/* copier le nom de  l'equipe recavante du fichier Calendrier.txt dans le champs Eq1 de Calendrier*/
              fprintf(fich,"%s",P->Eq1);/*Ecrire le nom de l equipe recevante dans le fichier planing.txt*/
              fgets(P->Eq2,25,fichier);/* copier le nom de  l'equipe visiteuse du fichier Calendrier.txt dans le champs Eq2 de Calendrier*/
              fprintf(fich,"%s",P->Eq2);/*Ecrire le nom de l equipe visiteuse dans le fichier planing.txt*/
              P->Res=00;/*On inisialise le champs RES a 0*/
              AFF_ADR_CAL(P,NULL);/*creation standard de liste*/
              if(tete==NULL)
              {
                 tete=P;
                 Q=P;
              }
              else
              {
                 AFF_ADR_CAL(Q,P);
                 Q=P;
              }
          }
           fclose(fichier);/*On procede a la fermeture des des fichiers utilisés*/
           fclose(fich);
 }
 if(choix>2 || choix<1)/*si l utilisateur entre un choix invalid*/
 {
        Color(12,1);
        printf("\n\n");
        printf("                                      CHOIX INVALID! VEILLEZ REESSAYER SVP \n\n");
        Sleep(1000);
 }
 }while(choix!=1 && choix!=2);
        return tete;/*On retourn l adresse de la tete du Calendrier pour s en servir plus tard pour la saisi des resultats des matchs*/

}
 /*******************************************************************************************************************************************************************/
    /*procedure qui va permettre d afficher le planing c est a dire le calendrier des matchs*/
void Affichage_planing(Calendrier *tete)
{
        Calendrier *P;/*Pointeur vers maillon de type Calendrier*/
       P=tete; int cpt=0;
            printf("\n");
            printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
            Color(13,1);
            printf("                                                 PROGRAMME DE LA JOURNEE\n");
            Color(11,1);
            printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
    while(P!=NULL)
    {
            cpt++;
            Sleep(1000);
            Color(11,1);
            printf("le match num %d  :  \n",cpt);
            Color(15,1);
            printf("-----------------\n%s\n",P->Eq1);
            Color(14,1);/*On affiche le nom des deux equipe qui vont s affronter*/
            printf("        -VS-\n ");
            Color(15,1);
            printf("           %s",P->Eq2);
            printf("\n");
            printf("----------------------------------------------------------------------------------------------------------------------------\n\n");

        P=SUIVANT_CAL(P);/*On avance dans la lecture des adresses des maillons*/
    }

}
 /*******************************************************************************************************************************************************************/
                                                                    /*MATHC A DIFUSER*/
 /*******************************************************************************************************************************************************************/
/*--------------------------------------------------------------PARTIE DECLARATION DES FONCTION UTILISES -----------------------------------------------------------*/
 /*******************************************************************************************************************************************************************/
/*la fonction qui permet de chercher le nombre de points d une equipe a partie de llceq*/
int cherche_points(struct llceq *tete,char EQ[50])
{
    struct llceq *P;/*P:pointeur vers maillon de type llceq*/
    struct RANG *S;/*S:pointeur vers maillon de type RANG*/
    P=tete;int npt=0;
    while(P!=NULL)/*On commence la parcourt de llceq */
    {
        if(P->lettre==EQ[1])/*On verifie si la dexieme lettre de EQ est semblable a la lettre contenu dans le maillon llceq
            car la premiere lettre est un espace. On a procedé ainsi pour des soucis d execution du programme*/
        {
            S=DROIT(P);/*S recevera le contenu du champs droit de P c est a dire l adress du premier maillon RANG*/
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)/*Si on trouve que EQ de l entree et S->Eq sont identique on stock le nombre de points
                dans npt qui est un entier*/
                {
                    npt=(S->NpT);
                }
                S=SUIVANT(S);/*on avance dans les maillons RANG*/
            }
        }
        P=BAH(P);/*on avance dans les maillons RANG*/
    }
    return(npt);/*On retourne le nombre de points*/
}
/*******************************************************************************************************************************************************************/
/*la fonction qui permet de chercher le rang d une equipe dans le championat a partir de llceq */
int cherche_rang(struct llceq *tete,char EQ[50])/*meme traitement que la fonction precedent sauf qu au lieu de retourner
                                                le nombre de points on retourn le rang*/
{
    struct llceq *P;struct RANG *S;
    P=tete;int rang;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    rang=(S->Rang);
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
    return(rang);
}
 /*******************************************************************************************************************************************************************/
void match_a_difuser(struct llceq *tete)
    {
       FILE *fichier=fopen("planing.txt","r+");/*On ouvre le fichier planing.txt rempli a partir du calendrier des matchs
       afin d acceder aux noms des equipes qui vont s affronter*/
       char mot1[256]; char mot2[256];/*mot 1 et mot2 vont etre des intermediaires pour extraire les noms des equipes du
       fichier planing.txt tel que mot 1: Eq1 et mot 2 :Eq2*/
       char Eq1[256]; char Eq2[256];
       int i,max=0;/*Max correspendra a la somme des nombre de points des deux equipes*/
        for(i=0;i<8;i++)/*Un boucle pour de 8 iterations tel que on effectue a chaque fois deux lectures*/
       {
           fgets(mot1,30,fichier);/*extraction du nom de l equipes recevante*/
           fgets(mot2,30,fichier);/*extraction du nom de l equipes visiteuse*/
           if(cherche_points(tete,mot1)+cherche_points(tete,mot2)>max)/*Si le nombre de points des deux premieres equipes(un match)
            est superieure au max alors */
           {
               max=cherche_points(tete,mot1)+cherche_points(tete,mot2);/*On met a jour le max*/
               strcpy(Eq1,mot1);/*on copie dans Eq1 et Eq2 le noms des deux equipes*/
               strcpy(Eq2,mot2);

           }
           if(cherche_points(tete,mot1)+cherche_points(tete,mot2)==max)/*si trouve que le nombre de points des deux equipes du match precedent
            et le nombre de points des deux equipes du match actuel sont egaux alors*/
           {
               if(cherche_rang(tete,Eq1)>cherche_rang(tete,mot1))/*On compare le rang des  equipes recevantes tel que
               mot1 : equipe recevante du match actuel et Eq1: equipe recevante du match precedent.
               So on trouve que le rang de l equipe recevante precedente est superieure(moin classé)que l equipe recevante
               du match actuel alors*/
               {
                strcpy(Eq1,mot1);/*On copie alors le contenu de mot 1 et mot 2 dans Eq1 et Eq2*/
                strcpy(Eq2,mot2);
               }
           }
    }
     printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
       Color(11,1);
       printf("le match a difuser:                                     %s",Eq1);/*On affiche a lors les noms des equipes qui vont s affronter*/
       Color(15,1);
     printf("-------------------                                         -VS-\n");
       Color(11,1);
       printf("                                                        %s",Eq2);
       printf("\n");
        printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
        Sleep(2000);
}
 /*******************************************************************************************************************************************************************/
                                                                        /*SAISI RESULTATS*/
 /*******************************************************************************************************************************************************************/
/*----------------------------------------------------------PARTIE DECLARATION DES FONCTION UTILISES ---------------------------------------------------------------*/
 /*******************************************************************************************************************************************************************/
 struct Calendrier *saisit_resultats(Calendrier *tete)/*fonction qui va permetre la saisis des resultats de la journee*/
{
    struct Calendrier *P;
    int i,cpt=0;
     P=tete;
   for(i=0;i<8;i++)/*Boucle pour de 8 iterations soit 8 matches et 16 equipes*/
   {
       cpt++;
            printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
            Color(11,1);
            printf("le match num %d  :  \n",cpt);
            Color(15,1);
            printf("----------------\n%s\n ",P->Eq1);/*on affiche le nom de l equipe recevante*/
            Color(9,1);
            printf("        -VS-\n ");
            Color(15,1);
            printf("           %s\n",P->Eq2);/*on affiche le nom de l equipe recevante*/
            printf("\n");
            printf("----------\n");
            Color(14,1);
            printf("Le score : ");
            Color(15,1);
            scanf("%d",&P->Res);/*On lit le RES qui est de la forme d un entier a deux chiffres par exemple : jsk vs usma
            le score est egale a 3-1 alors on ecrira 31*/
            Color(15,1);
            printf("----------\n");
       P=SUIVANT_CAL(P);
   }
   return tete;
   }
 /*******************************************************************************************************************************************************************/
void affichage_saisit_resultats(Calendrier *tete)/*procedure pour afficher les resultats de la journee saisis*/
{    struct Calendrier *P;
    int i,cpt=0;
     P=tete;
     printf("\n");
            printf("----------------------------------------------------------------------------------------------------------------------------\n");
            Color(13,1);
            printf("|                                                  RESULTATS DE LA JOURNEE                                                 |");
            Color(15,1);
            printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
   for(i=0;i<8;i++)
   {
       Sleep(1000);
       cpt++;
            Color(11,1);
            printf("le match num %d  :  \n",cpt);
            Color(15,1);
            printf("----------------\n%s\n ",P->Eq1);
            Color(14,1);/*On affiche le nom des deux equipe qui vont s affronter ainsi que le score*/
            printf("         %d - %d\n\n ",(P->Res)/10,(P->Res)%10);
            Color(15,1);
            printf("           %s\n",P->Eq2);
            printf("----------------------------------------------------------------------------------------------------------------------------\n\n");
       P=SUIVANT_CAL(P);
   }
   P=tete;
}
 /*******************************************************************************************************************************************************************/
                                                                        /*MISE A JOUR FICHIER RANG*/
 /*******************************************************************************************************************************************************************/
/*--------------------------------------------------------------------PARTIE DECLARATION DES FONCTION UTILISES -----------------------------------------------------*/
 /*******************************************************************************************************************************************************************/
void change_points(struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre de changer le nombre de points d une equipe en referencant son son en entree ansi que le nombre a ajouter*/
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])/*le parcourt de llceq se fera comme dans la fonction cherche points precedement definit*/
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->NpT=(S->NpT)+np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
void change_matchs_gagnes(struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre de changer le nombre de match gagnees d une equipe en referencant son son en entree ansi que le nombre a ajouter*/
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->NbG=(S->NbG)+np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
void change_matchs_perdus(struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre de changer le nombre de matchs perdus d une equipe en referencant son nom en entree ansi que le nombre a ajouter*/
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->NbP=(S->NbP)+np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
void change_matchs_nuls(struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre de changer le nombre de match nuls d une equipe en referencant son nom en entree ansi que le nombre a ajouter*/
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->NbN=(S->NbN)+np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
void change_matchs_joues (struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre de changer le nombre de match joues d une equipe en referencant son nom en entree ansi que le nombre a ajouter*/
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->NbJ=(S->NbJ)+np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
void change_buts_encaisses(struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre de changer le nombre de but encaisses d une equipe en referencant son nom en entree ansi que le nombre a ajouter*/
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->bc=(S->bc)+np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
void change_buts_marques(struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre de changer le nombre de buts marques d une equipe en referencant son nom en entree ansi que le nombre a ajouter*/
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->bp=(S->bp)+np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
void change_Diff(struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre de changer la difference entre le nombre de buts marques et encaisses d une equipe en referencant son nom en entree ansi que le nombre a ajouter*/
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->Diff=(S->Diff)+np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
void Affect_rang(struct llceq *tete,char EQ[50],int np)/*procedure qui va permetre d affecter le nouveau rang d une equipe */
{
    struct llceq *P;
    struct RANG *S;
    P=tete;
    while(P!=NULL)
    {
        if(P->lettre==EQ[1])
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                if(strcmp(EQ,S->Eq)==0)
                {
                    S->Rang=np;
                }
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
}
 /*******************************************************************************************************************************************************************/
struct llceq *mise_a_jour_llceq(struct llceq *tete1,struct Calendrier *tete2)/*fonction de mise a jour de llceq*/
{
    Calendrier *P;
    P=tete2;
    while(P!=NULL)
    {
        if((P->Res)/10>(P->Res)%10)/*Si Eq1 a remporte la victoire*/
         {  change_matchs_gagnes(tete1,P->Eq1,1);
            change_matchs_perdus(tete1,P->Eq2,1);
            change_buts_encaisses(tete1,P->Eq1,(P->Res)%10);
            change_buts_marques(tete1,P->Eq1,(P->Res)/10);
            change_buts_encaisses(tete1,P->Eq2,(P->Res)/10);
            change_buts_marques(tete1,P->Eq2,(P->Res)%10);
            change_Diff(tete1,P->Eq1,((P->Res)/10)-((P->Res)%10));
            change_Diff(tete1,P->Eq2,((P->Res)%10)-((P->Res)/10));
            change_points(tete1,P->Eq1,3);
         }
          if(((P->Res)/10)<(P->Res)%10)/*Si Eq2 a remporte la victoire*/
        {   change_matchs_gagnes(tete1,P->Eq2,1);
            change_matchs_perdus(tete1,P->Eq1,1);
            change_buts_encaisses(tete1,P->Eq1,(P->Res)%10);
            change_buts_marques(tete1,P->Eq1,(P->Res)/10);
            change_buts_encaisses(tete1,P->Eq2,(P->Res)/10);
            change_buts_marques(tete1,P->Eq2,(P->Res)%10);
            change_Diff(tete1,P->Eq1,((P->Res)/10)-((P->Res)%10));
            change_Diff(tete1,P->Eq2,((P->Res)%10)-((P->Res)/10));
            change_points(tete1,P->Eq2,3);

        }
            if(((P->Res)/10)==(P->Res)%10)/*Si Eq1 et Eq2 ont fait match nuls*/
        {
            change_points(tete1,P->Eq1,1);
            change_points(tete1,P->Eq2,1);
            change_matchs_nuls(tete1,P->Eq1,1);
            change_matchs_nuls(tete1,P->Eq2,1);
            change_buts_encaisses(tete1,P->Eq1,(P->Res)%10);
            change_buts_marques(tete1,P->Eq1,(P->Res)/10);
            change_buts_encaisses(tete1,P->Eq2,(P->Res)/10);
            change_buts_marques(tete1,P->Eq2,(P->Res)%10);
        }
        change_matchs_joues(tete1,P->Eq1,1);
        change_matchs_joues(tete1,P->Eq2,1);
        P=SUIVANT_CAL(P);
    }
    return tete1;
}
 /*******************************************************************************************************************************************************************/
void  tableau_llceq(struct llceq *tete)/*procedure de creation du nouveau fichier new_rang.txt*/
{

    struct llceq *P;/*P est un pointeur vers maillon de type llceq et S,R des pointeurs vers maillon de type RANG*/
    struct RANG *S,*R;
    int T[16];/*On declare un tableau de 16 cases soit 16 equipes chaque case contiendra l adresse d un maillon de type RANG
    de llceq contenant les information de chaque equipe*/
    P=tete;/*P recevra la tete de llceq afin de pouvoir extraire les adresses des maillons des equipes*/
    int cpt=0,i=0,j=0,inter=1,val;
    for(i=0;i<16;i++)
    {
    while(P!=NULL)
    {
        if(DROIT(P)!=NULL)/*Manipulation de llceq comme precedemment*/
        {
            S=DROIT(P);
            while(S!=NULL)
            {
                    T[j]=S;/*a chaque fois qu on trouve un maillon de type RANG  contanant une equipe on range son adresse dans une case du tableau*/
                    j++;/*On incremente l indice du tableau pour pouvoir avancer*/
                S=SUIVANT(S);
            }
        }
        P=BAH(P);
    }
    }
/*-----------------------------------------------------------------------------------------------------------------------*/
   do/*le but de cette etape est de trie le tableau par la maniere du tri a bules car
   a chaque fois on va acceder au nombre de points d une equipe dans llceq grace a l adress des maillons*/
   {
       inter=0;/*inter recevera 1 si on effectue une permutation dans le tableau c est a dire on trouve que
   la case a l indice i+1  un nombre de points superieure a la case d indice i*/
       for(i=0;i<15;i++)/*un boucle pour de 15 iteration pour avec de i a i+1*/
       {
           S=T[i]; R=T[i+1];/*on va affecter les adresses aux pointeurs vers RANG */
           if((S->NpT)<(R->NpT))/*Si on trouve que le nombre de points de la case a indice i+1 est superieure au nombre de points de la case  d indice i*/
           {
               val=T[i+1];
               T[i+1]=T[i];/*On effectue une permutation des adresses*/
               T[i]=val;
               inter=1;/*inter recevera 1*/
           }
       }
    }while(inter!=0);/*jusqu a a ne plus retrouver de permutation*/
/*------------------------------------------------------------------------------------------------------------------------*/
    inter=1;
     do/*cette etape est faite pour reordonner les cases ou le nombre de points de la case i+1 et i sont egales*/
   {
       inter=0;
       for(i=0;i<15;i++)/*un boucle pour de 15 iteration pour avec de i a i+1*/
       {
           S=T[i]; R=T[i+1];
           if((S->NpT)==(R->NpT))/*Si on retrouve deux cases successives contenant le meme nombre de points*/
           {
                if((S->Diff)<(R->Diff))/*On compare la difference entre le nombre de but marques et encaisses l equipe ayant le plus grand nombre Diff sera classe mieux*/
                {
                val=T[i+1];
                T[i+1]=T[i];/*On effectue une permutation d adresses*/
                T[i]=val;
                inter=1;
                }
                 if((S->Diff)==(R->Diff))/*maintenant si aussui en plus du nombre de points ils ont aussi le nombre diff egale*/
                {
                      if((S->Eq[1])>(R->Eq[1]))
                       {
                       val=T[i+1];/*l ordre se fait par ordre alphabetique alors on compare le codage asci des premieres lettres des deux equipes*/
                       T[i+1]=T[i];/*On effectue des permutations d adresses*/
                       T[i]=val;
                       inter=1;
                       }
                }
        }
    }
    }while(inter!=0);
/*--------------------------------------------------------------------------*/
    FILE *fichier=fopen("new_rang.txt","w");/*On ouvre alors le nouuveau fichier rang en ecriture*/
    for(j=0;j<16;j++)
      {

        S=T[j];
               Affect_rang(tete,S->Eq,j+1);/*On affecte a chaque equipe son nouveau rang suivant son nombre de points*/
               fprintf(fichier ,"%d ",j+1);/*On commence l ecriture dans le nouveau fichier en commencant par le rang*/
               fprintf(fichier,"%s                        ",S->Eq);
               fprintf(fichier,"%d  ",S->NpT);
               fprintf(fichier,"%d  ",S->NbJ);/*Grace aux adresse il suffir juste d acceder
               au information de chaque equipe et les ecrire dans le nouveaux fichier rang*/
               fprintf(fichier,"%d  ",S->NbG);
               fprintf(fichier,"%d  ",S->NbN);
               fprintf(fichier,"%d  ",S->NbP);
               fprintf(fichier,"%d  ",S->bp);
               fprintf(fichier,"%d  ",S->bc);
               fprintf(fichier,"%d\n",S->Diff);
    }
    fclose(fichier);
}
/*--------------------------------------------------------------------------*/
 /*******************************************************************************************************************************************************************/
/*procedure qui va permettre d afficher le contenu du fichier rang.txt*/
void Affichage_new_Rang()
{
                int i,cpt=0,rang;
                char mot [255];
                FILE *fich=fopen("new_rang.txt","r");/*ouverture en lecture du fichier rang.txt*/
                Color(11,1);
                printf("---------------------------------------------------------------------------------------------------------------------------\n");
                Color(13,1);
                printf("|                                           LE CONTENU DU FICHIER RANG                                                    |\n");
                Color(11,1);
                printf("---------------------------------------------------------------------------------------------------------------------------\n");
                for(i=0;i<16;i++)
                {
                    fscanf(fich,"%d",&rang);/*on lit le rang de l equipe qui est en premeir*/
                    Color(11,1);
                    fgets(mot,255,fich);/*on lit le nom de l equipe*/
                    Color(14,1);
                    Sleep(500);
                    printf(" %s",mot);/*on affiche le nom de l equipe*/
                    Color(11,1);
                    Sleep(500);
                    fgets(mot,255,fich);/*on lit la ligne contenant les diverses informations*/
                    printf(" %s\n",mot);/*on affiche le contenu de la ligne precedente*/
                    printf("---------------------------------------------------------------------------------------------------------------------------\n");
                }
               fclose(fich);/*fermeture du fichier*/
}
 /*******************************************************************************************************************************************************************/
void loading()/*procedure pour afficher un loading*/
        {
            system("color 15");
            system("mode con LINES=20 COLS=70");
            int l,X;char c;
            printf("\n\n\n\n\n\n\n");
            Color(11,1);
            printf("             +--------------------------------------+\n");
            Color(14,1);
            printf("             |    VEILLEZ CHOISIR UNE JOURNEE SVP : |                                                 ");/*On demande al lecture de la journee choisis*/
            Color(11,1);
            scanf("%d",&X);
            printf("             |                                      |\n");
            printf("             +--------------------------------------+\n");
            Color(2,1);
            printf("\n");
            printf("              LOADING ");
            for(l=0;l<14;l++)
            {Color(15,1);Sleep(100);printf("%c ",254);}
            Color(12,1);
            printf("100 %c",37);
            Color(15,1);
        }
 /*******************************************************************************************************************************************************************/
void thanks()/*une procedure pour afficher un merci*/
      {
            system("cls");
            printf("\n\n\n\n\n\n\n\n");
            Color(14,1);
            Sleep(100);Color(15,1);
            printf("                                                                                @@                  \n");Sleep(60);
            printf("                                                                               @@@@                 \n\n");Sleep(60);
            printf("       \t\t\t  @@@@@@@@@@  @@@@@@        @@@@@@      @@@@@@@@@@    @@@@@@@@    @@@@                 \n");Sleep(60);
            printf("       \t\t\t   @@    @@@@      @@    @@@@    @@      @@    @@  @@@@    @@      @@                 \n");Sleep(60);
            Color(12,1);
            printf("       \t\t\t   @@      @@      @@    @@      @@@@    @@        @@              @@                  \n");Sleep(60);
            printf("       \t\t\t   @@      @@      @@    @@@@@@@@@@@@    @@        @@              @@                  \n");Sleep(60);Color(15,1);
            printf("       \t\t\t   @@      @@      @@    @@              @@        @@              @@                   \n");Sleep(60);
            printf("       \t\t\t   @@      @@      @@    @@@@      @@    @@        @@@@    @@      @@                   \n");Sleep(60);
            printf("       \t\t\t @@@@@@  @@@@@@  @@@@@@    @@@@@@@@    @@@@@@        @@@@@@      @@@@@I         \n\n\n\n");Sleep(60);

            Color(14,1);
            printf("                                        REALISE PAR TERRAS JUBA && NOURI BOUTHEYNA\n");
            Color(15,1);
            printf("\n\n\n\n\n                                                         Appuyez sur n'importe quelle touche pour quitter  ");
            getch();
      }
/*******************************************************************************************************************************************************************/
void acceil()/*procedure pour afficher l acceil*/
{
 system("color 15");
 system("mode con LINES=36 COLS=130");/*redimensioner la console*/
 Color(11,1);
 printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
 Sleep(200);/*ralentir l affichage*/
 printf("|REPEBLIQUE ALGERIENNE                                                                                MINISTRE DE L'ENSEIGNEMENT |\n");
 Sleep(200);
 printf("|DEMOCRATIQUE ET                                                                                      SUPERIEURE ET DE LA        |\n");
 Sleep(200);
 printf("|POPULAIRE                                     ²²²²²²²     ²²²²²²    ²²²²²²²²                         RECHERCHE SCIENTIFIQUE     |\n");
 Sleep(200);
 printf("|                                              ²²         ²             ²²                                                       |\n");
 Sleep(200);
 printf("|                                              ²²         ²             ²²                                                       |\n");
 Sleep(200);
 printf("|                                              ²²²²²²²     ²²²²²        ²²                                                       |\n");
 Sleep(200);
 printf("|                                              ²²               ²       ²²                                                       |\n");
 Sleep(200);
 printf("|                                              ²²               ²       ²²                                                       |\n");
 Sleep(200);
 printf("|                                              ²²²²²²²    ²²²²²²     ²²²²²²²²                                                    |\n");
 Sleep(200);
 printf("|                                                                                                                                |\n");
 Sleep(200);
 printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
 Sleep(200);
 Color(13,1);
 printf("|                                                                                                                                |\n");
 Sleep(200);
 printf("|                                                                                                                                |\n");
 Sleep(200);
 printf("|                 ²²²²²²²  ²        ²     ²²²²²²²  ²²²²²²²  ²²²²²² ²²²²²²² ²²²²²²²   ²   ²        ²  ²²²²²²²                     |\n");
 Sleep(200);
 printf("|                    ²      ²      ²      ²        ²     ²  ²    ² ²     ²     ²     ²    ²      ²   ²                           |\n");
 Sleep(200);
 printf("|                    ²       ²    ²       ²²²²²²²  ²²²²²²²  ²    ² ² ² ² ²     ²     ²     ²    ²    ²²²²²²²                     |\n");
 Sleep(200);
 printf("|                    ²        ²  ²              ²  ²        ²    ² ²     ²     ²     ²      ²  ²     ²                           |\n");
 Sleep(200);
 printf("|                    ²          ²         ²²²²²²²  ²        ²²²²²² ²     ²     ²     ²        ²      ²²²²²²²                     |\n");
 Sleep(200);
 printf("|                                                                                                                                |\n");
 Sleep(200);
 printf("|                                                                                                                                |\n");
 Color(11,1);
 Sleep(200);
printf("+--------------------------------------------------------------------------------------------------------------------------------+\n\n\n\n");
 Sleep(200);
 Color(14,1);
    printf("                          \t+--------------------------------------------------------------+\n");
            Sleep(200);
    printf("                          \t|                      GESTION TV SPORTIVE                     |\n");
            Sleep(200);
    printf("                          \t|            Realise par:TERRAS JUBA && NOURI BOUTHEYNA        |\n");
            Sleep(200);
    printf("                          \t|                Encadre Par : MADAME CHADER ASMA              |\n");
            Sleep(200);
    printf("                          \t+--------------------------------------------------------------+\n");
            Sleep(200);
    Color(11,1);
    printf("\n\n                                                         Appuyez sur n'import quelle touche pour acceder a l'interface ");
    getch();

}
/*******************************************************************************************************************************************************************/
void affich_menu()/*procedure pour afficher le menu des choix*/
{
 printf("\n");
 Sleep(200);
 Color(11,1);
 Sleep(200);
 printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
 Color(10,1);
 Sleep(200);
 printf("|                                             GESTION DE LA TV SPORTIVE                                                          |\n");
 Color(11,1);
 Sleep(200);
 printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
 Color(12,1);
 Sleep(200);
 printf("|   NOM:                   BEIGN SPORT ALGERIE             |  PAGE FACEBOOK:                    BEIGN SPORT ALGERIE              |\n");
 Sleep(200);
 Color(11,1);
 Sleep(200);
 printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
 Color(12,1);
 Sleep(200);
 printf("|   ADRESSE MAIL:          BEIGN_SPORT_ALGERIE@GMAIL.COM   |  NUMERO DE TELEPHONE:              0214578463                       |\n");
 Sleep(200);
 Color(11,1);
 Sleep(200);
 printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
    Sleep(200);
    Color(14,1);
    printf("                         \t+--------------------------------------------------------------+\n");
    Sleep(200);
    printf("                         \t|                       MENU DES CHOIX                         |\n");
    Sleep(200);
    printf("                         \t+--------------------------------------------------------------+\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     1) Afficher le classement actuel du championat.          |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     2) Remplir le fichier rang.txt                           |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     3) Afficher le contenu du fichier rang.txt.              |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     4) Afficher llceq.                                       |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
     Sleep(200);
    printf("                         \t|     5) Remplir le calendrier des matchs                      |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     6) Afficher le planing des matchs                        |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     7) Visualiser le match a difuser                         |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     8) Saisir le scores des matchs de la journee             |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     9) Mettre a jour llceq et creer le nouveau fichier rang  |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     10) Afficher le contenu du nouveau fichier rang          |\n");
    Sleep(200);
    printf("                         \t|                                                              |\n");
    Sleep(200);
    printf("                         \t|     11) Quitter                                              |\n");
    Sleep(200);
    printf("                         \t+--------------------------------------------------------------+\n");
    Color(11,1);
}

#ifndef TV_LLC_BIBLIO_H_INCLUDED
#define TV_LLC_BIBLIO_H_INCLUDED
/**************************************************************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/**************************************************************************************************************************/
/*---------------------------------------PARTIE DECLARATION DES STRUCTURE-------------------------------------------------*/
/**************************************************************************************************************************/
typedef struct RANG/*la structure RANG avec ses diferents champs*/
{
    char Eq[25];
    struct RANG *suivant;/*un pointeur vers le maillon suivant de meme type*/
    int Rang,NpT,NbJ,NbG,NbN,NbP,bp,bc,Diff;/*les differentes informations relatives a chaque equipe*/

}RANG;
/**************************************************************************************************************************/
typedef struct llceq/*la structure llceq qui est compose de troie champs*/
{
    char lettre;/*un champs de type caractere pour la lettre de l alphabet correspendante*/
    struct llceq *bah;/*  bah:est un pointeur vers le maillon suivant contenant la lettre de l alphabet*/
    struct RANG *droit;/* droit:eqt un pointeur vers le maillon des equipes de meme type que RANG*/
}llceq;
/**************************************************************************************************************************/
/*1)-La structure calendrier qui est compose de 3 champs*/

typedef struct Calendrier Calendrier ;
typedef struct Res Res;
struct Calendrier
{char Eq1[256],Eq2[256];
   int Res;/*On definit les champs de la structure Calendrier qui est compose des
             noms des deux equipes qui vont s afforonter Eq1 et Eq2 ainsi que du
             resultat du match Res*/
   ;Calendrier *suivant;/*suivant est un pointeur vers le maillon suivant de la liste calendrier*/
};
/**************************************************************************************************************************/
/*-------------------------------PARTIE DECLARATION DES FONCTIONS UTILISES------------------------------------------------*/
/**************************************************************************************************************************/
/*creation de llceq*/
void Color(int couleurDuTexte,int couleurDeFond);
struct llceq *ALOUER1();
struct RANG *ALOUER2();
void AFF_ADR_B(struct llceq *P,struct llceq*Q);
void AFF_ADR_D(struct llceq *P,struct RANG *Q);
void AFF_ADR(struct RANG *P,struct RANG *Q);
struct RANG *SUIVANT(struct RANG *P);
struct llceq *BAH(struct llceq *P);
struct llceq *DROIT(struct llceq *P);
struct llceq *creation_llceq();
void affichage_llceq(struct llceq *tete);

/**************************************************************************************************************************/
/*Remplissage du calendrier*/
void Color(int couleurDuTexte,int couleurDeFond);
void Affichage_planing(Calendrier *tete);
struct Calendrier *Remplissage_Calendrier();
/**************************************************************************************************************************/
/*match a difuser*/
void match_a_difuser(struct llceq *tete);
int cherche_points(struct llceq *tete,char EQ[50]);
int cherche_rang(struct llceq *tete,char EQ[50]);
/**************************************************************************************************************************/
/*Saisie des resultats*/
void affichage_saisit_resultats(Calendrier *tete);
struct Calendrier *saisit_resultats(Calendrier *tete);
/**************************************************************************************************************************/
/*Creation du fichier rang.txt*/
void Affichage_classement();
void Remplissage_Rang();
void Affichage_Rang();
/**************************************************************************************************************************/
/*mise a jour de llceq et creation du nouveau fichier new_rang.txt*/
void change_points(struct llceq *tete,char EQ[50],int np);
void change_matchs_gagnes(struct llceq *tete,char EQ[50],int np);
void change_matchs_perdus(struct llceq *tete,char EQ[50],int np);
void change_matchs_nuls(struct llceq *tete,char EQ[50],int np);
void change_matchs_joues (struct llceq *tete,char EQ[50],int np);
void change_buts_encaisses(struct llceq *tete,char EQ[50],int np);
void change_buts_marques(struct llceq *tete,char EQ[50],int np);
struct llceq *mise_a_jour_llceq(struct llceq *tete1,struct Calendrier *tete2);
void change_Diff(struct llceq *tete,char EQ[50],int np);
void Affect_rang(struct llceq *tete,char EQ[50],int np);
void  tableau_llceq(struct llceq *tete);
void Affichage_new_Rang();
/**************************************************************************************************************************/
/*Affichage*/
void loading();
void thanks();
void clrscr ();
void acceil();
void affich_menu();
/**************************************************************************************************************************/
#endif // TV_LLC_BIBLIO_H_INCLUDED

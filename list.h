#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- liste.h ----------- */
typedef struct Point
{
    int x;
    int y;
    int z;
    struct Point *suivant;
}Point;

typedef struct ListeRepere
{
    Point *debut;
    Point *fin;
    int taille;
}Liste;

/* initialisation de la liste */
extern void initialisation (Liste *liste);
/* INSERTION */
/* insertion dans une liste vide */
extern int insListeVide (Liste *liste, Point *point);
/* insertion au début de la liste */
extern int insDebutListe (Liste *liste, Point *point);
/* insertion Ã a fin de la liste */
extern int insFinListe (Liste *liste, Point *courant, Point *point);
/* insertition ailleurs */
extern int insListe (Liste *liste, Point *point, int pos);
/* SUPPRESSION */
extern int suppDebut (Liste *liste);
extern int suppDansListe (Liste *liste, int pos);
extern int menu (Liste *liste, int *k);
extern void affiche (Liste *liste);
extern void detruire (Liste *liste);

/* -------- FIN liste.h --------- */
#endif // LIST_H_INCLUDED
/***************************\
 list.c *
\***************************/

//#include "list.h"

void initialisation (Liste *liste){


    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}

/* insertion dans une liste vide */
int insListeVide (Liste *liste, Point *point){

    Point *nouveau_point;

    if ((nouveau_point = (Point *) malloc (sizeof (Point))) == NULL)
        return -1;

    nouveau_point->x = point->x;
    nouveau_point->y = point->y;
    nouveau_point->z = point->z;

    nouveau_point->suivant = NULL;

    liste->debut = nouveau_point;

    liste->fin = nouveau_point;

    liste->taille++;

    return 0;
}

/* insertion au début de la liste */
int insDebutListe (Liste *liste, Point *point){

    Point *nouveau_point;

    if ((nouveau_point = (Point *) malloc (sizeof (Point))) == NULL)
        return -1;

    nouveau_point->x = point->x;
    nouveau_point->y = point->y;
    nouveau_point->z = point->z;

    nouveau_point->suivant = liste->debut;

    liste->debut = nouveau_point;

    liste->taille++;

    return 0;
}

/*insertion à la fin de la liste */
int insFinListe (Liste *liste, Point *courant, Point *point){

    Point *nouveau_point;

    if ((nouveau_point = (Point *) malloc (sizeof (Point))) == NULL)
        return -1;

    nouveau_point->x = point->x;
    nouveau_point->y = point->y;
    nouveau_point->z = point->z;

    courant->suivant = nouveau_point;

    nouveau_point->suivant = NULL;

    liste->fin = nouveau_point;

    liste->taille++;

    return 0;
}

/* insertion à la position demandée */
int insListe (Liste *liste, Point *point, int pos){

    if (liste->taille < 2)
        return -1;
    if (pos < 1 || pos >= liste->taille)
        return -1;

    Point *courant;
    Point *nouveau_point;

    int i;

    if ((nouveau_point = (Point *) malloc (sizeof (Point))) == NULL)
        return -1;

    courant = liste->debut;

    for (i = 1; i < pos; ++i)
        courant = courant->suivant;

    if (courant->suivant == NULL)
        return -1;

    nouveau_point->x = point->x;
    nouveau_point->y = point->y;
    nouveau_point->z = point->z;

    nouveau_point->suivant = courant->suivant;

    courant->suivant = nouveau_point;

    liste->taille++;

    return 0;
}

/* suppression au début de la liste */
int suppDebut (Liste *liste){

    if (liste->taille == 0)
        return -1;

    Point *supp_Point;

    supp_Point = liste->debut;

    liste->debut = liste->debut->suivant;

    if (liste->taille == 1)
        liste->fin = NULL;

    free (supp_Point);

    liste->taille--;

    return 0;
}

/* supprimer un Point après la position demandée */
int suppDansListe (Liste *liste, int pos){

    if (liste->taille <= 1 || pos < 1 || pos >= liste->taille)
        return -1;

    int i;

    Point *courant;
    Point *supp_Point;
    courant = liste->debut;

    for (i = 1; i < pos; ++i)
        courant = courant->suivant;

    supp_Point = courant->suivant;

    courant->suivant = courant->suivant->suivant;
    if(courant->suivant == NULL)
        liste->fin = courant;

    free (supp_Point);

    liste->taille--;

    return 0;
}

/* affichage de la liste */
void affiche (Liste *liste){

    Point *courant;
    courant = liste->debut;

    while (courant != NULL){
        printf ("%p - x: %d, y: %d, z: %d\n", courant, courant->x, courant->y, courant->z);
        courant = courant->suivant;
    }
}

/* detruire la liste */
void detruire (Liste *liste){

   while (liste->taille > 0)
        suppDebut (liste);
}

int menu (Liste *liste, int *k){

    int choix;

    printf("********** MENU **********\n");

    if (liste->taille == 0){
        printf ("1. Ajout du 1er Point\n");
        printf ("2. Quitter\n");
    }else if(liste->taille == 1 || *k == 1){
        printf ("1. Ajout au debut de la liste\n");
        printf ("2. Ajout a la fin de la liste\n");
        printf ("4. Suppression au debut de la liste\n");
        printf ("6. Detruire la liste\n");
        printf ("7. Quitter\n");
    }else {
        printf ("1. Ajout au debut de la liste\n");
        printf ("2. Ajout a la fin de la liste\n");
        printf ("3. Ajout apres la position specifie\n");
        printf ("4. Suppression au debut de la liste\n");
        printf ("5. Suppression apres la position specifie\n");
        printf ("6. Detruire la liste\n");
        printf ("7. Quitter\n");
    }

    printf ("\n\nFaites votre choix : ");

    scanf ("%d", &choix);

    getchar();

    if(liste->taille == 0 && choix == 2)
        choix = 7;

    return choix;
}
/* -------- FIN liste_function.h --------- */

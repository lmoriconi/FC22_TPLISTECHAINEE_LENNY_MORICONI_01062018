/**********************\
 liste.c *
\**********************/
#include "list.h"

int main (void)
{
    char choix;
    Point *point;
    Liste *liste;

    //point *courant;
    if ((liste = (Liste *) malloc (sizeof (Liste))) == NULL)
        return -1;
    if ((point = (Point *) malloc (50)) == NULL)
        return -1;

    //courant = NULL;
    choix = 'o';

    initialisation (liste);

    int pos, k;

    while (choix != 7){
        choix = menu (liste, &k);

        switch (choix){
            case 1:
                printf ("Entrez un point : \n");
                printf("x : ");
                scanf("%d", &point->x);
                fflush(stdin);
                printf("y : ");
                scanf("%d", &point->y);
                fflush(stdin);
                printf("z : ");
                scanf("%d", &point->z);
                fflush(stdin);
                if (liste->taille == 0)
                    insListeVide(liste, point);
                else
                    insDebutListe (liste, point);
                printf ("%d points: deb=x: %d, y: %d, z: %d; fin=x: %d, y: %d, z: %d\n", liste->taille, liste->debut->x, liste->debut->y, liste->debut->z, liste->fin->x, liste->fin->y, liste->fin->z);
                affiche (liste);
                break;
            case 2:
                printf ("Entrez un point : \n");
                printf("x : ");
                scanf("%d", &point->x);
                fflush(stdin);
                printf("y : ");
                scanf("%d", &point->y);
                fflush(stdin);
                printf("z : ");
                scanf("%d", &point->z);
                fflush(stdin);
                insFinListe (liste, liste->fin, point);
                printf ("%d points: deb=x: %d, y: %d, z: %d; fin=x: %d, y: %d, z: %d\n", liste->taille, liste->debut->x, liste->debut->y, liste->debut->z, liste->fin->x, liste->fin->y, liste->fin->z);
                affiche (liste);
                break;
            case 3:
                printf ("Entrez un point : \n");
                printf("x : ");
                scanf("%d", &point->x);
                fflush(stdin);
                printf("y : ");
                scanf("%d", &point->y);
                fflush(stdin);
                printf("z : ");
                scanf("%d", &point->z);
                fflush(stdin);
                do{
                    printf ("Entrez la position : ");
                    scanf ("%d", &pos);
                }while (pos < 1 || pos > liste->taille);
                getchar ();
                if (liste->taille == 1 || pos == liste->taille){
                    k = 1;
                    printf("-----------------------------------------------\n");
                    printf("Insertion echouée.Utilisez le menu {1|2} \n");
                    printf("-----------------------------------------------\n");
                    break;
                }
                insListe (liste, point, pos);
                printf ("%d points: deb=x: %d, y: %d, z: %d; fin=x: %d, y: %d, z: %d\n", liste->taille, liste->debut->x, liste->debut->y, liste->debut->z, liste->fin->x, liste->fin->y, liste->fin->z);
                affiche (liste);
                break;
            case 4:
                suppDebut (liste);
                if (liste->taille != 0)
                    printf ("%d points: deb=x: %d, y: %d, z: %d; fin=x: %d, y: %d, z: %d\n", liste->taille, liste->debut->x, liste->debut->y, liste->debut->z, liste->fin->x, liste->fin->y, liste->fin->z);
                else
                    printf ("liste vide\n");
                affiche (liste);
                break;
            case 5:
                do{
                    printf ("Entrez la position : ");
                    scanf ("%d", &pos);
                }while (pos < 1 || pos > liste->taille);
                getchar ();
                suppDansListe (liste, pos);
                if (liste->taille != 0)
                    printf ("%d points: deb=x: %d, y: %d, z: %d; fin=x: %d, y: %d, z: %d\n", liste->taille, liste->debut->x, liste->debut->y, liste->debut->z, liste->fin->x, liste->fin->y, liste->fin->z);
                else
                    printf ("liste vide\n");
                affiche (liste);
                break;
            case 6:
                detruire (liste);
                printf ("la liste a ete detruite : %d points\n", liste->taille);
                break;
        }
    }

    return 0;
}

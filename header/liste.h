#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste_{
    Element *premier;
}Liste;

Liste *creeListe();
void inserer(Liste *liste, int nvNombre);
void supprimer(Liste*liste,int degage);
void afficherListe(Liste*liste);
void freeListe(Liste*liste);



#endif // LISTE_H_INCLUDED


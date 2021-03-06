#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

typedef struct player_{
  int pos[2];//pos[0] hauteur, pos[1] largeur
  Liste *sac;
  int identpok;
}player;


typedef struct map_{
  int lig;
  int col;
  char** elt;
}map;

map* map_create(int lig, int col);
void map_free(map * m);
void map_print(map * m);
map* map_from_file(FILE * fp);
char getMap(map *m, int a, int b);
player* player_create();
void player_free(player *j);
void playerTomap(player *p,map *m);
void changePosition(player *j,map* m,char c);
int estVide(map *m,int lig, int col); 
#endif // CARTE_H_INCLUDED

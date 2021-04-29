#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "carte.h"
#include <time.h>
#define MaxP 100


typedef struct Pokemon_{
  int identifiant;
  char espece[MaxP];
  char type[MaxP];
  int vie;
}Pokemon;

typedef struct vecPoke_{
  int nbpoke; // la longeur du vec
  Pokemon **elt;
}vecPoke;

Pokemon * Pokemon_create();

Pokemon * Pokemon_init(int ident, char esp[MaxP],char type[MaxP],int vie);

void Pokemon_free (Pokemon *p);

void Pokemon_print(Pokemon *p);

void Pokemon_print_espece(Pokemon *p);

Pokemon* Pokemon_from_file(FILE *fp);

void Pokemon_to_file(FILE *fp,Pokemon*p);

void Pokemon_echange(Pokemon *a,Pokemon *b);

void Pokemon_to_map(map *m, Pokemon *p,FILE *fp);

int estVivant(Pokemon * p,Pokemon * a);


vecPoke * vecPoke_init(int a);

void vecPoke_free(vecPoke *vec);

void vecPoke_copy(vecPoke *a, vecPoke *b);

void vecPoke_ajout(Pokemon  *p, vecPoke *vec);

void vecPoke_print(vecPoke *vec);

Pokemon * Pokemon_from_vecPoke(int a,vecPoke * vec);

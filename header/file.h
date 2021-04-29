#ifndef H_FILE
#define H_FILE
#include "combat.h"

typedef struct Elt Elt;
struct Elt
{
    Pokemon *poke;
    Elt *suivant;
};

typedef struct File File;
struct File
{
    Elt *premier;
};

File *initialiser();
void enfiler(File *file, Pokemon *poke);
int defiler(File *file);
void afficherFile(File *file);
File *readpokemon(FILE *fp);
vecPoke * vecPoke_from_file(File *file);

#endif


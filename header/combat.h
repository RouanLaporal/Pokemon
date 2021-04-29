#ifndef COMBAT_H
#define COMBAT_H

#include "pokemon.h"
#include <stdio.h>

int estPokemon(map *m, player *j,char c);
void ask(player *j, Pokemon * sauvage,vecPoke * vec);
void attaque(player *j,Pokemon *sauvage,vecPoke *vec);
void changerdepokemon(player *j, Pokemon *sauvage,vecPoke * vec);
void fuir();


#endif

#include "combat.h"
#include <time.h>



int estPokemon(map *m, player *j, char c)
// check if the case where the player is going to be is a *
{
  
  if (c=='l'&& getMap(m, j->pos[0]+1,j->pos[1])=='*')
    return 0;
  
  if (c=='o'&& getMap(m, j->pos[0]-1,j->pos[1])=='*')
    return 0;
   
  if (c=='m'&& getMap(m, j->pos[0],j->pos[1]+1)=='*')
    return 0;
  
  if (c=='k'&& getMap(m, j->pos[0],j->pos[1]-1)=='*')
    return 0;
  else 
	return 1;
  
}
void  ask(player *j,Pokemon *sauvage,vecPoke *vec){
  char c[2];
  int i=0;
  system("clear");
  printf("Vous etes en combat avec un pokemon sauvage : ");
  Pokemon_print_espece(sauvage); 
  printf("\n");
  
  printf("Que voulez-vous faire? \n");
  printf("Pour attaquer = a \n");
  printf("Pour changer de pokemon = c \n");
  printf("Pour fuir = f \n");
  for (i=0;i<2;i++)
  scanf("%c",&c[0]);
   
   if (c[0]=='a')
     attaque(j,sauvage,vec);
   if (c[0]=='c') 
     changerdepokemon(j,sauvage,vec);
   if (c[0]=='f')
	     fuir();
   else
     ask(j,sauvage,vec);
 
}




void attaque(player *j,Pokemon *sauvage, vecPoke * vec )
{
  int reussite;
  srand(time(NULL));
  Pokemon * dresseur = sauvage;//Pokemon_from_vecPoke(j->identpok, vec);
  Pokemon_print(dresseur);
  while ( (dresseur->vie>=1) && (sauvage->vie>=1))/*on vérifie que les 2 pokemon sont toujours vivant*/
    {
      reussite=rand()%(5-1)+1;/*on choisit un nombre au hasard entre 1 et 4*/
      if (reussite!=4)/*si ce nombre est 1, 2 ou 3 alors l'attaque du dresseur est réussite*/
	{
	  printf("%s attaque \n",dresseur->espece);
	  sauvage->vie = sauvage->vie-1;
	  Pokemon_print_espece(sauvage);
	  printf(" : a maintenant %d point de vie \n",sauvage->vie);	
	}
      else/*sinon le pokemon n'attaque pas */ 
	   printf("%s a rate son attaque\n",dresseur->espece);
	 
	if(dresseur -> vie <=1)
		break; 
       reussite=rand()%(5-1)+1;
       if (reussite!=4)/*on refait le même procéder pour le pokemon sauvage*/
	{
	  printf("%s attaque \n",sauvage->espece);
	  dresseur->vie = dresseur->vie-1;
	  Pokemon_print_espece(dresseur);
	  printf(" : a maintenant %d point de vie \n",dresseur->vie);
	}
       else
	 
	   printf("%s a rate son attaque\n",sauvage->espece);
	 
	if(sauvage -> vie <=1)
		break;	
    }
  if(sauvage->vie<=1)
    {
      printf("Félicitation vous avez attrappez un %s sauvage\n",sauvage->espece); /*capture of a new pokemon(sauvage)*/ ;
    }
  if (dresseur->vie<=1)
    {
      printf("%s est K.o\n",dresseur->espece);
      /*dresseur it's dead*/
    }
}


void changerdepokemon(player *j,Pokemon *sauvage,vecPoke *vec)
{
  int x;
  vecPoke_print(vec);
  printf("Voici-ci vos pokemon, taper l'identifiant de celui que vous avez choisi \n");
  
 scanf ("%d", &x);
 Pokemon_echange(Pokemon_from_vecPoke(x,vec),Pokemon_from_vecPoke(j->identpok,vec)); 
 ask(j,sauvage,vec);
}


void fuir ()
{
  printf("Vous avez decidé de fuir");
  getchar();
}



	// Pour aller plus loin il s'agit d'une lsite cyclique.

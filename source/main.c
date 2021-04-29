#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(){
  
  player * p;
  map * m;
  char tmp[]={"caracter a rentrer"};
  Liste * sac= creeListe();
  Pokemon * pikachu = Pokemon_create(12,"Pikachu ","feu ", 5);
  vecPoke * vecplayer = vecPoke_init(0);
  vecPoke * ppoke = vecPoke_init(0);
  int i;
  FILE *fp = NULL;//carte.txt
  FILE *fp2 = NULL;//pokemon.txt
  FILE *fp3 = NULL;//inventory.txt for save the game
 
  if ((fp = fopen("./txt/carte.txt", "r"))== NULL){
    printf("Erreur d'ouverture de la carte\n");
    return 1;
  }

  if ((fp2 = fopen("./txt/pokemon.txt", "r"))== NULL){
    printf("Erreur d'ouverture du fichier pokemon\n");
    return 1;
  }

  if ( (fp3 = fopen("./txt/inventory.txt", "r+"))== NULL){
       printf("Erreur d'ouverture de l'inventaire \n");
       return 1;    

  }
  File* listpoke=readpokemon(fp2);
  afficherFile(listpoke);
  m = map_from_file(fp);
  p = player_create();
  playerTomap(p,m);  
  printf ("Vous avez les pokémon suivant \n");
  inserer(sac,pikachu->identifiant);// the player start with a pikachu
  vecPoke_ajout(pikachu,vecplayer);
  vecPoke_print(vecplayer);
  Pokemon_to_map(m,listpoke->premier->poke,fp2);
  map_print(m);
  
  while(tmp[0]!='q'){// solution found for allow the player to make more than move and not read the /n 
    i=0;              
     do{
       scanf("%c",&tmp[i]);
	        
       if (estPokemon(m,p,tmp[i])==0) {	     
	 
	 ask(p,listpoke->premier->poke,vecplayer);
	 Pokemon_to_map(m,listpoke->premier->poke,fp2);
       }
       
       
       changePosition(p,m,tmp[i]);
       i++;
     }while(tmp[i-1]!='\n');
     playerTomap(p,m);
     system("clear");
     map_print(m);
  }
     
       
 
   

  //Pokemon_free(pikachu);
  vecPoke_free(ppoke);
  player_free(p);
  map_free(m);
  fclose(fp2);
  fclose(fp);
  return 0;
}

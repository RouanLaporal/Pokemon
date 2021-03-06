#include "pokemon.h"
#include <time.h>
#include <string.h>



Pokemon * Pokemon_create(int ident, char esp[MaxP],char type[MaxP],int vie)
{
  Pokemon *p;
 
  p=(Pokemon*) malloc (sizeof(Pokemon));
  p->identifiant = ident;
  strcpy(p->espece,esp);
  strcpy(p->type,type);
  p->vie =vie;

  return p;
}

void Pokemon_free (Pokemon *p){
  free (p);
}


void Pokemon_print(Pokemon * p){
  int i= 0;
  printf("%d ", p->identifiant);
  
  while(p->espece[i]!=' '){
    printf("%c",p->espece[i]);
    i++;}
  printf(" ");
  i=0;
  
  while(p->type[i]!=' '){
    printf("%c",p->type[i]);
    i++;
  }
  printf(" %d ",p->vie);
  printf("\n");
}

void Pokemon_print_espece(Pokemon *p)
{
  int i=0;
  while(p->espece[i]!=' '){
    printf("%c",p->espece[i]);
    i++;}
}
  

Pokemon* Pokemon_from_file(FILE *fp){

  Pokemon *p;
  int ident,v,i=-1;
  char esp[MaxP], typ[MaxP];
  
  fscanf(fp,"%d  ",&ident);
 
  do{
    i=i+1;
    fscanf(fp,"%c",&esp[i]);
    
  }while(esp[i]!=' ');
  
  i=-1;
  
  do{
    i=i+1;
    fscanf(fp,"%c",&typ[i]);
    
  }while(typ[i]!=' ');

 
  fscanf(fp,"%d ",&v);
  p = Pokemon_create(ident,esp,typ,v);
  return p;
}
void Pokemon_to_file(FILE *fp,Pokemon*p){
  int i=-1;
   
  fprintf(fp,"%d ",p->identifiant);
  
  do{
    i++;
    fprintf (fp,"%c",p->espece[i]);
    
  }while(p->espece[i]!=' ');
  i=-1;
  do{
    i++;
    fprintf(fp,"%c",p->type[i]);
  
  }while(p->type[i]!=' ');
  
  fprintf(fp,"5 \n");
  
}
void Pokemon_to_map(map *m, Pokemon *p, FILE *fp){
  int i,j,k,a;
  srand(time(NULL));
  fseek(fp, 0,SEEK_SET);
  fscanf(fp, "%d",&a);
  printf ("\n Il y aura en permanance %d pokemons sur la carte \n \n",a);
  for(k=0;k<a;k++){
      do{

    i=rand()%(m->lig-1)+1;
    j=rand()%(m->col-1)+1;
      }while (estVide(m,i,j)==0);
  m->elt[i][j]='*';
  }
}

void Pokemon_echange(Pokemon *a,Pokemon *b)
{
  Pokemon *c = Pokemon_create(a->identifiant,a->espece,a->type,a->vie);
  a = b;
  b =c;
}

int estVivant(Pokemon * p,Pokemon * a)
{
  if((p->vie<=0)||(a->vie<=0))
    return 0;
  else
    return 1;
}

vecPoke * vecPoke_init(int a){
  vecPoke *vec;
  
  int i;
  vec=(vecPoke *) malloc (sizeof(vec));
  vec->nbpoke=a;
  vec->elt=  malloc (a*sizeof(Pokemon*));
  for (i=0;i<=vec->nbpoke;i++)
    vec-> elt [i]= (Pokemon*)malloc (sizeof (Pokemon));
  return vec;
   }

void vecPoke_free(vecPoke *vec){
  int i;
  for (i=0;i<=vec->nbpoke;i++)
    free(vec->elt [i]);
  free(vec->elt);
  free (vec);
}
void vecPoke_copy(vecPoke *a, vecPoke *b){// copy a in b
  int i;
  b->nbpoke=a->nbpoke;
  for(i=0;i<=a->nbpoke;i++)
  b->elt[i]=a->elt[i];
  }

void  vecPoke_ajout(Pokemon  *p, vecPoke *vec)
{
  
  vecPoke * tmp = vecPoke_init(vec->nbpoke);
  vecPoke_copy(vec,tmp);
  tmp->nbpoke=tmp->nbpoke+1;
  tmp->elt[tmp->nbpoke]=p;
  vec->elt =  realloc (vec->elt,tmp->nbpoke*sizeof(Pokemon));
  
  vecPoke_copy(tmp,vec);
  free(tmp);
  
}

void vecPoke_retrait(Pokemon *p, vecPoke *vec){
  vecPoke * tmp = vecPoke_init(vec->nbpoke);
  vecPoke_copy(vec,tmp);
  tmp->nbpoke=tmp->nbpoke-1;
  tmp->elt[tmp->nbpoke]=p;
  vec->elt =  realloc (vec->elt,tmp->nbpoke*sizeof(Pokemon));
  
  vecPoke_copy(tmp,vec);
  free(tmp);
}

void vecPoke_print(vecPoke *vec)
{
  int i;
  for (i=1;i<=vec->nbpoke;i++)
    Pokemon_print(vec->elt[i]);
}

Pokemon * Pokemon_from_vecPoke(int a,vecPoke *vec)
{
  Pokemon *tmp;
  int i=1;
  while(i<=vec->nbpoke){
    tmp=vec->elt[a];
    i++;
    if (tmp->identifiant==a)
      return tmp;
  }
  printf("Il n'y a de pokemon avec cette identifiant dans votre sac");
  return tmp;
}



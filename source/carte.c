#include "carte.h"


map* map_create(int lig, int col){
  map *m;
  int i;
  m = (map*) malloc(sizeof(m));
  m->lig = lig;
  m->col = col;

  m->elt = malloc (lig * sizeof(char*));
  for(i=0; i<m->lig; i++)
    m->elt[i] = (char*) malloc (col* sizeof(char));
  
  return m;
}


void map_free(map * m){
  int i;
  for(i=0; i < m->lig; i++){
    free(m->elt[i]);
  }
  free(m->elt);
  free(m);
}

void map_print(map * m){
  int i, j;
  
  for(i=0; i < m->lig; i++){
    for(j=0; j < m->col; j++){
      printf("%c", m->elt[i][j]);
    }
    printf("\n");
  }
}

map * map_from_file(FILE * fp){
  int i, j, lig, col;
  
  fscanf(fp, "%d %d", &lig, &col);
  
  map * m = map_create(lig, col);
  for(i=0; i < m->lig; i++){
    fseek(fp,1,SEEK_CUR);
    for(j=0; j < m->col; j++){
      fscanf(fp, "%c", &m->elt[i][j]);
    }  
  }
  return m;
  }





player* player_create(){
  player * p;
  p=(player*) malloc (sizeof (player));  
  p->sac =creeListe();
  p->pos[0]=1;
  p->pos[1]=1;
  p->identpok=12;
  return p;
}

void player_free(player *p){
	freeListe(p->sac);
	free(p);
}
void playerTomap(player *p,map *m){
  int a = p->pos[0];
  int b = p->pos[1];
  m->elt[a][b]='x';
}


char getMap(map *m, int a, int b)
{
  return m->elt[a][b];
}


void changePosition(player *j,map *m,char c)
{
    

    if (c=='l'&& getMap(m,j->pos[0]+1,j->pos[1])!='#'){
     
      m->elt[j->pos[0]][j->pos[1]]=' ';//faire la fonction matrice_set
      j->pos[0]=(j->pos[0])+1;
    } 
    if (c=='o'&& m->elt[(j->pos[0])-1][j->pos[1]]!='#'){
      m->elt[j->pos[0]][j->pos[1]]=' ';
      j->pos[0]=j->pos[0]-1;
    }
    if (c=='k'&& m->elt[(j->pos[0])][(j->pos[1])-1]!='#'){
       m->elt[j->pos[0]][j->pos[1]]=' ';
       j->pos[1]=j->pos[1]-1;
    }
    if (c=='m' && m->elt[(j->pos[0])][(j->pos[1])+1]!='#'){
       m->elt[j->pos[0]][j->pos[1]]=' ';
       j->pos[1]=j->pos[1]+1;
    }
   
}

int estVide(map *m,int lig,int col){

  if (m->lig <=lig || m->col<= col){
    printf("Erreur estVide");
    return 0;
  }
    
  if (getMap(m,lig,col)==' ')
    return 1;
  else
    return 0;
}


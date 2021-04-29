#include "file.h"

File *initialiser()
{
    File *file = malloc(sizeof(*file));
    file->premier = NULL;
    return file;
}
void enfiler(File *file, Pokemon* nPoke)
{
    Elt *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->poke = nPoke;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide*/
    {
      /*On se positionne à la fin de la file*/
        Elt *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier*/
    {
        file->premier = nouveau;
    }
   
}
void afficherFile(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Elt *element = file->premier;

    while (element != NULL)
    {
      Pokemon_print(element->poke);
        element = element->suivant;
    }

    printf("\n");
    
}

File *readpokemon(FILE *fp)
{
  File * Fsauvage=initialiser();
  Pokemon *tmp;
  fseek(fp,0,SEEK_END);
  int nbcar =ftell(fp);
  
  fseek(fp,2,SEEK_SET);
 
  while(ftell(fp)!= nbcar){
    tmp=Pokemon_from_file(fp);
    enfiler(Fsauvage, tmp); 
  }
  return Fsauvage;
}





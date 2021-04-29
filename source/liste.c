#include "liste.h"

Liste *creeListe()
{
  Liste *liste = malloc(sizeof(*liste));
  Element *element = malloc(sizeof(*element));
  if (liste == NULL || element == NULL)
    {
      exit(EXIT_FAILURE);
    }
  element->nombre = 0;
  element->suivant = NULL;
  liste->premier = element;
  return liste;
}

void freeListe(Liste*liste)
{
  Element *element=liste->premier;
  while (element != NULL)
    {
      liste->premier=element->suivant;
      free(element);
      element=liste->premier;
    }
  free(liste);
}

void inserer(Liste *liste,int nvNombre)
{
  Element *nouveau=malloc(sizeof(*nouveau));
  if (liste==NULL || nouveau==NULL)
    {
      exit(EXIT_FAILURE);
    }
  nouveau->nombre=nvNombre;
  nouveau->suivant=liste->premier;
  liste->premier=nouveau;
}


void afficherListe(Liste*liste)
{
  if (liste == NULL)
    {
      exit(EXIT_FAILURE);
    }
  Element *actuel = liste->premier;
  while (actuel->nombre!=0 && actuel != NULL)
    {
      printf("%d-> ", actuel->nombre);
      actuel = actuel->suivant;
    }
  printf("Fin de la liste\n");
}

  
  
void supprimer(Liste*liste,int degage)
{
  if(liste==NULL)
    {
      exit(EXIT_FAILURE);
    }
   Element*actuel=liste->premier;
  if(actuel->nombre == degage)
    {
      Element*aSupprimer=actuel;
      actuel=actuel->suivant;
      free(aSupprimer);
    }
  while(actuel->suivant != NULL)
    {
      if(actuel->suivant->nombre == degage)
	{
	  Element *aSupprimer=actuel->suivant;
	  actuel->suivant=actuel->suivant->suivant;
	  free (aSupprimer);
	}
      actuel=actuel->suivant;
    }
 
}


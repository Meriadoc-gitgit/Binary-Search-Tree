#include <stdio.h>
#include <stdlib.h>
#include "arbre_lexicographique.h"


int main(int argc, char **argv)
{
  
  /* a completer. Exercice 4, question 4 */

  PNoeud pn1 = creer_noeud('a');
  PNoeud pn2 = NULL;
  inserer_lettre(&pn1, &pn2, 'b');

  /* Ajout de mots */
  pn1 = ajouter_mot(pn1, "bateau");
  pn1 = ajouter_mot(pn1, "arbalette");
  pn1 = ajouter_mot(pn1, "aval");
  pn1 = ajouter_mot(pn1, "avion");
  pn1 = ajouter_mot(pn1, "arbre");

  pn1 = lire_dico("french_za");
  /* affichage */
  afficher_dico(pn1);
  printf("\n");
  
  /* Liberer */
  detruire_dico(pn1);
  
  return 0;
}

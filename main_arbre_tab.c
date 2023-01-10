#include <stdlib.h>
#include <stdio.h>
#include "arbre_lexicographique_tab.h"

int main(int argc, char **argv) {

  /* a completer. Exercice 6, question 2 */
  PNoeudTab pnt1 = creer_noeud('.');

  pnt1 = ajouter_mot(pnt1, "bateau");
  pnt1 = ajouter_mot(pnt1, "arbalette");
  pnt1 = ajouter_mot(pnt1, "aval");
  pnt1 = ajouter_mot(pnt1, "avion");

  /* Affichage */
  afficher_dico(pnt1);
  printf("\n");


  pnt1 = lire_dico("french_za");
  afficher_dico(pnt1);

  /* Liberer */
  detruire_dico(pnt1);
  
  return 0;
}

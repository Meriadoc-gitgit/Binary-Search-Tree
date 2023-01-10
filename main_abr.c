#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "abr.h"

int main(int argc, char **argv)
{
  /* a completer. Exercice 3, question 1 */

  /* Creation de Lm_mot */
  Lm_mot *l1 = creer_Lm_mot("bateau");

  Nd_mot *n1 = Lm2abr(l1);
  Nd_mot *n2 = chercher_Nd_mot(n1, "bateau");


  /* Affichage */
  printf("Taille de l1 : %d\n", taille_Lmot(l1));
  printf("%d\n", n2!=NULL);

  return 0;
}

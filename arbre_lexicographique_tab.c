#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arbre_lexicographique_tab.h"


PNoeudTab creer_noeud(char lettre) {
  /* a completer. Exercice 6, question 1 */

  PNoeudTab pn = (PNoeudTab)malloc(sizeof(NoeudTab));
  if (pn==NULL) {
    printf("Impossible d'allouer un tableau de noeud\n");
    return NULL;
  }

  pn->lettre = lettre;
  pn->fin_de_mot = non_fin;
  
  for (int i=0;i<26;i++) 
    pn->fils[i] = NULL;

  return pn;
}


PNoeudTab ajouter_mot(PNoeudTab racine, char *mot) {
  /* a completer. Exercice 6, question 1 */

  if (strlen(mot)==0) 
    return NULL;

  PNoeudTab n = NULL;
  if (racine->fils[(int)mot[0]-97]) {
    if (racine->fils[(int)mot[0]-97]->lettre==mot[0])
      n = racine->fils[(int)mot[0]-97];
  }
  else 
      n = creer_noeud(mot[0]);

  racine->fils[(int)mot[0]-97] = n;

  if (strlen(mot) == 1) 
    n->fin_de_mot = fin;
  else 
    n = ajouter_mot(n,mot+1);
  
  return racine;
}

void afficher_mots(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index) {
  /* a completer. Exercice 6, question 1 */

  if (n==NULL) {
    printf("Erreur lors de l'allocation\n");
    return ;
  }
  if (n->lettre!='.') {
    mot_en_cours[index] = n->lettre;
    index++;
  }

  int tmp = 0;
  for (int i=0;i<26;i++) {
    if (n->fils[i]) 
      tmp = 1;
  }

  if (n->fin_de_mot==fin) {
    for (int i=0;i<index;i++) 
        putchar(mot_en_cours[i]);
      printf("\n");
      
    if (tmp) {
      n->fin_de_mot = non_fin;
      for (int i=0;i<26;i++) {
        if (n->fils[i]) {
          afficher_mots(n->fils[i], mot_en_cours, index);
        }
      }
    }
  }
  else {
    for (int i=0;i<26;i++) {
      if (n->fils[i]) {
        afficher_mots(n->fils[i], mot_en_cours, index);
      }
    }
  }
}

void afficher_dico(PNoeudTab racine) {
  /* a completer. Exercice 6, question 1 */

  char mot[26];

  for (int i=0;i<26;i++) {
    if (racine->fils[i])
      afficher_mots(racine->fils[i],mot,0);
  }
}


void detruire_dico(PNoeudTab dico) {
  /* a completer. Exercice 6, question 1 */

  for (int i=0;i<26;i++) {
    if (dico->fils[i]) {
      detruire_dico(dico->fils[i]);
      free(dico);
    }
  }
}

int rechercher_mot(PNoeudTab dico, char *mot) {
  /* a completer. Exercice 6, question 1 */
  if (dico->fils[(int)mot[0]-97]) {
    if (dico->fils[(int)mot[0]-97]->lettre == mot[0]) {
      if (strlen(mot)==1) {
        if (dico->fils[(int)mot[0]-97]->fin_de_mot==fin)
          return 1;
        return 0;
      }
    }
  }
  return rechercher_mot(dico->fils[(int)mot[0]-97], mot+1);
}


PNoeudTab lire_dico(const char *nom_fichier) {
  /* a completer. Exercice 6, question 2 */

  FILE *f = fopen(nom_fichier, "r");
  if (f==NULL) {
    printf("Erreur d'ouverture\n");
    return NULL;
  }

  PNoeudTab dico = creer_noeud('.');

  char buffer[256];
  char *res = fgets(buffer, 256, f);
  char a[26];

  while (res!=NULL) {
    sscanf(buffer, "%s",a);
    res = fgets(buffer, 256, f);
    dico = ajouter_mot(dico, a);
    //printf("%s\n",a);
  }
  fclose(f);

  return dico;
}



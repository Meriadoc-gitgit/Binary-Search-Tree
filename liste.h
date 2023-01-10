#ifndef LIST_H
#define LIST_H

typedef struct Lm_mot_ {
  char *mot; // moi mot se o trong 1 khuon rieng -> khong qua phuc tap
  struct Lm_mot_ *suiv;
} Lm_mot; // cai struct nay de phuc vu cho viec tao abr.h, cat doi ra roi ghep lai vao thanh abr.h

/* couper une liste en 2 */
Lm_mot *part_Lmot(Lm_mot **pl);

/* creation d'un element de liste */
Lm_mot *creer_Lm_mot(char *mot);

/* ajout en place d'un mot dans la liste donnee en premier argument */
Lm_mot *ajouter_Lmot(Lm_mot *lm, char *mot);

/* affichage de la liste donnee en argument */
void afficher_Lmot(Lm_mot *lm);

/* taille de la liste donnee en argument */
int taille_Lmot(Lm_mot *lm);

/* destruction de la liste donnee en argument */
void detruire_Lmot(Lm_mot *lm);

/* Initialisation d'une liste chainee de mots depuis
   un fichier contenant un ensemble de mots */
Lm_mot *lire_dico_Lmot(const char *nom_fichier);

/* Recherche d'un mot dans la liste */
Lm_mot *chercher_Lm_mot(Lm_mot *lm, const char *mot);

#endif

#include "ELT.h"

struct Noeud {ELT val; struct Noeud * g; struct Noeud * d;};
typedef struct Noeud * ARBRE;

ARBRE ARBRE_creer(ELT, ARBRE, ARBRE);
void ARBRE_lire(ARBRE, ELT *, bool *);
void ARBRE_ss_ag(ARBRE, ARBRE *, bool *);
void ARBRE_ss_ad(ARBRE, ARBRE *, bool *);
void ARBRE_aff_valeur(ARBRE, ELT, bool *);
void ARBRE_aff_ss_ag(ARBRE, ARBRE, bool *);
void ARBRE_aff_ss_ad(ARBRE, ARBRE, bool *);
void ARBRE_afficher(ARBRE);

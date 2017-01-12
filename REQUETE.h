#include "ARBRE.h"

// une requete est un arbre binaire
typedef ARBRE REQUETE;

// Creation de requete 
// Retourne l'arbre/requete dont la racine a pour valeur un operateur algebrique et pour sous-arbres/requetes des requetes 
REQUETE REQUETE_creer(OPERATEUR,REQUETE,REQUETE);

// Affichage d'une requete
// Affichage prefixe des operateurs d'un arbre/requete selon un parcours en profondeur a gauche d'abord (cf. enonce du projet pour des exemples)
void REQUETE_afficher(REQUETE);

// Evaluation simple de requete (facile)
// Evaluation recursive de la requete, en supposant que la requete est bien formee (les relations sont aux feuilles, les noeuds avec un seul fils ont ce fils situe a gauche et codent des operateurs unaires verifiant les conditions pour leur application aux résultats de leur sous-requete de sous-arbre gauche, les noeuds avec deux fils codent des operateurs binaires verifiant les conditions pour leur application aux resultats de leurs sous-requetes des sous-arbres gauche et droit) [les conditions des operateurs sont donnees dans OPERATEURS.h et a coder dans OPERATEUR.c]
RELATION REQUETE_evaluer(REQUETE);

/*
L'evaluation de requete avec verification ci-dessous est la partie la plus difficile du projet, donc a faire quand tout le reste fonctionne
*/

// Evaluation et verification de requete (difficile)
// Evaluation recursive de la requete tout en verifiant que la requete est bien formee (cf. ci-dessus)
// Si le booleen passe par adresse est 'true' alors il y a une erreur (la requete est mal formee), sinon le resultat de l'evaluation est dans la relation passee par adresse
void REQUETE_verifeval(REQUETE,RELATION*,bool*);

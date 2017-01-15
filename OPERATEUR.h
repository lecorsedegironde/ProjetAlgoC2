#include <stdbool.h>
#include "RELATION.h"

// Type OPERATEUR_RELATIONNEL
typedef enum op_rel {
    op_relation,
    op_selection,
    op_projection,
    op_renommage,
    op_jointure,
    op_union,
    op_intersection,
    op_difference
} OPERATEUR_RELATIONNEL;

// Type OPERATEUR pour les noeuds de REQUETE 
typedef struct {
    // type d'operateur
    OPERATEUR_RELATIONNEL op; // operateur modelise
    // champ significatif pour une relation (noeud feuille)
    RELATION rel;
    // champ significatif pour la selection
    char **val_sel; // selection : valeurs de selection des attributs
    int nb_att_sel; // nombre d'attributs dans la relation ou selectionner
    // champs significatifs pour la projection
    char **att_proj; //attributs de projection
    int nb_att_proj; // nombre d'attributs projetes
    // champs significatifs pour le renommage
    char *ancien_nom_ren;
    char *nouveau_nom_ren;
} OPERATEUR;

// Fonctions de creation d'operateur : chaque fonction prend en entree les valeurs des champs significatifs pour l'operateur cree 
// Le champ significatif est : rel
OPERATEUR OPERATEUR_relation_creer(RELATION);

// Les champs significatifs sont : val_sel, nb_att_sel
OPERATEUR OPERATEUR_selection_creer(char **, int);

// Les champs significatifs sont : att_proj, nb_att_proj
OPERATEUR OPERATEUR_projection_creer(char **, int);

// Les champs significatifs sont : ancien_nom_ren, nouveau_nom_ren
OPERATEUR OPERATEUR_renommage_creer(char *, char *);

// Pas de champ significatif pour les operateurs binaires
OPERATEUR OPERATEUR_jointure_creer();

OPERATEUR OPERATEUR_union_creer();

OPERATEUR OPERATEUR_intersection_creer();

OPERATEUR OPERATEUR_difference_creer();

// Fonction d'affichage des operateurs
/*
  L'affichage se fait selon le type d'operateur (sans saut de ligne a la fin de l'affichage), au caractere près (!) :
  - op_relation : affiche uniquement le nom de la relation, par exemple : film
  - op_selection : affiche SELECTION["v1",...,"vN"] ou v1,...,vN est le tuple de selection stocke dans le champ val_sel, par exemple SELECTION["","Georges Lucas",""]
  - op_projection : affiche PROJECTION[a1,...,aN] ou a1,...,aN sont les attributs de projection stocke dans le champ att_proj, par exemple PROJECTION[Spectateur,Titre]
  - op_renommage : affiche RENOMMAGE[ancien->nouveau] ou ancien est le nom de l'attribut a renommer stocke dans ancien_nom_ren et nouveau est le nom a donner par renommage stocke dans nouveau_nom_ren
  - op_jointure : affiche JOINTURE 
  - op_union : affiche UNION
  - op_intersection : affiche INTERSECTION
  - op_difference : affiche DIFFERENCE
 */
void OPERATEUR_afficher(OPERATEUR);

// Fonction retournant le type d'un operateur
OPERATEUR_RELATIONNEL OPERATEUR_type(OPERATEUR);

// Fonction d'evaluation des operateurs
// L'evaluation d'un operateur relation est la relation qui y est stockee
RELATION OPERATEUR_relation_evaluer(OPERATEUR);

// L'evaluation d'un operateur unaire (selection, projection et renommage) est le resultat de l'application de cet operateur a une relation
RELATION OPERATEUR_unaire_evaluer(OPERATEUR, RELATION);

// L'evaluation d'un operateur binaire (jointure, union, intersection et difference) est le resultat de l'application de cet operateur a deux relations
RELATION OPERATEUR_binaire_evaluer(OPERATEUR, RELATION, RELATION);

/*
Les fonctions ci-dessous ne sont necessaires qu'a l'evaluation de requete avec verification que la requete est bien formee. 
C'est la partie la plus difficile du projet, donc a faire quand tout le reste fonctionne
*/

// Fonction de validation des operateurs
// Pas de validation pour un operateur relation
/* La validation d'un operateur unaire ou binaire consiste a verifier qu'il peut etre applique a une relation donnee:
   - la taille d'un tuple de selection doit etre egale au nombre de colonnes de la relation
   - les attributs de projection doivent etre des attributs de la relation
   - l'attribut a renommer doit etre un attribut de la relation et le nom de renommage ne doit pas deja être un nom d'attribut de la relation
   - les relations dont on veut l'union, l'intersection ou la difference doivent etre de meme schema 
*/
bool OPERATEUR_unaire_valider(OPERATEUR, RELATION);

bool OPERATEUR_binaire_valider(OPERATEUR, RELATION, RELATION);


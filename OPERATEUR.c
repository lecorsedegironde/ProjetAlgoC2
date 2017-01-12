// Etudiant : Bastien Hoffstetter
// Enseignant : François Goasdoue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OPERATEUR.h"

//=======================================================================================
// OPERATEURS UNAIRES
//=======================================================================================

/*Module OPERATEUR_relation_creer
Paramètre :
    RELATION rel - Champ significatif pour une relation (noeud feuille)
Retourne : OPERATEUR
Structure :
    op
    rel
*/
OPERATEUR OPERATEUR_relation_creer(RELATION rel) {
    OPERATEUR operateur;
    operateur.op = op_relation;
    operateur.rel = rel;

    return operateur;
}

/*Module OPERATEUR_selection_creer
Paramètres :
    char ** valeurSelection - Valeur de sélection des attributs
    int nbAttrProj - Nombre d'atributs projetés
Retourne : OPERATEUR
Structure :
    op
    val_sel
    nb_att_sel
*/
OPERATEUR OPERATEUR_selection_creer(char **valeurSelection, int nbAttrProj) {
    OPERATEUR operateur;
    operateur.op = op_selection;
    operateur.val_sel = valeurSelection;
    operateur.nb_att_sel = nbAttrProj;

    return operateur;
}

/*Module OPERATEUR_projection_creer
Paramètres :
    char ** attrProj - Atributs de projection
    int nbAttrProj - Nombre d'attributs projetés
Retourne : OPERATEUR
Structure :
    op
    att_proj
    nb_att_proj
*/
OPERATEUR OPERATEUR_projection_creer(char **attrProj, int nbAttrProj) {
    OPERATEUR operateur;
    operateur.op = op_projection;
    operateur.att_proj = attrProj;
    operateur.nb_att_proj = nbAttrProj;

    return operateur;
}

/*Module OPERATEUR_renommage_creer
Paramètres :
    char * ancienNom - Ancien nom
    char * nvNom - Nouveau nom
Retourne : OPERATEUR
Structure :
    op
    ancien_nom_ren
    nouveau_nom_ren
*/
OPERATEUR OPERATEUR_renommage_creer(char *ancienNom, char *nvNom) {
    OPERATEUR operateur;
    operateur.op = op_renommage;
    operateur.ancien_nom_ren = ancienNom;
    operateur.nouveau_nom_ren = nvNom;

    return operateur;
}

//=======================================================================================
// OPERATEURS BINAIRES
//=======================================================================================

/*Module OPERATEUR_jointure_creer
Retourne : OPERATEUR
Structure :
    op
*/
OPERATEUR OPERATEUR_jointure_creer() {
    OPERATEUR operateur;
    operateur.op = op_jointure;

    return operateur;
}

/*Module OPERATEUR_union_creer
Retourne : OPERATEUR
Structure :
    op
*/
OPERATEUR OPERATEUR_union_creer() {
    OPERATEUR operateur;
    operateur.op = op_union;

    return operateur;
}

/*Module OPERATEUR_intersection_creer
Retourne : OPERATEUR
Structure :
    op
*/
OPERATEUR OPERATEUR_intersection_creer() {
    OPERATEUR operateur;
    operateur.op = op_intersection;

    return operateur;
}

/*Module OPERATEUR_difference_creer
Retourne : OPERATEUR
Structure :
    op
*/
OPERATEUR OPERATEUR_difference_creer() {
    OPERATEUR operateur;
    operateur.op = op_difference;

    return operateur;
}
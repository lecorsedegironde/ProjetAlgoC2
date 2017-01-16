// Etudiant : Bastien Hoffstetter
// Enseignant : François Goasdoue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OPERATEUR.h"

//=======================================================================================
// CREATION OPERATEURS UNAIRES
//=======================================================================================

/*
 * Module OPERATEUR_relation_creer
 * Paramètre :
 *      RELATION rel - Champ significatif pour une relation (noeud feuille)
 * Retourne : OPERATEUR
 * Structure :
 *      op
 *      rel
*/
OPERATEUR OPERATEUR_relation_creer(RELATION rel) {
    OPERATEUR operateur;
    operateur.op = op_relation;
    operateur.rel = rel;

    return operateur;
}

/*
 * Module OPERATEUR_selection_creer
 * Paramètres :
 *    char ** valeurSelection - Valeur de sélection des attributs
 *    int nbAttrProj - Nombre d'atributs projetés
 * Retourne : OPERATEUR
 * Structure :
 *    op
 *    val_sel
 *    nb_att_sel
*/
OPERATEUR OPERATEUR_selection_creer(char **valeurSelection, int nbAttrProj) {
    OPERATEUR operateur;
    operateur.op = op_selection;
    operateur.val_sel = valeurSelection;
    operateur.nb_att_sel = nbAttrProj;

    return operateur;
}

/*
 * Module OPERATEUR_projection_creer
 * Paramètres :
 *    char ** attrProj - Atributs de projection
 *    int nbAttrProj - Nombre d'attributs projetés
 * Retourne : OPERATEUR
 * Structure :
 *    op
 *    att_proj
 *    nb_att_proj
*/
OPERATEUR OPERATEUR_projection_creer(char **attrProj, int nbAttrProj) {
    OPERATEUR operateur;
    operateur.op = op_projection;
    operateur.att_proj = attrProj;
    operateur.nb_att_proj = nbAttrProj;

    return operateur;
}

/*
 * Module OPERATEUR_renommage_creer
 * Paramètres :
 *    char * ancienNom - Ancien nom
 *    char * nvNom - Nouveau nom
 * Retourne : OPERATEUR
 * Structure :
 *    op
 *    ancien_nom_ren
 *    nouveau_nom_ren
*/
OPERATEUR OPERATEUR_renommage_creer(char *ancienNom, char *nvNom) {
    OPERATEUR operateur;
    operateur.op = op_renommage;
    operateur.ancien_nom_ren = ancienNom;
    operateur.nouveau_nom_ren = nvNom;

    return operateur;
}

//=======================================================================================
// CREATION OPERATEURS BINAIRES
//=======================================================================================

/*
 * Module OPERATEUR_jointure_creer
 * Retourne : OPERATEUR
 * Structure :
 *    op
*/
OPERATEUR OPERATEUR_jointure_creer() {
    OPERATEUR operateur;
    operateur.op = op_jointure;

    return operateur;
}

/*
 * Module OPERATEUR_union_creer
 * Retourne : OPERATEUR
 * Structure :
 *    op
*/
OPERATEUR OPERATEUR_union_creer() {
    OPERATEUR operateur;
    operateur.op = op_union;

    return operateur;
}

/*
 * Module OPERATEUR_intersection_creer
 * Retourne : OPERATEUR
 * Structure :
 *    op
*/
OPERATEUR OPERATEUR_intersection_creer() {
    OPERATEUR operateur;
    operateur.op = op_intersection;

    return operateur;
}

/*
 * Module OPERATEUR_difference_creer
 * Retourne : OPERATEUR
 * Structure :
 *    op
*/
OPERATEUR OPERATEUR_difference_creer() {
    OPERATEUR operateur;
    operateur.op = op_difference;

    return operateur;
}

//=======================================================================================
//AFFICHAGE OPERATEUR
//=======================================================================================

/*
 * Module OPERATEUR_afficher
 * Paramètre :
 *      OPERATEUR op - Opérateur a afficher
 * Retourne : void
*/
void OPERATEUR_afficher(OPERATEUR op) {
    int i = 0;
    switch (op.op) {
        case op_relation:
            printf("%s", op.rel.nom);
            break;
        case op_selection:
            printf("SELECTION[");
            for (i = 0; i < op.nb_att_sel; i++) {
                printf("\"%s\"", op.val_sel[i]);
                if (i < op.nb_att_sel - 1) printf(",");
            }
            printf("]");
            break;
        case op_projection:
            printf("PROJECTION[");
            for (i = 0; i < op.nb_att_proj; i++) {
                printf("%s", op.att_proj[i]);
                if (i < op.nb_att_proj - 1) printf(",");
            }
            printf("]");
            break;
        case op_renommage:
            printf("RENOMAGE[%s->%s]", op.ancien_nom_ren, op.nouveau_nom_ren);
            break;
        case op_jointure:
            printf("JOINTURE");
            break;
        case op_union:
            printf("UNION");
            break;
        case op_intersection:
            printf("INTERSECTION");
            break;
        case op_difference:
            printf("DIFFERENCE");
            break;
        default:
            break;
    }
}

/*
 * Module OPERATEUR_type
 * Paramètre :
 *      OPERATEUR op - Opérateur dont le titre est à afficher
 * Retourne : OPERATEUR_RELATIONNEL
 */
OPERATEUR_RELATIONNEL OPERATEUR_type(OPERATEUR op) {
    return op.op;
}

/*
 * Module OPERATEUR_relation_evaluer
 * Paramètre :
 *      OPERATEUR op : Opérateur de relation qui est à évaluer
 * Retourne : RELATION
 */
RELATION OPERATEUR_relation_evaluer(OPERATEUR op) {
    return op.rel;
}

/*
 * Module OPERATEUR_unaire_evaluer
 * Opérateurs unaires : selection, projection et renommage
 * Paramètres :
 *      OPERATEUR op : Opérateur unaire à évaluer
 *      RELATION rel : Relation sur laquelle on applique l'opérateur
 * Retourne : RELATION
 *
 */
RELATION OPERATEUR_unaire_evaluer(OPERATEUR op, RELATION rel) {
    switch (op.op) {
        case op_selection:
            return RELATION_SELECTION(rel, op.val_sel);
        case op_projection:
            return RELATION_PROJECTION(rel, op.att_proj, op.nb_att_proj);
        case op_renommage:
            return RELATION_RENOMMAGE(rel, op.ancien_nom_ren, op.nouveau_nom_ren);
        default:
            //Temporary workaround to avoid compilation warning
            //TODO: Change when needed
            return rel;
    }
}

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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
 */
OPERATEUR_RELATIONNEL OPERATEUR_type(OPERATEUR op) {
    return op.op;
}

/*
 * Module OPERATEUR_relation_evaluer
 * Paramètre :
 *      OPERATEUR op : Opérateur de relation qui est à évaluer
 * Retourne : RELATION
 *
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

/*
 * Module OPERATEUR_binaire_evaluer
 * Opérateurs binaires : jointure, union, intersection et difference
 * Paramètres :
 *      OPERATEUR op : Opérateur unaire à évaluer
 *      RELATION rel1, rel2 : Relations sur lesquelles on applique l'opérateur
 * Retourne : RELATION
 *
 */
RELATION OPERATEUR_binaire_evaluer(OPERATEUR op, RELATION rel1, RELATION rel2) {
    switch (op.op) {

        case op_jointure:
            return RELATION_JOINTURE(rel1, rel2);
        case op_union:
            return RELATION_UNION(rel1, rel2);
        case op_intersection:
            return RELATION_INTERSECTION(rel1, rel2);
        case op_difference:
            return RELATION_DIFFERENCE(rel1, rel2);
        default:
            //Temporary workaround to avoid compilation warning
            //TODO: Change when needed
            return rel1;
    }
}

/*
 * Module OPERATEUR_unaire_valider
 * Paramètres :
 *      OPERATEUR op : Opéarateur unaire à valider
 *      RELATION rel : La relation sur laquelle l'opérateur est censé s'appliquer
 * Retourne : bool
 *
 */
bool OPERATEUR_unaire_valider(OPERATEUR op, RELATION rel) {
    //Switch case sur les opérateurs unaires
    //Pas besoin de test pour relation

    //Booleen retour, par défaut on estime l'opérateur valide
    bool retourValidation = true;
    //Booleen pour la validation de la projection
    bool projection = false;

    //Récupération du schéma de la relation et de son arite
    char **relationAttr = RELATION_schema(rel);
    int relationArite = RELATION_arite(rel);

    //Création d'itérateurs
    int i = 0, j = 0;

    switch (op.op) {
        case op_selection:
            //la taille d'un tuple de selection doit etre egale au nombre de colonnes de la relation
            if (op.nb_att_sel != rel.colonnes) retourValidation = false;
            break;
        case op_projection:
            //les attributs de projection doivent etre des attributs de la relation
            if (op.nb_att_proj <= rel.colonnes) {
                //Il y a le bon nombre de colonnes, on peut vérifier la concordance des attributs
                i = op.nb_att_proj;
                while (i--) {
                    //Pour chaque attribut de projection, on regarde si il existe dans le shéma de la relation
                    j = relationArite;
                    while (j--) {
                        //Si il y a concordance entre les deux noms on quitte cette boucle
                        if (!strcmp(op.att_proj[i], relationAttr[j])) {
                            projection = true;
                            j = 0;
                        } else {
                            projection = false;
                        }
                    }
                    //Si aucunne concordance n'a été trouvée, l'opérateur n'est pas valide
                    if (!projection) retourValidation = false;
                }
            } else {
                //Il y a plus d'attributs pour la projection que d'attributs dans la relation
                retourValidation = false;
            }
            break;
        case op_renommage:
            //l'attribut a renommer doit etre un attribut de la relation et le nom de renommage ne doit
            // pas deja être un nom d'attribut de la relation
            //On parcours le schéma de la relation pour vérifier l'éxistence de l'attribut à renommer
            i = relationArite;
            while (i--) {
                if (!strcmp(op.ancien_nom_ren, relationAttr[i])) {
                    retourValidation = true;
                    i = 0;
                } else {
                    retourValidation = false;
                }
            }
            //Si il a bien été trouvé, on vérifie que l'autre attribut existe pas déjà
            i = relationArite;  //Remise à 0 de l'itérateur
            while (i-- && retourValidation) {
                if (!strcmp(op.nouveau_nom_ren, relationAttr[i])) {
                    retourValidation = false;
                }
            }

            break;
        default:
            //Si défaut : pas normal et on retourne false
            retourValidation = false;
            break;
    }

    return retourValidation;
}


/*
 * Module OPERATEUR_binaire_valider
 * Paramètres :
 *      OPERATEUR op : Opéarateur unaire à valider
 *      RELATION rel1, rel2 : Les relations sur lesquelle l'opérateur est censé s'appliquer
 * Retourne : bool
 *
 */
bool OPERATEUR_binaire_valider(OPERATEUR op, RELATION rel1, RELATION rel2) {
    //les relations dont on veut l'union, l'intersection ou la difference doivent etre de meme schema
    //Booleen de retour, ici aussi on part du postulat que l'opérateur est vrai
    bool retourValidation = true;
    if (op.op == op_union || op.op == op_intersection || op.op == op_difference) {

        //Récupération des schémas de la relation et de son arite
        char **relation1Attr = RELATION_schema(rel1);
        int relation1Arite = RELATION_arite(rel1);
        char **relation2Attr = RELATION_schema(rel2);
        int relation2Arite = RELATION_arite(rel2);

        if (relation1Arite == relation2Arite) {
            while (relation1Arite-- && retourValidation) {
                retourValidation = !strcmp(relation1Attr[relation1Arite], relation2Attr[relation1Arite]);
            }
        } else {
            retourValidation = false;
        }
    } else if (op.op != op_jointure) {
        retourValidation = false;    //Opérateur unaire ou jointure
    }

    return retourValidation;
}


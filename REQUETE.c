// Etudiant : Bastien Hoffstetter
// Enseignant : François Goasdoue

#include <stdio.h>
#include "REQUETE.h"

/*
 * Module REQUETE_creer
 * Paramètres :
 *      OPERATEUR op : Opérateur de la requête
 *      REQUETE reqGauche, relDroite : Requetes pour lesquelles l'opérateur s'appliquera sur leur résultat
 * Retourne : REQUETE
 */
REQUETE REQUETE_creer(OPERATEUR op, REQUETE reqGauche, REQUETE reqDroite) {
    return ARBRE_creer(op, reqGauche, reqDroite);
}

/*
 * Module REQUETE_afficher
 * Paramètres :
 *      REQUETE req : Requête à afficher
 * Retourne : void
 */
void REQUETE_afficher(REQUETE req) {

    //Affichage de l'opérateur de la requête
    ELT_afficher(req->val);

    //Parcours en préfixe des fils de la requêtes
    if (req->g != NULL) {
        printf("(");
        REQUETE_afficher(req->g);
        if (req->d == NULL) printf(")");
    }

    if (req->d != NULL) {
        printf(",");
        REQUETE_afficher(req->d);
        printf(")");
    }
}
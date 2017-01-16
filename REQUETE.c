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


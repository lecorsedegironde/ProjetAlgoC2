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
 *
 * Création de la requête avec un opérateur et une sous-requête gauche et une sous-requête droite.
 *
 */
REQUETE REQUETE_creer(OPERATEUR op, REQUETE reqGauche, REQUETE reqDroite) {
    return ARBRE_creer(op, reqGauche, reqDroite);
}

/*
 * Module REQUETE_afficher
 * Paramètres :
 *      REQUETE req : Requête à afficher
 * Retourne : void
 *
 * Affichage récursif de la requête, avec la sous-requête entre parenthèses si l'opérateur est unaire, les sous-requêtes
 * entre parenthèses et séparées par une virgule si opérateur binaire et sans parenthèses si l'opérateur est une relation
 * et n'a donc pas de sous-requête.
 *
 */
void REQUETE_afficher(REQUETE req) {
    //Affichage de l'opérateur de la requête
    ELT_afficher(req->val);

    //Parcours en préfixe des fils de la requêtes
    if (req->g != NULL) {
        printf("(");
        //Si pas de fils droit, on ferme la parenthèse
        REQUETE_afficher(req->g);
        if (req->d == NULL) printf(")");
    }
    //Si on a un fils droit, on affiche la virgule
    if (req->d != NULL) {
        printf(",");
        REQUETE_afficher(req->d);
        printf(")");
    }
}

/*
 * Module REQUETE_evaluer
 * Paramètres :
 *      REQUETE req : Requête à évaluer
 * Retourne : RELATION
 *
 * Évaluation récursive de la requête, on évalue l'opérateur (unaire, binaire, relation) et on lui passe comme relations
 * à évaluer celles renvoyées par l'évaluation des sous-requêtes.
 *
 */
RELATION REQUETE_evaluer(REQUETE req) {
    //On teste si il existe un fils gauche
    if (req->g != NULL) {
        //Si il y a un fils droit, c'est un opérateur binaire
        if (req->d != NULL) {
            return OPERATEUR_binaire_evaluer(req->val, REQUETE_evaluer(req->g), REQUETE_evaluer(req->d));
        } else {
            //Sinon c'est un opérateur unaire
            return OPERATEUR_unaire_evaluer(req->val, REQUETE_evaluer(req->g));
        }
    } else {
        //Il n'y a pas de fils gauche donc la requête porte sur une relation
        return OPERATEUR_relation_evaluer(req->val);
    }
}

/*
 * Module REQUETE_verifeval
 * Paramètres :
 *      REQUETE req : La requête à vérifier
 *      RELATION * rel : Résultat de la requête si valide
 *      bool * err : Booléen qui annonce la validité de la requête
 * Retourne : void
 * Évaluation recursive de la requete tout en verifiant que la requete est bien formee, on commence par vérifier la
 * formation correcte des requêtes (unaire -> un unique fils gauche, binaire -> deux fils) puis on vérifie et
 * évalue les sous-requêtes, la formation correcte de l'opérateur et enfin on évalue celui-ci et le place dans le
 * pointeur sur relation. Le pointeur sur booléen est à vrai si la requête est mal formée.
 *
 */
void REQUETE_verifeval(REQUETE req, RELATION *rel, bool *err) {
    //Si err est déjà à true pas la peine de vérifier la requête elle ressortira fausse
    if (!*err) {
        //Booléen qui stocke la validité de l'opérateur
        bool valideOp;
        RELATION relationTestG;
        RELATION relationTestD;

        //Existe-t-il un fils gauche ?
        if (req->g != NULL) {
            //Si il existe un fils droit, cela doit être un opérateur binaire
            if (req->d != NULL) {
                //Opérateur binaire
                //Vérification récursive des sous parties la requête
                REQUETE_verifeval(req->g, &relationTestG, err);
                //Si la première sous-requête a renvoyé false, celle-ci ne sera pas évaluée
                REQUETE_verifeval(req->d, &relationTestD, err);
                //Si il n'y a toujours pas d'erreur
                if (!*err) {
                    //On peut alors tester la validité de l'opérateur
                    valideOp = OPERATEUR_binaire_valider(req->val, relationTestG, relationTestD);
                    if (valideOp) {
                        //Si l'opérateur est valide ont peut alors l'évaluer et mettre sa valeur dans rel
                        *rel = OPERATEUR_binaire_evaluer(req->val, relationTestG, relationTestD);
                    } else {
                        //Sinon la requête est fausse
                        *err = true;
                    }
                }
            } else {
                //Opérateur unaire
                //Vérification récursive du fils gauche
                REQUETE_verifeval(req->g, &relationTestG, err);
                if (!*err) {
                    //Si la validation donne la sous-requête correcte, on valide l'opérateur
                    valideOp = OPERATEUR_unaire_valider(req->val, relationTestG);
                    if (valideOp) {
                        //Si l'opérateur est valide ont peut alors l'évaluer et mettre sa valeur dans rel
                        *rel = OPERATEUR_unaire_evaluer(req->val, relationTestG);
                    } else {
                        //Sinon la requête est fausse
                        *err = true;
                    }
                }

            }
        } else if (req->d != NULL) {
            //Si il n'y a qu'un fils droit : requête fausse
            *err = true;
        } else {
            //Si il n'y a aucun fils, vérification du type de l'op
            if (req->val.op == op_relation) {
                //Si op est une relation, on l'évalue :
                *rel = OPERATEUR_relation_evaluer(req->val);
            } else {
                //Sinon la requête est fausse
                *err = true;
            }
        }
    }
}

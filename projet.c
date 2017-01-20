// Etudiant : Bastien Hoffstetter
// Enseignant : François Goasdoue

#include <stdio.h>
#include "REQUETE.h"

int main() {
    char *att_film[] = {"Titre", "Realisateur", "Acteur"};
    RELATION film = RELATION_creer("film", att_film, 3);
    char *tuple1[] = {"Star Wars: Episode 4", "Georges Lucas", "Harrison Ford"};
    RELATION_INSERTION(&film, tuple1);
    char *tuple2[] = {"Star Wars: Episode 5", "Georges Lucas", "Harrison Ford"};
    RELATION_INSERTION(&film, tuple2);
    char *tuple3[] = {"Star Wars: Episode 6", "Georges Lucas", "Harrison Ford"};
    RELATION_INSERTION(&film, tuple3);
    char *tuple4[] = {"THX 1138", "Georges Lucas", "Obert Duvall"};
    RELATION_INSERTION(&film, tuple4);
    char *tuple5[] = {"Working Girl", "Mike Nichols", "Sigourney Weaver"};
    RELATION_INSERTION(&film, tuple5);
    char *tuple6[] = {"Kingsman: The Secret Service", "Matthew Vaughn", "Colin Firth"};
    RELATION_INSERTION(&film, tuple6);
    char *tuple7[] = {"Milk", "Gus Van Sant", "Sean Penn"};
    RELATION_INSERTION(&film, tuple7);
    char *tuple8[] = {"She's So Lovely", "Nick Cassavetes", "Sean Penn"};
    RELATION_INSERTION(&film, tuple8);
    char *tuple9[] = {"The Beach", "Danny Boyle", "Leonardo DiCaprio"};
    RELATION_INSERTION(&film, tuple9);
    char *tuple10[] = {"Orphan", "Jaume Collet-Serra", "Vera Farmiga"};
    RELATION_INSERTION(&film, tuple10);
    RELATION_afficher(film);

    char *att_aime[] = {"Spectateur", "Titre"};
    RELATION aime = RELATION_creer("aime", att_aime, 2);
    char *tuple11[] = {"Martin Solveig", "Star Wars: Episode 6"};
    RELATION_INSERTION(&aime, tuple11);
    char *tuple12[] = {"Martin Solveig", "Star Wars: Episode 4"};
    RELATION_INSERTION(&aime, tuple12);
    char *tuple13[] = {"Cher", "Star Wars: Episode 4"};
    RELATION_INSERTION(&aime, tuple13);
    char *tuple14[] = {"Cher", "Kingsman: The Secret Service"};
    RELATION_INSERTION(&aime, tuple14);
    char *tuple15[] = {"John Travolta", "Star Wars: Episode 4"};
    RELATION_INSERTION(&aime, tuple15);
    char *tuple16[] = {"John Travolta", "Kingsman: The Secret Service"};
    RELATION_INSERTION(&aime, tuple16);
    char *tuple17[] = {"John Travolta", "THX 1138"};
    RELATION_INSERTION(&aime, tuple17);
    RELATION_afficher(aime);

    char *att_vu[] = {"Spectateur", "Titre"};
    RELATION vu = RELATION_creer("vu", att_vu, 2);
    char *tuple18[] = {"Martin Solveig", "Star Wars: Episode 6"};
    RELATION_INSERTION(&vu, tuple18);
    char *tuple19[] = {"Martin Solveig", "Star Wars: Episode 4"};
    RELATION_INSERTION(&vu, tuple19);
    char *tuple20[] = {"Cher", "Star Wars: Episode 4"};
    RELATION_INSERTION(&vu, tuple20);
    char *tuple21[] = {"Cher", "Kingsman: The Secret Service"};
    RELATION_INSERTION(&vu, tuple21);
    char *tuple22[] = {"Cher", "THX 1138"};
    RELATION_INSERTION(&vu, tuple22);
    char *tuple23[] = {"John Travolta", "Star Wars: Episode 4"};
    RELATION_INSERTION(&vu, tuple23);
    char *tuple24[] = {"John Travolta", "Kingsman: The Secret Service"};
    RELATION_INSERTION(&vu, tuple24);
    char *tuple25[] = {"John Travolta", "THX 1138"};
    RELATION_INSERTION(&vu, tuple25);
    RELATION_afficher(vu);

    /* Mettre vos tests ci-dessous */
    printf("***************TESTS***************");

    /* TEST OPÉRATEUR*/
    OPERATEUR operateur;
    printf("\nTests Opérateurs :\n");

    //Opérateur Relation
    printf("\nOpérateur RELATION : \n");
    operateur = OPERATEUR_relation_creer(film);
    OPERATEUR_afficher(operateur);

    //Opérateur Selection
    printf("\nOpérateur SELECTION : \n");
    char *selectionTest[] = {"", "Georges Lucas", ""};
    operateur = OPERATEUR_selection_creer(selectionTest, 3);
    OPERATEUR_afficher(operateur);


    //Opérateur Projection
    printf("\nOpérateur PROJECTION : \n");
    char *projectionTests[] = {"Titre", "Acteur"};
    operateur = OPERATEUR_projection_creer(projectionTests, 2);
    OPERATEUR_afficher(operateur);

    //Opérateur Renomage
    printf("\nOpérateur RENOMAGE : \n");
    char *ancienNomTest = "Spectateur";
    char *nouveauNomTest = "Client";
    operateur = OPERATEUR_renommage_creer(ancienNomTest, nouveauNomTest);
    OPERATEUR_afficher(operateur);

    //Opérateur Jointure
    printf("\nOpérateur JOINTURE : \n");

    operateur = OPERATEUR_jointure_creer();
    OPERATEUR_afficher(operateur);

    //Opérateur Union
    printf("\nOpérateur UNION : \n");
    operateur = OPERATEUR_union_creer();
    OPERATEUR_afficher(operateur);

    //Opérateur Intersection
    printf("\nOpérateur INTERSECTION : \n");
    operateur = OPERATEUR_intersection_creer();
    OPERATEUR_afficher(operateur);

    //Opérateur Difference
    printf("\nOpérateur DIFFERENCE : \n");
    operateur = OPERATEUR_difference_creer();
    OPERATEUR_afficher(operateur);
    printf("\n\nFin des tests Opérateurs\n");

    /* TEST ÉVALUATION */
    printf("\nTests Évaluation :\n");

    //Évaluation OPÉRATEURS UNAIRES :

    //Opérateur relation
    printf("\nÉvaluation Opérateur RELATION : \n");
    operateur = OPERATEUR_relation_creer(film);
    OPERATEUR_afficher(operateur);
    printf("\n");
    RELATION_afficher(OPERATEUR_relation_evaluer(operateur));

    //Opérateur sélection
    printf("\nÉvaluation Opérateur SELECTION : \n");
    operateur = OPERATEUR_selection_creer(selectionTest, 3);
    OPERATEUR_afficher(operateur);
    printf("\n");
    RELATION_afficher(OPERATEUR_unaire_evaluer(operateur, film));

    //Opérateur projection
    printf("\nÉvaluation Operateur PROJECTION : \n");
    operateur = OPERATEUR_projection_creer(projectionTests, 2);
    OPERATEUR_afficher(operateur);
    printf("\n");
    RELATION_afficher(OPERATEUR_unaire_evaluer(operateur, film));

    //Opérateur renomage
    printf("\nÉvaluation Operateur RENOMMAGE : \n");
    operateur = OPERATEUR_renommage_creer(ancienNomTest, nouveauNomTest);
    OPERATEUR_afficher(operateur);
    printf("\n");
    RELATION_afficher(OPERATEUR_unaire_evaluer(operateur, aime));

    //Évaluation OPÉRATEURS BINAIRES :

    //Opérateur jointure
    printf("\nÉvaluation Opérateur JOINTURE : \n");
    operateur = OPERATEUR_jointure_creer();
    OPERATEUR_afficher(operateur);
    printf("\n");
    RELATION_afficher(OPERATEUR_binaire_evaluer(operateur, film, vu));

    //Opérateur union
    printf("\nÉvaluation Opérateur UNION : \n");
    operateur = OPERATEUR_union_creer();
    OPERATEUR_afficher(operateur);
    printf("\n");
    RELATION_afficher(OPERATEUR_binaire_evaluer(operateur, vu, film));

    //Opérateur intersection
    printf("\nÉvaluation Opérateur INTERSECTION : \n");
    operateur = OPERATEUR_intersection_creer();
    OPERATEUR_afficher(operateur);
    printf("\n");
    RELATION_afficher(OPERATEUR_binaire_evaluer(operateur, vu, film));

    //Opérateur différence
    printf("\nÉvaluation Opérateur DIFFERENCE : \n");
    operateur = OPERATEUR_difference_creer();
    OPERATEUR_afficher(operateur);
    printf("\n");
    RELATION_afficher(OPERATEUR_binaire_evaluer(operateur, vu, aime));

    printf("\n\nFin des tests d'Évaluation\n");

    /* TEST REQUETE */
    printf("\nTests Requête :\n");

    //Creation d'une requête
    //Création des opérateurs :
    OPERATEUR opVu = OPERATEUR_relation_creer(vu);
    OPERATEUR opFilm = OPERATEUR_relation_creer(film);
    OPERATEUR opJointure = OPERATEUR_jointure_creer();
    char *selectionReqTests[] = {"", "Georges Lucas", "", ""};
    OPERATEUR opSelection = OPERATEUR_selection_creer(selectionReqTests, 4);
    char *projectionReqTests[] = {"Spectateur", "Titre"};
    OPERATEUR opProjection = OPERATEUR_projection_creer(projectionReqTests, 2);
    REQUETE requete = REQUETE_creer(opProjection,
                                    REQUETE_creer(opSelection,
                                                  REQUETE_creer(opJointure,
                                                                REQUETE_creer(opFilm, NULL, NULL),
                                                                REQUETE_creer(opVu, NULL, NULL)
                                                  ), NULL),
                                    NULL);
    REQUETE_afficher(requete);
    printf("\nÉvaluation : \n");
    RELATION_afficher(REQUETE_evaluer(requete));

    printf("\n\nFin des tests de requête\n");

    /* TEST VALIDATION */
    printf("\nTests validation :");

    //Opérateur relation :
    printf("\n\nValidation Relation : ");
    operateur = OPERATEUR_relation_creer(film);
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 1 (film) (Attendu : false) : %s",
           (OPERATEUR_unaire_valider(operateur, film) ? "true" : "false"));

    //Opérateur sélection :
    printf("\n\nValidation Sélection : ");
    operateur = OPERATEUR_selection_creer(selectionTest, 3);
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 2a (film) (Attendu : true) : %s",
           (OPERATEUR_unaire_valider(operateur, film) ? "true" : "false"));
    operateur = OPERATEUR_selection_creer(selectionReqTests, 4);
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 2b (film) (Attendu : false) : %s",
           (OPERATEUR_unaire_valider(operateur, film) ? "true" : "false"));

    //Opérateur projection :
    printf("\n\nValidation Projection : ");
    //projectionTests : Titre, Acteur
    operateur = OPERATEUR_projection_creer(projectionTests, 2);
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 3a (film) (Attendu : true) : %s",
           (OPERATEUR_unaire_valider(operateur, film) ? "true" : "false"));
    printf("\nRésultat 3b (vu) (Attendu : false) : %s", (OPERATEUR_unaire_valider(operateur, vu) ? "true" : "false"));
    printf("\nRésultat 3c (aime) (Attendu : false) : %s",
           (OPERATEUR_unaire_valider(operateur, aime) ? "true" : "false"));
    char *test[] = {"Spectateur"};
    operateur = OPERATEUR_projection_creer(test, 1);
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 3d (vu) (Attendu : true) : %s", (OPERATEUR_unaire_valider(operateur, vu) ? "true" : "false"));

    //Opérateur renomage :
    printf("\n\nValidation Renomage : ");
    operateur = OPERATEUR_renommage_creer(ancienNomTest, nouveauNomTest);
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 4a (vu) (Attendu : true) : %s", (OPERATEUR_unaire_valider(operateur, vu) ? "true" : "false"));
    printf("\nRésultat 4b (film) (Attendu : false) : %s",
           (OPERATEUR_unaire_valider(operateur, film) ? "true" : "false"));
    //Évaluation sur le renomage de vu -> déjà présent
    printf("\nRésultat 4c (RENOMAGE(vu)) (Attendu : false) : %s",
           (OPERATEUR_unaire_valider(operateur, (OPERATEUR_unaire_evaluer(operateur, vu))) ? "true" : "false"));

    //Opérateurs binaires
    printf("\n\nValidation Opérateurs binaires : ");
    operateur = OPERATEUR_union_creer();
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 5a (vu,aime) (Attendu : true) : %s",
           (OPERATEUR_binaire_valider(operateur, vu, aime) ? "true" : "false"));
    printf("\nRésultat 5b (film,vu) (Attendu : false) : %s",
           (OPERATEUR_binaire_valider(operateur, film, vu) ? "true" : "false"));
    operateur = OPERATEUR_intersection_creer();
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 5c (vu,aime) (Attendu : true) : %s",
           (OPERATEUR_binaire_valider(operateur, vu, aime) ? "true" : "false"));
    operateur = OPERATEUR_difference_creer();
    printf("\n\n");
    OPERATEUR_afficher(operateur);
    printf("\nRésultat 5d (vu,aime) (Attendu : true) : %s",
           (OPERATEUR_binaire_valider(operateur, vu, aime) ? "true" : "false"));
    printf("\n\nFin des tests de validation");

    /* TEST VALIDATION REQUETE */
    printf("\n\nTests validation requête : \n");

    RELATION rel;
    bool err = false;
    printf("\n");
    REQUETE_afficher(requete);

    REQUETE_verifeval(requete, &rel, &err);

    printf("\n");
    printf("\nRésultat 1 (Attendu : false) : %s", err ? "true" : "false");
    printf("\n");
    RELATION_afficher(rel);

    //Création de requêtes incorrectes
    char * selectionReqFaux[] = {"", "Georges Lucas", "", "", ""};
    OPERATEUR opSelFaux = OPERATEUR_selection_creer(selectionReqFaux, 5);

    REQUETE requeteFausse = REQUETE_creer(opProjection,
                                          REQUETE_creer(opSelection, NULL,
                                                        REQUETE_creer(opJointure,
                                                                      REQUETE_creer(opFilm, NULL, NULL),
                                                                      REQUETE_creer(opVu, NULL, NULL)
                                                        )
                                          ), NULL);

    printf("\n");
    REQUETE_afficher(requeteFausse);
    REQUETE_verifeval(requeteFausse, &rel, &err);
    printf("\nRésultat 2 (Attendu : true) : %s", err ? "true" : "false");

    requeteFausse = REQUETE_creer(opSelection,
                                  REQUETE_creer(opProjection, NULL,
                                                REQUETE_creer(opJointure,
                                                              REQUETE_creer(opFilm, NULL, NULL),
                                                              REQUETE_creer(opVu, NULL, NULL)
                                                )
                                  ), NULL);
    printf("\n");
    REQUETE_afficher(requeteFausse);
    REQUETE_verifeval(requeteFausse, &rel, &err);
    printf("\nRésultat 3 (Attendu : true) : %s", err ? "true" : "false");

    requeteFausse = REQUETE_creer(opProjection,
                                  REQUETE_creer(opSelFaux,
                                                REQUETE_creer(opJointure,
                                                              REQUETE_creer(opFilm, NULL, NULL),
                                                              REQUETE_creer(opVu, NULL, NULL)
                                                ), NULL),
                                  NULL);
    printf("\n");
    REQUETE_afficher(requeteFausse);
    REQUETE_verifeval(requeteFausse, &rel, &err);
    printf("\nRésultat 4 (Attendu : true) : %s", err ? "true" : "false");

    printf("\n\nFin des Tests\n\n");

    return 0;
}

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
    /* OPERATEUR TEST */
    OPERATEUR operateur;
    printf("\nOperateur tests\n\n");

    //Operateur Relation
    printf("Operateur RELATION : \n");
    operateur = OPERATEUR_relation_creer(film);
    OPERATEUR_afficher(operateur);

    //Operateur Selection
    printf("\nOperateur SELECTION : \n");
    char *selectionTest[] = {"", "Georges Lucas", ""};
    operateur = OPERATEUR_selection_creer(selectionTest, 3);
    OPERATEUR_afficher(operateur);


    //Operateur Projection
    printf("\nOperateur PROJECTION : \n");
    char *projectionTests[] = {"Spectateur", "Titre"};
    operateur = OPERATEUR_projection_creer(projectionTests, 2);
    OPERATEUR_afficher(operateur);

    //Operateur Renomage
    printf("\nOperateur RENOMAGE : \n");
    char *ancienNomTest = "Cher";
    char *nouveauNomTest = "Pas cher";
    operateur = OPERATEUR_renommage_creer(ancienNomTest, nouveauNomTest);
    OPERATEUR_afficher(operateur);

    //Operateur Jointure
    printf("\nOperateur JOINTURE : \n");
    operateur = OPERATEUR_jointure_creer();
    OPERATEUR_afficher(operateur);

    //Operateur Union
    printf("\nOperateur UNION : \n");
    operateur = OPERATEUR_union_creer();
    OPERATEUR_afficher(operateur);

    //Operateur Intersection
    printf("\nOperateur INTERSECTION : \n");
    operateur = OPERATEUR_intersection_creer();
    OPERATEUR_afficher(operateur);

    //Operateur Difference
    printf("\nOperateur DIFFERENCE : \n");
    operateur = OPERATEUR_difference_creer();
    OPERATEUR_afficher(operateur);
    printf("\n\nFin Operateurs test\n");

    return 0;
}

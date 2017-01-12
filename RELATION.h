// CE FICHIER NE DOIT PAS ETRE MODIFIE

/*
  Enregistrement RELATION
  Contient :
  - t : un tableau dynamique a 2 dimensions de chaines de caracteres
  - lignes : le nombre de lignes de t
             les attributs de la relation sont en ligne 0 de t
  - colonnes : le nombre de colonnes de t 
*/
typedef struct {
  char * * * t;
  char * nom;
  int lignes;
  int colonnes;
} RELATION;

// creation de relation vide a partir de
/* 
   - char * : son nom 
   - char * [] : ses attributs
   - int : son arite (= nombre d'attributs)
*/
RELATION RELATION_creer(char *, char * [], int);

// affichage de relation (vide ou non)
void RELATION_afficher(RELATION);

// schema de relation (tableau des attributs)
char * * RELATION_schema(RELATION);

// arite de relation (nombre d'attributs/colonnes)
int RELATION_arite(RELATION);

// insertion d'un tuple (char * []) dans une relation passee par adresse
void RELATION_INSERTION(RELATION *, char * []);

// operateurs de l'algebre relationnelle
// selection des tuples d'une relation selon un tuple de valeur de selection (char * [])
RELATION RELATION_SELECTION(RELATION, char * []);
// projection des tuples d'une relation selon les attributs pertinents (char * []) et leur nombre (int)
RELATION RELATION_PROJECTION(RELATION, char * [], int);
// renommage d'un attribut (1er char *) d'une relation par un nouveau nom d'attribut (2nd char*)
RELATION RELATION_RENOMMAGE(RELATION, char *, char *);
// jointure de relations
RELATION RELATION_JOINTURE(RELATION,RELATION);
// union de relations
RELATION RELATION_UNION(RELATION,RELATION);
// intersection de relations
RELATION RELATION_INTERSECTION(RELATION,RELATION);
// difference de relations
RELATION RELATION_DIFFERENCE(RELATION,RELATION);

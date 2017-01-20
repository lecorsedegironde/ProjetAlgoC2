all: program note

program:
	gcc -Wall -o projet ELT.c OPERATEUR.c REQUETE.c projet.c ARBRE.o RELATION.o

note:
	gcc -Wall -o note OPERATEUR.c ELT.c ARBRE.o RELATION.o REQUETE.c note.o




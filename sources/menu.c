#include "../headers/colors.h"
#include "../headers/compatibility.h"
#include "../headers/fact_basis.h"
#include "../headers/inference_motor.h"
#include "../headers/knowledge_basis.h"
#include "../headers/menu.h"
#include "../headers/rules.h"

long entry_num() {
	char entry[MAX_LENGTH];
	// get a user entry & return 0 if NaN
	fgets(entry, MAX_LENGTH+1, stdin);
	return strtol(entry, NULL, 10);
}

/*---------------------------------------------------------*/

char* entry_char() {
	char entry[MAX_LENGTH];

	// get entry from user:
	fgets(entry, MAX_LENGTH+1, stdin);
	// remove \n char
	entry[strlen(entry) - 1] = 0;

	// adjust size to the string itself
	char* result = (char*)malloc(strlen(entry)+1);
	strcpy(result, entry);

	return result;
}

/*---------------------------------------------------------*/

void header() {
	printf(YELLOW(".o. .o.")CYAN("    ooooo     ooo oooooo     oooo             ")YELLOW(".o. .o.")"\n");
	printf(YELLOW("888 888")CYAN("    `888'     `8'  `888.     .8'              ")YELLOW("888 888")"\n");
	printf(YELLOW("888 888")CYAN("     888       8    `888.   .8'    .oooo.o    ")YELLOW("888 888")"\n");
	printf(YELLOW("Y8P Y8P")CYAN("     888       8     `888. .8'    d88(  '8    ")YELLOW("Y8P Y8P")"\n");
	printf(YELLOW("`8' `8'")CYAN("     888       8      `888.8'     `'Y88b.     ")YELLOW("`8' `8'")"\n");
	printf(YELLOW(".o. .o.")CYAN("     `88.    .8'       `888'      o.  )88b    ")YELLOW(".o. .o.")"\n");
	printf(YELLOW("Y8P Y8P")CYAN("       `YbodP\"          `8'       8\"\"888P\"    ")YELLOW("Y8P Y8P")"\n\n");
	printf("             Système expert "RED("--")" Recherche d'UVs!\n\n");
}

/*---------------------------------------------------------*/

void menu(BC knowledge_basis){
	long int numeric;

	printf("\n");
	printf(BLUE("1.")" Rechercher une UV\n");
  printf(BLUE("2.")" Accéder à la liste complète des UVs\n");
  printf(BLUE("3.")" Supprimer la base de connaissance\n");
  printf(BLUE("4.")" Ajouter une règle à la base de connaissance\n");
  printf(BLUE("5.")" Quitter le programme\n\n");
  do {
		printf(MAGENTA("Votre choix : "));
		numeric = entry_num();
  } while (numeric > 5 || numeric < 1);

  switch(numeric){
    case 1 :
			/*
			 * RECHERCHE D'UVs
			*/
			CLEAR;
			header();

      BF fact_basis = createFactBasis();

			// On évite toute intéraction si la bc est vide : on ne cherche pas dans du "vide"
			if (isEmptyKnowledgeBasis(knowledge_basis)) {
				printf(RED("La base de connaissance est vide!\n"));
				menu(knowledge_basis);
				break;
			}
      
			printf("Quel est le type de l'UV ?\n");
			printf(BLUE("1.")" CS\n");
      printf(BLUE("2.")" TM\n");
			printf(BLUE("3.")" EC\n");
			printf(BLUE("4.")" QC\n");
			printf(BLUE("5.")" OM\n\n");

			do {
				printf(MAGENTA("Tapez votre nombre de 1 a 5 pour choisir : "));
				numeric = entry_num();
			} while (numeric > 5 || numeric < 1);

      switch(numeric){
        case 1 : 
          fact_basis = addFactFactBasis(fact_basis, "CS");
          break;
        case 2 : 
          fact_basis = addFactFactBasis(fact_basis, "TM");
          break;
        case 3 : 
          fact_basis = addFactFactBasis(fact_basis, "EC");
          break;
        case 4 : 
          fact_basis = addFactFactBasis(fact_basis, "QC");
          break;
        case 5 : 
          fact_basis = addFactFactBasis(fact_basis, "OM");
          break;
      }

			// Lecture de la matière:
      printf(MAGENTA("Matière : "));
      fact_basis = addFactFactBasis(fact_basis, entry_char());

			// Lecture du theme:
      printf(MAGENTA("Thème : "));
      fact_basis = addFactFactBasis(fact_basis, entry_char());

      printf(MAGENTA("Quand l'UV est-elle disponible ?\n"));
      printf(BLUE("1.")" Automne\n");
      printf(BLUE("2.")" Printemps\n");
      printf(BLUE("3.")" Les deux\n");

			do {
	      printf(MAGENTA("Tapez votre nombre de 1 à 3 pour choisir : "));
				numeric = entry_num();
			} while (numeric > 3 || numeric < 1);

      switch(numeric){
        case 1 :
          fact_basis = addFactFactBasis(fact_basis, "Automne");
        break;
        case 2 : 
          fact_basis = addFactFactBasis(fact_basis, "Printemps");
        break;
        case 3 :
          fact_basis = addFactFactBasis(fact_basis, "Les deux");
      }

      inference_motor(knowledge_basis, fact_basis);
			menu(knowledge_basis);
      break;
    case 2 :
			/*
			 * AFFICHAGE DE LA BASE DE CONNAISSANCE
			*/
			CLEAR;
			header();
      printf(GREEN("Voici la liste des UV et leurs caractéristiques\n\n"));
      displayKnowledgeBasis(knowledge_basis);
			menu(knowledge_basis);
      break;
    case 3 :
			/*
			 * SUPPRESSION DE LA BASE DE CONNAISSANCE
			*/
			CLEAR;
			header();
      deleteKnowledgeBasis(knowledge_basis);
			menu(knowledge_basis);
      break;
    case 4 : 
			/*
			 * AJOUT D'UNE REGLE A DE LA BASE DE CONNAISSANCE
			*/
      CLEAR;
			header();

			// Création de la nouvelle règle
      Regle ajoutRegle = createRule();

      printf(GREEN("Ajout d'une règle à la base de connaissance\n\n"));
      printf("Quel est le type d'UV ?\n");
			printf(BLUE("1.")" CS\n");
      printf(BLUE("2.")" TM\n");
			printf(BLUE("3.")" EC\n");
			printf(BLUE("4.")" QC\n");
			printf(BLUE("5.")" OM\n");

      do {
	      printf(MAGENTA("Tapez votre nombre de 1 à 5 pour choisir : "));
				numeric = entry_num();
			} while (numeric > 5 || numeric < 1);

      switch(numeric){
        case 1 : 
          ajoutRegle = addProposition(ajoutRegle, "CS");
          break;
        case 2 : 
          ajoutRegle = addProposition(ajoutRegle, "TM");
          break;
        case 3 : 
          ajoutRegle = addProposition(ajoutRegle, "EC");
          break;
        case 4 : 
          ajoutRegle = addProposition(ajoutRegle, "QC");
          break;
        case 5 : 
          ajoutRegle = addProposition(ajoutRegle, "OM");
          break;
      }

			// Ajout de la matière
      printf(MAGENTA("Matière : "));
      ajoutRegle = addProposition(ajoutRegle, entry_char());

			// Ajout du thème
      printf(MAGENTA("Thème : "));
      ajoutRegle = addProposition(ajoutRegle, entry_char());

      printf("A Quel semestre ?\n");
      printf(BLUE("1.")" Automne\n");
      printf(BLUE("2.")" Printemps\n");
      printf(BLUE("3.")" Les deux\n");

      do {
	      printf(MAGENTA("Tapez votre nombre de 1 à 3 pour choisir : "));
				numeric = entry_num();
			} while (numeric > 3 || numeric < 1);

      switch(numeric){
        case 1 :
          ajoutRegle = addProposition(ajoutRegle, "Automne");
        break;
        case 2 : 
          ajoutRegle = addProposition(ajoutRegle, "Printemps");
        break;
        case 3 :
          ajoutRegle = addProposition(ajoutRegle, "Les deux");
      }

			// Ajout de la conclusion
      printf(MAGENTA("Quelle est le nom de l'uv : "));
      ajoutRegle = createConclusion(ajoutRegle, entry_char());
      knowledge_basis = addRuleBasis(knowledge_basis, ajoutRegle);

      menu(knowledge_basis);
      break;
    case 5 :
			/*
			 * FERMER LE PROGRAMME
			*/
			CLEAR;
			header();
			printf("Au revoir et à bientôt!\n");
      exit(0);
      break;
  }
}
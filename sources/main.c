#include "../headers/rules.h"
#include "../headers/knowledge_basis.h"
#include "../headers/fact_basis.h"
#include "../headers/compatibility.h"

/********************************
 * @brief fonction d'affichage du menu
 * 
 * @param knowledge_basis base de connaissance du guide des UV
 * @param fact_basis base de fait de l'utilisateur
 * @return pas de return
 */
void menu(BC knowledge_basis, BF fact_basis);

int main(void){
	// Utilisé pour l'interprétation des accents, etc.. sous windows
	ASCII;

	Regle Regle1 = createRule();
	Regle1 = addProposition(Regle1, "CS");
	Regle1 = addProposition(Regle1, "Mathematiques");
	Regle1 = addProposition(Regle1, "Statistiques");
	Regle1 = addProposition(Regle1, "Primtemps uniquement");
	Regle1 = createConclusion(Regle1, "SQ20");

	Regle Regle2 = createRule();
	Regle2 = addProposition(Regle2, "CS");
	Regle2 = addProposition(Regle2, "Informatique");
	Regle2 = addProposition(Regle2, "Algorithmie");
	Regle2 = addProposition(Regle2, "Automne uniquement");
	Regle2 = createConclusion(Regle2, "LO21");

	Regle Regle3 = createRule();
	Regle3 = addProposition(Regle3, "TM");
	Regle3 = addProposition(Regle3, "Informatique");
	Regle3 = addProposition(Regle3, "Systeme Linux");
	Regle3 = addProposition(Regle3, "Printemps uniquement");
	Regle3 = createConclusion(Regle3, "LP25");

	Regle Regle4 = createRule();
	Regle4 = addProposition(Regle4, "EC");
	Regle4 = addProposition(Regle4, "Russe");
	Regle4 = addProposition(Regle4, "Niveau 0");
	Regle4 = addProposition(Regle4, "Tout semestre");
	Regle4 = createConclusion(Regle4, "LR00");

	Regle Regle5 = createRule();
	Regle5 = addProposition(Regle5, "QC");
	Regle5 = addProposition(Regle5, "Histoire");
	Regle5 = addProposition(Regle5, "Theme des sciences");
	Regle5 = addProposition(Regle5, "Tout semestre");
	Regle5 = createConclusion(Regle5, "HE09");

	Regle Regle6 = createRule();
	Regle6 = addProposition(Regle6, "OM");
	Regle6 = addProposition(Regle6, "Gestion");
	Regle6 = addProposition(Regle6, "Thème des finances et des investissements");
	Regle6 = addProposition(Regle6, "Automne uniquement");
	Regle6 = createConclusion(Regle6, "GE07");

	//Création de la base de connaissance
	BC knowledge_basis = createBasis();
	knowledge_basis = addRuleBasis(knowledge_basis, Regle1);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle2);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle3);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle4);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle5);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle6);

	BF fact_basis = createFactBasis();

	CLEAR;
	
	printf(".o. .o.    ooooo     ooo oooooo     oooo             .o. .o.\n");
	printf("888 888    `888'     `8'  `888.     .8'              888 888\n");
	printf("888 888     888       8    `888.   .8'    .oooo.o    888 888\n");
	printf("Y8P Y8P     888       8     `888. .8'    d88(  '8    Y8P Y8P\n");
	printf("`8' `8'     888       8      `888.8'     `'Y88b.     `8' `8'\n");
	printf(".o. .o.     `88.    .8'       `888'      o.  )88b    .o. .o.\n");
	printf("Y8P Y8P       `YbodP\"          `8'       8\"\"888P\"    Y8P Y8P\n\n");
	printf("             Système expert -- Recherche d'UVs!      \n\n");

  printf("Bienvenue, que souhaitez-vous faire ?\n");
	menu(knowledge_basis, fact_basis);
  
	return 0;
}

void menu(BC knowledge_basis, BF fact_basis){
	int choix = 0;
	BC test = createBasis();

	printf("\n");
	printf("1. Rechercher une UV\n");
  printf("2. Accéder à la liste complète des UVs\n");
  printf("3. Réinitialiser le système\n");
  printf("4. Ajouter une règle à la base de connaissance\n");
  printf("5. Quitter le programme\n\n");
  printf("Votre choix : ");

  do {
  	scanf("%d", &choix);
  } while (choix > 5 || choix < 1);

  switch(choix){
    case 1 :
			CLEAR;
      printf("Quel est le type d'UV ?\n");
			printf("L'UV est : 1. CS\n");
      printf("           2. TM\n");
			printf("           3. EC\n");
			printf("           4. QC\n");
			printf("           5. OM\n");
      printf("Tapez votre nombre de 1 à 5 pour choisir : ");

      int type = 0;
      do {
        scanf("%d", &type);
      }while(type > 5 || type < 1);

      switch(type){
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

      printf("Quelle est la matière abordée ?\n");
      char matiere[15];
      scanf("%s", matiere);
      char* ptr = matiere;
      fact_basis = addFactFactBasis(fact_basis, ptr);

      printf("Quelle est le theme abordé ?\n");
      char theme[15];
      scanf("%s", theme);
      char* ptr2 = theme;
      fact_basis = addFactFactBasis(fact_basis, ptr2);

      printf("Quand l'UV est-elle disponible ?\n");
      printf("1. Automne uniquement\n");
      printf("2. Printemps uniquement\n");
      printf("3. Tout semestre\n");
      printf("Tapez votre nombre de 1 à 3 pour choisir : ");

      int semestre = 0;
      do{
        scanf("%d", &semestre);
      }while(semestre < 1 || semestre > 3);

      switch(semestre){
        case 1 :
          fact_basis = addFactFactBasis(fact_basis, "Automne uniquement");
        break;
        case 2 : 
          fact_basis = addFactFactBasis(fact_basis, "Printemps uniquement");
        break;
        case 3 :
          fact_basis = addFactFactBasis(fact_basis, "Tout semestre");
      }

      inference_motor(knowledge_basis, fact_basis);
			menu(knowledge_basis, fact_basis);
      break;
    case 2 :
			CLEAR;
      printf("Voici la liste des UV et de leur caractéristiques : \n\n");
      displayKnowledgeBasis(knowledge_basis);
			menu(knowledge_basis, fact_basis);
      break;
    case 3 :
			CLEAR;
      deleteFactBasis(fact_basis);
      deleteKnowledgeBasis(knowledge_basis);
			menu(knowledge_basis, fact_basis);
      break;
    case 4 : 
      CLEAR;

      Regle ajoutRegle = createRule();

      printf("Ajout d'une règle à la base de connaissance...");
      printf("Quel est le type d'UV ?\n");
			printf("L'UV est : 1. CS\n");
      printf("           2. TM\n");
			printf("           3. EC\n");
			printf("           4. QC\n");
			printf("           5. OM\n");
      printf("Tapez votre nombre de 1 à 5 pour choisir : ");

      int addType = 0;
      do {
        scanf("%d", &addType);
      }while(addType > 5 || addType < 1);

      switch(addType){
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

      printf("Quelle est la matière abordée ?\n");
      char addMatter[15];
      scanf("%s", addMatter);
      char* addPtr = addMatter;
      ajoutRegle = addProposition(ajoutRegle, addPtr);

      printf("Quelle est le theme abordé ?\n");
      char addTheme[15];
      scanf("%s", addTheme);
      char* addPtr2 = addTheme;
      ajoutRegle = addProposition(ajoutRegle, addPtr2);

      printf("Quand l'UV est-elle disponible ?\n");
      printf("1. Automne uniquement\n");
      printf("2. Printemps uniquement\n");
      printf("3. Tout semestre\n");
      printf("Tapez votre nombre de 1 à 3 pour choisir : ");

      int addSemestre = 0;
      do{
        scanf("%d", &addSemestre);
      }while(addSemestre < 1 || addSemestre > 3);

      switch(addSemestre){
        case 1 :
          ajoutRegle = addProposition(ajoutRegle, "Automne uniquement");
        break;
        case 2 : 
          ajoutRegle = addProposition(ajoutRegle, "Printemps uniquement");
        break;
        case 3 :
          ajoutRegle = addProposition(ajoutRegle, "Tout semestre");
      }

      printf("Quelle est la conclusion ?\n");
      char conclusion[15];
      scanf("%s", conclusion);
      char* ptr3 = conclusion;
      ajoutRegle = createConclusion(ajoutRegle, ptr3);

      knowledge_basis = addRuleBasis(knowledge_basis, ajoutRegle);

      break;
    case 5 :
      exit(0);
      break;
  }
}

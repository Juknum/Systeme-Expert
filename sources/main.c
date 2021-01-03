#include "../headers/rules.h"
#include "../headers/knowledge_basis.h"
#include "../headers/fact_basis.h"
#include "../headers/compatibility.h"

/********************************
 * @brief fonction d'affichage du menu
 * 
 * @param aucun
 * @return pas de return
 */
void menu(BC knowledge_basis, BF fact_basis);

int main(void){
	// Utilisé pour l'interprétation des accents, etc.. sous windows
	ASCII;

	Regle Regle1 = createRule();
	Regle1 = addProposition(Regle1, "CS");
	Regle1 = addProposition(Regle1, "Mathématiques");
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
	fact_basis = addFactFactBasis(fact_basis, "SQ20 est en Printemps uniquement");
	fact_basis = addFactFactBasis(fact_basis, "LP25 est en Printemps uniquement");
	fact_basis = addFactFactBasis(fact_basis, "LO21 est en Automne uniquement");
	fact_basis = addFactFactBasis(fact_basis, "GE07 est en Automne uniquement");
	fact_basis = addFactFactBasis(fact_basis, "LR00 est en Automne et en Printemps");
	fact_basis = addFactFactBasis(fact_basis, "HE09 est en Automne et en Printemps");	

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
	printf("3. Accéder à la base de fait\n");
  printf("4. Réinitialiser le système\n");
	printf("5. Ajouter des informations\n");
  printf("6. Quitter le programme\n\n");
  printf("Votre choix : ");

  do {
  	scanf("%d", &choix);
  } while (choix > 6 || choix < 1);

  switch(choix){
    case 1 :
			CLEAR;
			printf("Not done yet\n");
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
			printf("Voici la base de fait:\n");
			displayFactBasis(fact_basis);
			menu(knowledge_basis, fact_basis);
			break;
    case 4 :
			CLEAR;
      deleteFactBasis(fact_basis);
      deleteKnowledgeBasis(knowledge_basis);
			menu(knowledge_basis, fact_basis);
      break;
		case 5 :
			CLEAR;
			printf("Not done yet\n");
			menu(knowledge_basis, fact_basis);
			break;
    case 6 :
      exit(0);
      break;
  }
}
#include "../headers/rules.h"
#include "../headers/knowledge_basis.h"
#include "../headers/fact_basis.h"

int main(void){

	system("chcp 65001");
	printf("ICI\n");

	//Création des règles

	Regle Regle1 = createRule();
	Regle1 = addProposition(Regle1, "CS");
	Regle1 = addProposition(Regle1, "Mathématiques");
  Regle1 = addProposition(Regle1, "Statistiques");
	Regle1 = addProposition(Regle1, "Primtemps Uniquement");
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
	printf("ICI");

	BC knowledge_basis = createBasis();
	knowledge_basis = addRuleBasis(knowledge_basis, Regle1);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle2);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle3);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle4);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle5);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle6);

	printf("OU LA BAS");

  //Création de la base de fait 

  BF fact_basis = createFactBasis();

  /////////////////////////////////////////////////////
  ////////////////INTERFACE////////////////////////////

  printf("*******************************************\n");
  printf("******Système expert : Recherche d'UV******\n");
  printf("*******************************************\n");

  printf("Bienvenue, que souhaitez-vous faire ?\n");
  printf("1. Rechercher une UV\n");
  printf("2. Acceder à la liste complète des UV\n");
  printf("3. Réinitialiser le système\n");
  printf("4. Quitter le logiciel\n");
  printf("Votre choix : ");

  int choix = 0;

  do {
  	scanf("%d", &choix);
  } while (choix > 4 || choix < 1);

  switch(choix){
    case 1 :
			printf("Not done yet");
      break;
    case 2 :
			printf("Not done yet");
      printf("Voici la liste des UV et de leur caractéristiques : \n");
      displayKnowledgeBasis(knowledge_basis);
      break;
    case 3 :
      deleteFactBasis(fact_basis);
      deleteKnowledgeBasis(knowledge_basis);
      printf("Données supprimmées");
      break;
    case 4 :
      exit(0);
      break;
  }
	
	return 0;
}
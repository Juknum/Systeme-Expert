#include "../headers/rules.h"
#include "../headers/knowledge_basis.h"
#include "../headers/fact_basis.h"
#include "../headers/compatibility.h"
#include "../headers/inference_motor.h"

#include "../headers/colors.h"
#include "../headers/menu.h"

int main(void){
	// Utilisé pour l'interprétation des accents, etc.. sous windows
	ASCII;

	// Création des règles et de leurs prémisses & conclusion
	Regle Regle1 = createRule();
	Regle1 = addProposition(Regle1, "CS");
	Regle1 = addProposition(Regle1, "Mathematiques");
	Regle1 = addProposition(Regle1, "Statistiques");
	Regle1 = addProposition(Regle1, "Printemps");
	Regle1 = createConclusion(Regle1, "SQ20");

	Regle Regle2 = createRule();
	Regle2 = addProposition(Regle2, "CS");
	Regle2 = addProposition(Regle2, "Informatique");
	Regle2 = addProposition(Regle2, "Algorithmie");
	Regle2 = addProposition(Regle2, "Automne");
	Regle2 = createConclusion(Regle2, "LO21");

	Regle Regle3 = createRule();
	Regle3 = addProposition(Regle3, "TM");
	Regle3 = addProposition(Regle3, "Informatique");
	Regle3 = addProposition(Regle3, "Systeme Linux");
	Regle3 = addProposition(Regle3, "Printemps");
	Regle3 = createConclusion(Regle3, "LP25");

	Regle Regle4 = createRule();
	Regle4 = addProposition(Regle4, "EC");
	Regle4 = addProposition(Regle4, "Russe");
	Regle4 = addProposition(Regle4, "Niveau 0");
	Regle4 = addProposition(Regle4, "Les deux");
	Regle4 = createConclusion(Regle4, "LR00");

	Regle Regle5 = createRule();
	Regle5 = addProposition(Regle5, "QC");
	Regle5 = addProposition(Regle5, "Histoire");
	Regle5 = addProposition(Regle5, "Theme des sciences");
	Regle5 = addProposition(Regle5, "Les deux");
	Regle5 = createConclusion(Regle5, "HE09");

	Regle Regle6 = createRule();
	Regle6 = addProposition(Regle6, "OM");
	Regle6 = addProposition(Regle6, "Gestion");
	Regle6 = addProposition(Regle6, "Thème des finances et des investissements");
	Regle6 = addProposition(Regle6, "Automne");
	Regle6 = createConclusion(Regle6, "GE07");

  Regle Regle7 = createRule();
  Regle7 = addProposition(Regle7, "TM");
	Regle7 = addProposition(Regle7, "Informatique");
	Regle7 = addProposition(Regle7, "VBA");
	Regle7 = addProposition(Regle7, "Automne");
	Regle7 = createConclusion(Regle7, "IFA");


	// Création de la base de connaissance & ajout des règles dedans
	BC knowledge_basis = createBasis();
	knowledge_basis = addRuleBasis(knowledge_basis, Regle1);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle2);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle3);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle4);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle5);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle6);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle7);

	// Mettre sous commentaire pour laisser les informations du compilateurs <!>
	CLEAR;
	
	header();
	printf("Bienvenue, que souhaitez-vous faire ?\n");
	menu(knowledge_basis);
  
	return 0;
}
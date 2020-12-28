#include "rules.h"
#include "knowledge_basis.h"
#include "fact_basis.h"

int main(){

	//Création des règles

	Regle Regle1 = createRule();
	Regle1 = addProposition(Regle1, "CS");
	Regle1 = addProposition(Regle1, "Mathématique");
	Regle1 = addProposition(Regle1, "Primtemps Uniquement");
	Regle1 = createConclusion(Regle1, "SQ20");

	Regle Regle2 = createRule();
	Regle2 = addProposition(Regle2, "CS");
	Regle2 = addProposition(Regle2, "Algorithmie");
	Regle2 = addProposition(Regle2, "Automne uniquement");
	Regle2 = createConclusion(Regle2, "LO21");

	Regle Regle3 = createRule();
	Regle3 = addProposition(Regle3, "TM");
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
}
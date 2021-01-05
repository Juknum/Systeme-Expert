#include "../headers/knowledge_basis.h"
#include "../headers/colors.h"

/*------------------------------------*/

BC createBasis(){
	BC new = (BC)malloc(sizeof(ElemBC));
	new->head.premisse = NULL;
	new->next = NULL;
	return new;
}

/*------------------------------------*/

BC addRuleBasis(BC knowledge_basis, Regle r){
	if (knowledge_basis == NULL){
		knowledge_basis->head = r;
		knowledge_basis->next = NULL;
	}
	else {
		BC buffer = knowledge_basis;
		
		while(buffer->next != NULL){
			buffer = buffer->next;
		}

		BC new = (BC)malloc(sizeof(ElemBC));
		new->head = r;
		new->next = NULL;
		buffer->next = new;
	}
	return knowledge_basis;
}

/*------------------------------------*/

Regle headValueBasis(BC knowledge_basis){
	return knowledge_basis->head;
}
 
/*------------------------------------*/

bool isEmptyKnowledgeBasis(BC knowledge_basis){
	if(knowledge_basis->next == NULL) return true;
	return false;
}

/*------------------------------------*/

void displayKnowledgeBasis(BC knowledge_basis){
	if(isEmptyKnowledgeBasis(knowledge_basis)){
		printf(RED("Base de connaissance vide\n"));
	}
	else{
		BC buffer = knowledge_basis;
		buffer = buffer->next;
		printf(BLUE("----------------- BASE DE CONNAISSANCE ----------------\n\n"));
		while(buffer != NULL){
			displayRule(headValueBasis(buffer));
			buffer = buffer->next;
		}
		printf(BLUE("-------------------------------------------------------\n\n"));
	}
}

/*------------------------------------*/

void deleteKnowledgeBasis(BC knowledge_basis){

	if(isEmptyKnowledgeBasis(knowledge_basis)){
		printf(RED("Base de connaissance déjà vide\n"));
	}
	else{
		BC buffer = knowledge_basis;
		while(buffer->next != NULL){
				buffer->head.conclusion = NULL;
			while(buffer->head.premisse != NULL){
				free(buffer->head.premisse->content);
				buffer->head.premisse = buffer->head.premisse->next;
			}
			buffer = buffer->next;
			}

		knowledge_basis->next = NULL;
		printf(GREEN("Base de connaissance supprimée\n"));
	}
}
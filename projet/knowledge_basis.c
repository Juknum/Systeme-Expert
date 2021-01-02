#include "../headers/knowledge_basis.h"

/*------------------------------------*/

BC createBasis(){
	BC new = (BC)malloc(sizeof(ElemBC));
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
		buffer->next = new;
	}
	return knowledge_basis;
 }

 /*------------------------------------*/

 Regle headValueBasis(BC knowledge_basis){
	return knowledge_basis->head;
 }
 
 /*------------------------------------*/

 Bool isEmptyKnowledgeBasis(BC knowledge_basis){
	 if(knowledge_basis == NULL)return true;
	 return false;
 }

 void displayKnowledgeBasis(BC knowledge_basis){
	if(isEmptyKnowledgeBasis(knowledge_basis)){
		printf("***Base de connaissance vide***");
	}
	else{
		BC buffer = knowledge_basis;
		printf("***Voici la base de connaissance***");
		while(buffer != NULL){
			displayRule(headValueBasis(buffer));
			buffer = buffer->next;
		}
		printf("***Fin de la base de connaissance***");
	}
}
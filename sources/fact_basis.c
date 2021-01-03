#include "../headers/fact_basis.h"

BF createFactBasis(){
	BF fact_basis = NULL;
	return fact_basis;
}

bool isEmptyFactBasis(BF fact_basis){
	if(fact_basis == NULL) return true;
	return false;
}

void displayFactBasis(BF fact_basis){
	if(isEmptyFactBasis(fact_basis)){
		printf("*** Base de fait vide ***\n");
	}
	else{
		BF buffer = fact_basis;
		printf("*** Début de la base de fait ***\n\n");
		while(buffer != NULL){
			printf("- %s\n", buffer->content);
			buffer = buffer->next;
		}
		printf("\n*** Fin de la base de fait ***\n");
	}
}

BF addFactFactBasis(BF fact_basis, char* content){
	if(isEmptyFactBasis(fact_basis)){
		fact_basis = (BF)malloc(sizeof(Proposition));
		fact_basis->content = malloc(strlen(content));
		strcpy(fact_basis->content, content);
	}
	else{
		BF buffer = fact_basis;
		while(isEmptyFactBasis(buffer->next) == false){
			buffer = buffer->next;
		}
		BF ajout = (BF)malloc(sizeof(Proposition));
		ajout->content = malloc(strlen(content));
		strcpy(ajout->content, content);
		buffer->next = ajout;
	}
	return fact_basis;
}

void deleteFactBasis(BF fact_basis){
	if(isEmptyFactBasis(fact_basis)){
		printf("*** Base déjà vide ***\n");
	}
	else{
	/*
		BF buffer = fact_basis;
		BF buffer_of_buffer = NULL;
		while(isEmptyFactBasis(buffer) == false){
			buffer_of_buffer = buffer->next;
			free(buffer);
			free(buffer->content);
			buffer = buffer_of_buffer;
		}
		printf("*** Base de fait supprimée ***\n");
	*/
	}
}
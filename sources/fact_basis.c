#include "../headers/fact_basis.h"
#include "../headers/colors.h"

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
		printf(RED("Base de fait vide\n"));
	}
	else{
		BF buffer = fact_basis;
		printf(BLUE("-------------------- BASE DE FAITS --------------------\n\n"));
		while(buffer != NULL){
			printf(BLUE("- ")"%s\n", buffer->content);
			buffer = buffer->next;
		}
		printf(BLUE("\n-------------------------------------------------------\n\n"));
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
		while(!isEmptyFactBasis(buffer->next)){
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
		printf(RED("Base de fait déjà vide\n"));
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
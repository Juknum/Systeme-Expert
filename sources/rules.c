#include "../headers/rules.h"

/*------------------------------------*/

bool isEmptyRule(Regle r){
	if (r.conclusion == NULL && r.premisse == NULL) return true;
	return false;
}

/*------------------------------------*/

bool isEmptyPremisse(Premisse p){
	if (p == NULL) return true;
	return false;
}

/*------------------------------------*/

bool isEmptyConclusion(Regle r){
	if (r.conclusion == NULL) return true;
	return false;
}

/*------------------------------------*/

Regle createRule(){
	Regle new;
		new.premisse = NULL;
		new.conclusion = NULL;
	return new;
}

/*------------------------------------*/

Regle addProposition(Regle r, char* text){
	if(isEmptyRule(r)){
		r.premisse = (Premisse)malloc(sizeof(Proposition));
		r.premisse->content = malloc(strlen(text));
		strcpy(r.premisse->content, text);
		r.premisse->next = NULL;
	}
	else if(isProposition(r.premisse, text) == false){
		Regle buffer = r;

		while(!isEmptyPremisse(buffer.premisse->next)){
			buffer.premisse = buffer.premisse->next;
		}

		Premisse new = (Premisse)malloc(sizeof(Proposition));
		new->content = (char*)malloc(strlen(text)+1);
		strcpy(new->content, text);
		new->next = NULL;
		buffer.premisse->next = new;
	}
	else {
		printf("Vous avez déjà mis cette proposition dans cette prémisse");
	}
	printf("AHH\n");
	return r;
}

/*------------------------------------*/

Regle createConclusion(Regle r, char* content){
	if(isEmptyPremisse(r.premisse)) {
		printf("La prémisse de cette règle est vide, impossible de faire un conclusion");
	}
	else {
		r.conclusion = (char *)malloc(strlen(content)+1);
		strcpy(r.conclusion, content);
	}
	return r;
}

/*------------------------------------*/

bool isProposition(Premisse p, char* content){
	if(isEmptyPremisse(p)){
		return false;
	}
	else{
		if(strcmp(p->content, content) == 0){
			return true;
		}
		else{
			return isProposition(p->next, content);
		}
	}
}

/*------------------------------------*/

Premisse deleteProposition(Premisse p, char* proposition){
	if(isEmptyPremisse(p)){
		return p;
	}
	else if(strcmp(p->content, proposition)){
		if(isEmptyPremisse(p->next) == true){
			return NULL;
		}
		else{
			Premisse buffer = p->next;
			free(p->content);
			free(p);
			p = buffer;
			return p;
		}
	}
	else if(isEmptyPremisse(p->next)){
		return p;
	}
	else if(strcmp(p->next->content, proposition)){
		Premisse buffer = p->next->next;
		free(p->next->content);
		free(p->next);
		p->next = buffer;
		return p;
	}else{
		return deleteProposition(p->next, proposition);
	}
}

/*------------------------------------*/

char* headValuePremisse(Regle r){
	if(isEmptyPremisse(r.premisse)){
		return NULL;
	}
	else {
		return r.premisse->content;
	}
}

/*------------------------------------*/

char* valueConclusion(Regle r){
	 if(isEmptyConclusion(r)){
		return NULL;
	}
	else{
		return r.conclusion;
	}
}

/*------------------------------------*/

void displayRule(Regle r){
	if(isEmptyRule(r)){
		printf("\nLa règle est vide");
	}
	else{
		printf("***Regle***");
		Regle buffer = r;
		while(buffer.premisse != NULL){
			puts(buffer.premisse->content);
			buffer.premisse = buffer.premisse->next;
		}
		puts(r.conclusion);
	}
}
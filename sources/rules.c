#include "../headers/rules.h"
#include "../headers/colors.h"

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
	// si aucune règle n'est présente
	if(isEmptyRule(r)){
		r.premisse = (Premisse)malloc(sizeof(Proposition));
		r.premisse->content = malloc(strlen(text));
		strcpy(r.premisse->content, text);
		r.premisse->next = NULL;
	}
	// s'il y a déjà de règles et qu'elle n'en fait pas partie
	else if(isProposition(r.premisse, text) == false){
		Regle buffer = r;

		// on boucle jusqu'à la dernière déjà présente
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
		printf(RED("Vous avez déjà mis cette proposition dans cette prémisse"));
	}
	return r;
}

/*------------------------------------*/

Regle createConclusion(Regle r, char* content){
	if(isEmptyPremisse(r.premisse)) {
		printf(RED("La prémisse de cette règle est vide, impossible de faire un conclusion"));
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

Premisse deleteProposition(Premisse p, char* text){
	if (p == NULL) return NULL;
	if (p->next == NULL){
		if(strcmp(p->content, text) == 0){
			free(p->content);
			return p;
		} 
		else {
			return p;
		}
	}

	if (strcmp(p->content, text) == 0) {
		Premisse result = deleteProposition(p->next, text);
		free(p);
		return result;
	}
	else {
		p->next = deleteProposition(p->next, text);
		return p;
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
		printf(RED("La règle est vide\n"));
	}
	else{
		Regle buffer = r;
		while(buffer.premisse != NULL){
			printf(BLUE("-")" %s\n",buffer.premisse->content);
			buffer.premisse = buffer.premisse->next;
		}
		printf(CYAN("=>")" %s\n\n",r.conclusion);
	}
}
#include "rules.h"

/*------------------------------------*/

Bool isEmptyRule(Regle r){
	if (r.conclusion == NULL && r.premisse == NULL) return true;
	return false;
}

/*------------------------------------*/

Bool isEmptyPremisse(Premisse p){
	if (p == NULL) return true;
	return false;
}

/*------------------------------------*/

Bool isEmptyConclusion(Regle r){
	if (r.conclusion == NULL) return true;
	return false;
}

/*------------------------------------*/

Regle* createRule(){
	Regle* new = (Regle*)malloc(sizeof(Regle));
	return new;
}

/*------------------------------------*/

char* proposition(Regle r){
	if(isEmptyRule(r)){
		return NULL;
	}
	else if(isEmptyPremisse(r.premisse)){
		return NULL;
	}
	else{
		return r.premisse->content;
	}
}

/*------------------------------------*/

char* conclusion(Regle r){
	if(isEmptyRule(r)){
		return NULL;
	}
	else if(isEmptyConclusion(r)){
		return NULL;
	}
	else{
		return r.conclusion;
	}
}

/*------------------------------------*/

Regle addProposition(Regle r, char* content){
	if(isEmptyRule(r)){
		r.premisse = (Premisse)malloc(sizeof(Proposition));
		r.premisse->content = malloc(strlen(content));
		strcpy(r.premisse->content, content);
		r.premisse->next = NULL;
	}
	else if(isProposition(r.premisse, content) == false){
		Premisse tampon = r.premisse;
		while(isEmptyPremisse(tampon->next)){
			tampon = tampon->next;
		}
		Premisse new = (Premisse)malloc(sizeof(Proposition));
		new->content = malloc(sizeof(strlen(content)));
		strcpy(new->content, content);
		tampon->next = new;
	}
	else {
		printf("Vous avez déjà mis cette proposition dans cette prémisse");
	}
	return r;
}

/*------------------------------------*/

Regle createConclusion(Regle r, char* content){
	if(isEmptyPremisse(r.premisse)) {
		printf("La prémisse de cette règle est vide, impossible de faire un conclusion");
	}
	else {
		r.conclusion = (char *)malloc(sizeof(strlen(content)));
		strcpy(r.conclusion, content);
	}
	return r;
}

/*------------------------------------*/

Bool isProposition(Premisse p, char* content){
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

Premisse deleteProposition(Regle r, char* proposition){
	int c = 0;
	Regle l = r;
	Regle j = r; 
	if(isEmpty(l)){
		return NULL;
	}
	else
	{
			//a refaire
}

/*------------------------------------*/

char headValuePremisse(Regle r){
	if(isEmpty(r)){
		return NULL;
	}
	else if(isEmpty(r->next)){
		return NULL;
	}
	else {
		return head_element(r);
	}
}

/*------------------------------------*/

char valueConclusion(Regle r){
Regle l = r;
	if(isEmpty(l)){
		return NULL;
	}
	else{
		while(isEmpty(l->next) == false){
			l = l->next;
		}
		return l;
	}
}
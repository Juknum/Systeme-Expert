
/*------------------------------------*/

Bool isEmpty(Regle rule){
	if (rule == NULL) return true;
	return false;
}

/*------------------------------------*/

List createRule(Rule new_rule){
	return new_rule <- new(rule); // A REECRIRE
}

Regle newProposition(char proposition){
	return newProposition <- new(proposition); // A REECRIRE
}

Regle newConclusion(char conclusion){
	return newConclusion <- new(conclusion); // A REECRIRE
}

/*------------------------------------*/

int lengthRule(Rule r){
	int size = 0;
	Regle l = r;

	if (!isEmpty(l)) {
		while (l != NULL) {
			++size;
			l = l->next;
		}
	}

	return size;
	
}

/*------------------------------------*/

char getPremisse(Rule r){
	if (isEmpty(r)) return NULL;
	return premisse(r); // A REECRIRE
}

char getConclusion(Rule r){
	Regle l = r;

	if(isEmpty(l)) {
		return NULL;
	}
	else {
		while(l != NULL){
			l = l->next;
		}
		return conclusion(l) <- l // A REECRIRE
	}
}

/*------------------------------------*/

Regle addProposition(Regle r, char proposition){
	Regle l = r;

	if (isEmpty(l)) {
		l->next = NULL;
		proposition = getPremisse(l);
		newProposition(proposition);
	}
	else {
		while(l != NULL){
			l = l->next;
		}
		newProposition(proposition);
		l = getConclusion(l);
	}
}

/*------------------------------------*/

Regle createConclusion(Regle r, char conclusion){
	Regle l = r;
	if(isEmpty(l)) {
		conclusion = NULL;
	}
	else {
		while(isEmpty(l->next) = false){
			l = l->next;
		}
		newConclusion(conclusion);
		l->next = conclusion;
	}
}

/*------------------------------------*/

Bool isProposition(Regle r, char proposition){
	if(isEmpty(r)) {
		return false;
	}
	else if(head_element(r) = proposition) {
		return true;
	}
	return isProposition(tail_element(r), proposition);
}

/*------------------------------------*/

deleteProposition(Regle r, char proposition){
	int c = 0;
	Regle l = r;
	Regle j = r; 
	if(isEmpty(l)){
		return l;
	}
	else
	{
		while(isEmpty(l) = false && l != proposition){
			l = l->next;
			++c;
		}
		while(isEmpty(j) = false){
			for(i = c; i<lengthRule(j); i++){
				j = j->next;
			}
		}
	}
	return j;
	
}
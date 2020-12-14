
/*------------------------------------*/

Bool isEmpty(Rule rule){
	if (rule == NULL) return true;
	return false;
}

/*------------------------------------*/

List createRule(Rule new_rule){
	return new_rule <- new(rule); // A REECRIRE
}

Rule newProposition(char proposition){
	return newProposition <- new(proposition); // A REECRIRE
}

Rule newConclusion(char conclusion){
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
		l = getConclusion(l)
	}
}
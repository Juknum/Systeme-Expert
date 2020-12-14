#ifndef __RULES__H__
#define __RULES__H__

/*
 * Booléen:
*/
typedef enum {
	false,
	true
} Bool;

/*
 * Définition d'une Liste:
*/
typedef struct ListElement {
	int value;
	struct ListElement *next;
} ListElement, *List;

/*
 * Définition d'une Règle:
*/
typedef struct Element {
	int value;
	struct Element *next;
} Element, *Regle;

/*
 * Prototypes:
*/
List createRule(Rule new_rule);
Bool isEmpty(Rule rule);

#endif
#ifndef __RULES__H__
#define __RULES__H__

#include <stdlib.h>
#include <stdio.h>

/*
 * Booléen:
*/
typedef enum {
	false = 0,
	true = 1
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

/********************************
 * @brief fonction de création de règle vide
 * 
 * @param new_rule variable acceuillant la nouvelle regle
 * @return regle nouvellement créée
 */
Regle* createRule();

/**********************************
 * @brief fonction testant si la regle est vide ou non
 * 
 * @param rule variable de type regle à tester
 * @return booléen sur la variable
 */
Bool isEmpty(Regle rule);

/*************************************
 * @brief fonction de création de proposition dans une règle
 * 
 * @param proposition chaine de caractère acceuillant la proposition
 * @return proposition nouvellement créée
 */
Regle newProposition(char propostion);

/***************************************
 * @brief fonction de création de conclusion
 * 
 * @param conclusion chaine de caractère acceuillant la conclusion
 * @return conclusion nouvellement créée
 */
Regle newConclusion(char conclusion);

/****************************************
 * @brief fonction comptant le nombre de proposition d'une règle
 * 
 * @param r variable de type regle qui contient les propositions
 * @return entier indiquant le nombre de proposition
 */
int lengthRule(Regle r);

/****************************************
 * @brief fonction d'accès à la prémisse d'une règle
 * 
 * @param r variable de type regle contenant la prémisse
 * @return le contenu de la prémisse de la regle
 */
char getPremisse(Regle r);

/****************************************
 * @brief fonction d'accès à la conclusion d'une règle
 * 
 * @param r variable de type regle contenant la conclusion
 * @return le contenu de la conclusion de la regle
 */
char getConclusion(Regle r);

/****************************************
 * @brief fonction d'ajout d'une proposition à une prémisse
 * 
 * @param r variable de type regle contenant la prémisse
 * @param proposition chaine de caractère contenant la proposition à ajouter
 * @return pas de return car void
 */
void addProposition(Regle r, char proposition);

/****************************************
 * @brief fonction d'ajout d'une proposition à une prémisse
 * 
 * @param r variable de type regle contenant la conclusion (si elle existe déjà)
 * @param conclusion chaine de caractère contenant la conclusion à ajouter
 * @return pas de return car void
 */
void createConclusion(Regle r, char conclusion);

/****************************************
 * @brief fonction indiquant si une chaine de caractère est une proposition de la prémisse d'une règle
 * 
 * @param r variable de type regle contenant la prémisse
 * @param proposition chaine de caractère contenant la porposition à comparer à la prémisse
 * @return booléen sur la comparaison
 */
Bool isProposition(Regle r, char proposition);

/****************************************
 * @brief fonction de suppression de proposition dans une prémisse
 * 
 * @param r variable de type regle contenant la prémisse
 * @param proposition chaine de caractère contenant la porposition à supprimer de la prémisse
 * @return pas de return car void
 */
void deleteProposition(Regle r, char proposition);

/****************************************
 * @brief fonction indiquant si la prémisse est vide ou pas
 * 
 * @param r variable de type regle contenant la prémisse
 * @return booléen sur la prémisse
 */
Bool isEmptyPremisse(Regle r);

/****************************************
 * @brief fonction indiquant la valeur de la tête de la prémisse d'une règle
 * 
 * @param r variable de type regle contenant la prémisse
 * @return chaine de caractère de la tête de la prémisse
 */
char headValuePremisse(Regle r);

/****************************************
 * @brief fonction indiquant la valeur de la conclusion d'une règle
 * 
 * @param r variable de type regle contenant la conclusion
 * @return chaine de caractère de la conclusion
 */
char valueConclusion(Regle r);



#endif
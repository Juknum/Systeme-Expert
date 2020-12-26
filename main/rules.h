#ifndef __RULES__H__
#define __RULES__H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Booléen:
*/
typedef enum {
	false,
	true
} Bool;

/*
 * Définition d'une Proposition :
*/
typedef struct proposition {
	char* content;
	struct proposition* next;
} Proposition;

typedef Proposition* Premisse;

typedef char* Conclusion;

/*
 * Définition d'une Règle:
*/
typedef struct regle {
	Premisse premisse;
	Conclusion conclusion;
} Regle;

/*
 * Prototypes:
*/

/********************************
 * @brief fonction de création de règle vide
 * 
 * @param new_rule variable acceuillant la nouvelle regle
 * @return regle nouvellement créée
 */
Regle createRule();

/**********************************
 * @brief fonction testant si la regle est vide ou non
 * 
 * @param rule variable de type regle à tester
 * @return booléen sur la variable
 */
Bool isEmptyRule(Regle r);

/**********************************
 * @brief fonction testant si la premisse d'une regle est vide ou non
 * 
 * @param rule variable de type regle à tester
 * @return booléen sur la variable
 */
Bool isEmptyPremisse(Premisse p);

/**********************************
 * @brief fonction testant si la conclusion d'une regle est vide ou non
 * 
 * @param rule variable de type regle à tester
 * @return booléen sur la variable
 */
Bool isEmptyConclusion(Regle r);

/****************************************
 * @brief fonction comptant le nombre de proposition d'une règle
 * 
 * @param r variable de type regle qui contient les propositions
 * @return entier indiquant le nombre de proposition
 */
int lengthRule(Regle r);

/****************************************
 * @brief fonction d'ajout d'une proposition à une prémisse
 * 
 * @param r variable de type regle contenant la prémisse
 * @param proposition chaine de caractère contenant la proposition à ajouter
 * @return pas de return car void
 */
Regle addProposition(Regle r, char* content);

/****************************************
 * @brief fonction d'ajout d'une proposition à une prémisse
 * 
 * @param r variable de type regle contenant la conclusion (si elle existe déjà)
 * @param conclusion chaine de caractère contenant la conclusion à ajouter
 * @return pas de return car void
 */
Regle createConclusion(Regle r, char* content);

/****************************************
 * @brief fonction indiquant si une chaine de caractère est une proposition de la prémisse d'une règle
 * 
 * @param r variable de type regle contenant la prémisse
 * @param proposition chaine de caractère contenant la porposition à comparer à la prémisse
 * @return booléen sur la comparaison
 */
Bool isProposition(Premisse p, char* content);

/****************************************
 * @brief fonction de suppression de proposition dans une prémisse
 * 
 * @param r variable de type regle contenant la prémisse
 * @param proposition chaine de caractère contenant la porposition à supprimer de la prémisse
 * @return pas de return car void
 */
Premisse deleteProposition(Premisse p, char* proposition);

/****************************************
 * @brief fonction indiquant la valeur de la tête de la prémisse d'une règle
 * 
 * @param r variable de type regle contenant la prémisse
 * @return chaine de caractère de la tête de la prémisse
 */
char headValuePremisse(Premisse p);

/****************************************
 * @brief fonction retournant le contenu d'une prémisse
 * 
 * @param r variable de type regle contenant la prémisse
 * @return string du contenu
 */
char* proposition(Regle r);

/****************************************
 * @brief fonction retournant le contenu d'une conclusion
 * 
 * @param r variable de type regle contenant la conclusion
 * @return string du contenu
 */
char* valueConclusion(Regle r);


#endif

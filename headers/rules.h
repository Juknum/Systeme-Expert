#ifndef __RULES__H__
#define __RULES__H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Booléen:
*/
#include <stdbool.h>
// typedef enum { false, true } bool;

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
bool isEmptyRule(Regle r);

/**********************************
 * @brief fonction testant si la premisse d'une regle est vide ou non
 * 
 * @param p variable de type prémisse à tester
 * @return booléen sur la variable
 */
bool isEmptyPremisse(Premisse p);

/**********************************
 * @brief fonction testant si la conclusion d'une regle est vide ou non
 * 
 * @param r variable de type regle à tester
 * @return booléen sur la variable
 */
bool isEmptyConclusion(Regle r);

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
 * @param p variable de type premisse contenant la proposition
 * @param proposition chaine de caractère contenant la porposition à comparer à la prémisse
 * @return booléen sur la comparaison
 */
bool isProposition(Premisse p, char* content);

/****************************************
 * @brief fonction de suppression de proposition dans une prémisse
 * 
 * @param p variable de type prémisse contenant la proposition
 * @param text chaine de caractère contenant la porposition à supprimer de la prémisse
 * @return prémisse de la regle mise à jour
 */
Premisse deleteProposition(Premisse p, char* text);

/****************************************
 * @brief fonction indiquant la valeur de la tête de la prémisse d'une règle
 * 
 * @param r variable de type regle contenant la prémisse
 * @return chaine de caractère de la tête de la prémisse
 */
char* headValuePremisse(Regle r);

/****************************************
 * @brief fonction retournant le contenu d'une conclusion
 * 
 * @param r variable de type regle contenant la conclusion
 * @return string du contenu
 */
char* valueConclusion(Regle r);

/****************************************
 * @brief fonction une regle
 * 
 * @param r variable de type regle à afficher
 * @return pas de return
 */
void displayRule(Regle r);


#endif
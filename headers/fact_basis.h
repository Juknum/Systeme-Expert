#ifndef __FACT__BASIS__H__
#define __FACT__BASIS__H__

#include "../headers/rules.h"
#include "../headers/knowledge_basis.h"


//On recycle la structure Proposition utilisée pour les prémisses car les deux sont fait de la même manière

typedef Proposition* BF;


/******************************
 * @brief fonction de création d'une base de fait
 *
 * @return la base de fait créée
 */
BF createFactBasis();


/******************************
 * @brief fonction de test si base de fait vide ou non
 * 
 * @param fact_basis variable de type BF à tester
 * @return Booléen sur la base de fait
 */
bool isEmptyFactBasis(BF fact_basis);


/*****************************
 * @brief fonction d'ffichage de la base de fait
 * 
 * @param fact_basis variable de type BF qu'on affiche
 * @return pas de return
 */
void displayFactBasis(BF fact_basis);


/*****************************
 * @brief fonction d'ajout de fait à la base de fait
 * 
 * @param fact_basis variable de type BF à laquelle on ajoute des faits
 * @param content string contenant le fait à ajouter
 * @return Base de fait actualisée
 */
BF addFactFactBasis(BF fact_basis, char* content);

#endif
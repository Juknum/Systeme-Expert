#ifndef __KNOWLEDGE__BASIS__H__
#define __KNOWLEDGE__BASIS__H__

#include "../headers/rules.h"

typedef struct BC{
  Regle head;
  struct BC* next;
}ElemBC;

typedef ElemBC* BC;

/*
 * Prototypes : 
 */

/********************************
 * @brief fonction de création d'une base de connaissance
 * 
 * @return base de connaissance nouvellement créée
 */
BC createBasis();

/********************************
 * @brief fonction de test si base de connaissance vide
 * 
 * @param knowledge_basis base de connaissance à tester
 * @return booléen sur la base de connaissance
 */
bool isEmptyKnowledgeBasis(BC knowledge_basis);

/********************************
 * @brief fonction d'ajout de règle à une base
 * 
 * @param knowledge_basis variable de type BC acceuillant la base de connaissance
 * @param r variable de type règle à intégrer à BC
 * @return base connaissance actualisée 
 */
BC addRuleBasis(BC knowledge_basis, Regle r);

/********************************
 * @brief fonction d'accès à la valeur de tète de la base de connaissance
 * 
 * @param knoledge_basis variable de type BC acceuillant la base de connaissance
 * @return la regle qui est valeur de tête
 */
Regle headValueBasis(BC knowledge_basis);

/********************************
 * @brief fonction pour supprimer une base de connaissance
 * 
 * @param knoledge_basis variable de type BC acceuillant la base de connaissance
 * @return pas de return
 */
void deleteKnowledgeBasis(BC knowledge_basis);

/********************************
 * @brief fonction pour afficher une base de connaissance
 * 
 * @param knoledge_basis variable de type BC acceuillant la base de connaissance
 * @return pas de return
 */
void displayKnowledgeBasis(BC knowledge_basis);

#endif
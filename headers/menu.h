#ifndef __MENU__H__
#define __MENU__H__

#include "../headers/fact_basis.h"
#include "../headers/knowledge_basis.h"

#define MAX_LENGTH 255
#include <stdlib.h>

/********************************
 * @brief fonction d'affichage du menu
 * 
 * @param knowledge_basis base de connaissance du guide des UV
 * @param fact_basis base de fait de l'utilisateur
 * @return pas de return
 */
void menu(BC knowledge_basis);

/********************************
 * @brief affiche l'entête du programme
 *
 * @param aucun
 * @return aucun
*/
void header();

/********************************
 * @brief fonction pour lire une entrée écrite sur la console
 *
 * @param aucun
 * @return retourne une string de l'entrée sur la console
*/
char* entry_char();

/********************************
 * @brief fonction pour lire une entrée écrite sur la console
 *
 * @param aucun
 * @return retourne un entier de type long de l'entrée sur la console
*/
long entry_num();

#endif
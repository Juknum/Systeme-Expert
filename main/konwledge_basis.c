#include "knowledge_basis.h"

/*------------------------------------*/

BC createBasis(){
    BC new = (BC)malloc(sizeof(ElemBC));
    return new;
}

/*------------------------------------*/

 BC addRuleBasis(BC knowledge_basis, Regle r){
     if (knowledge_basis == NULL){
         knowledge_basis->head = r;
         knowledge_basis->next = NULL;
     }
     else {
         while(knowledge_basis->next != NULL){
             knowledge_basis = knowledge_basis->next;
         }
         BC new = (BC)malloc(sizeof(ElemBC));
         new->head = r;
         knowledge_basis->next = new;
     }
 }

 /*------------------------------------*/

 Regle headValueBasis(BC knowledge_basis){
     return knowledge_basis->head;
 }
 
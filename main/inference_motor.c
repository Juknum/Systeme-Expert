#include "inference_motor.h"

void inference_motor(BC knowledge_basis, BF fact_basis){
    if(isEmptyFactBasis(fact_basis)){
        printf("La base de fait est vide");
    }
    else if(isEmptyKnowledgeBasis(knowledge_basis)){
        printf("La base de fait est vide");
    }
    else {
        Bool comp;
        Premisse buffer = fact_basis;

        while(buffer->next != NULL){
            buffer = buffer->next;
        }

        do{
            do{

                //Algo qui parcourt et compare tout à caler ici

            }while(knowledge_basis != NULL);
        }while(fact_basis != NULL);
    }
}
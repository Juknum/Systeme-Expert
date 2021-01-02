#include "../headers/inference_motor.h"

void inference_motor(BC knowledge_basis, BF fact_basis){
	if(isEmptyFactBasis(fact_basis)){
		printf("La base de fait est vide");
	}
	if(isEmptyKnowledgeBasis(knowledge_basis)){
		printf("La base de connaissance est vide");
	}

	else {
		bool comp;
		Premisse buffer = fact_basis;

		while(buffer->next != NULL){
			buffer = buffer->next;
		}

		do{
			do{
        comp = isProposition(knowledge_basis->head->premisse, fact_basis->proposition);
				if(comp == true){
          knowledge_basis->head->premisse = deleteProposition(knowledge_basis->head->premisse, fact_basis->proposition);
            if(knowledge_basis->head->premisse == NULL){
              Premisse new = (Premisse)malloc(sizeof(ElemBC));
              new->proposition = knowledge_basis->head->conclusion;
              end->next = new;
              printf("%s\n", end->proposition);
            }
        }

			}while(knowledge_basis != NULL);
		}while(fact_basis != NULL);
	}
}
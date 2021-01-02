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
        comp = isProposition(knowledge_basis->head.premisse, fact_basis->content);
				if(comp == true){
          knowledge_basis->head.premisse = deleteProposition(knowledge_basis->head.premisse, fact_basis->content);
            if(knowledge_basis->head.premisse == NULL){
              Premisse new = (Premisse)malloc(sizeof(ElemBC));
              new->content = knowledge_basis->head.conclusion;
              buffer->next = new;
              printf("%s\n", buffer->content);
            }
        }

			}while(knowledge_basis != NULL);
		}while(fact_basis != NULL);
	}
}
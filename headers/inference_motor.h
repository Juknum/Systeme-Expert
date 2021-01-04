#ifndef __INFERENCE__MOTOR__H__
#define __INFERENCE__MOTOR__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/rules.h"
#include "../headers/knowledge_basis.h"
#include "../headers/fact_basis.h"

BC search_uv(BC knowledge_basis, BF fact_basis);
void inference_motor(BC knowledge_basis, BF fact_basis);

#endif
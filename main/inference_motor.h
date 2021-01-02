#ifndef __INFERENCE__MOTOR__H__
#define __INFERENCE__MOTOR__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rules.h"
#include "knowledge_basis.h"
#include "fact_basis.h"

void inference_motor(BC knowledge_basis, BF fact_basis);

#endif
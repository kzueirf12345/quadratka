#ifndef SRC_CALCULATE_H
#define SRC_CALCULATE_H


#include <math.h>
#include <assert.h>

#include "../structs/structs.h"


Answer linear_calculate(const Coefs coefs);
Answer quadratic_calculate(const Coefs coefs);

Answer calculate(const Coefs coefs);


#endif /* SRC_CALCULATE_H */
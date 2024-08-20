#pragma once

#include <math.h>

#include "../structs/structs.h"

Answer linear_calculate(const Coefs coefs);
Answer quadratic_calculate(const Coefs coefs);
Answer calculate(const Coefs coefs);
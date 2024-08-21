#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "src/input/input.h"
#include "src/calculate/calculate.h"
#include "src/output/output.h"

//src rename src
int main()
{
    Coefs coefs = {0, 0, 0};
    if (input(&coefs) == INPUT_FAILURE)
    {
        fprintf(stderr, "INPUT_FAILURE\t ferror(stdin) = %d", ferror(stdin));
        return 0;
    }

    const Answer answer = calculate(coefs);
    print(answer);

    return 0;
}
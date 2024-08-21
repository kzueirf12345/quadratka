#include "output.h"

void print(const Answer answer)
{
    printf("Answer: ");
    switch (answer.count_solutions) 
    {
        case ZERO_SOLUTIONS:
        {
            printf("zero solutions\n");
            break;
        }
        case ONE_SOLUTIONS: 
        {
            printf("x = %g\n", fix_double_zero(answer.root1));
            break;
        }
        case TWO_SOLUTIONS: 
        {
            printf("x = %g, %g\n", fix_double_zero(answer.root1), fix_double_zero(answer.root2));
            break;
        }
        case INF_SOLUTIONS: 
        {
            printf("x - any number\n");
            break;
        }
        case NOT_REAL_SOLUTIONS: 
        {
            printf("no real solutions\n");
            break;
        }
        default: 
        {
            assert(0 && "Unknown error\n");
            break;
        }
    }
}

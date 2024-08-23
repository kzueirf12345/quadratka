#include "output.h"

#include "../utils/console.h"

OutputCode print(FILE* stream, const Answer answer)
{
    assert(stream && "stream is nullptr");
    
    int count_output = 0;
    switch (answer.count_solutions) 
    {
        case ZERO_SOLUTIONS:
        {
            count_output = fprintf(stream, "zero solutions\n");
            break;
        }
        case ONE_SOLUTIONS: 
        {
            count_output = fprintf(stream, "x = %g\n", fix_double_zero(answer.root1));
            break;
        }
        case TWO_SOLUTIONS: 
        {
            count_output = fprintf(stream, "x = %g, %g\n", 
                                            fix_double_zero(answer.root1), 
                                            fix_double_zero(answer.root2));
            break;
        }
        case INF_SOLUTIONS: 
        {
            count_output = fprintf(stream, "x - any number\n");
            break;
        }
        case NOT_REAL_SOLUTIONS: 
        {
            count_output = fprintf(stream, "no real solutions\n");
            break;
        }
        default: 
        {
            assert(0 && "Unknown error\n");
            break;
        }
    }
    return count_output > 0 ? OUTPUT_SUCCESS : OUTPUT_FAILURE;
}

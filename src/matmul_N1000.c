#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matrix_lib.h"
#include "vector_lib.h"

const size_t N = 1000;


int main()
{
    
    int NRuns = 5;
    size_t i, j, k;
 
    double *runtimes;
    double *A, *B, *C, *V;
    
    A = (double *) malloc(N * N * sizeof(double));
    B = (double *) malloc(N * N * sizeof(double));
    C = (double *) malloc(N * N * sizeof(double));
    V = (double *) malloc(N *  sizeof(double));
    
    runtimes = (double *) malloc(NRuns * sizeof(double));

    RandomMatrix(&A[0], N);
    RandomMatrix(&B[0], N);
    RandomVector(&V[0], N);     

// ijk ordering
    double average_runtime = 0.0;
    for(int n=0; n<NRuns; n++)
    {
        runtimes[n]=CalcVecMulTime(&A[0], &V[0], &C[0], N);
        printf("runtime %lf seconds\n", runtimes[n]);
        average_runtime += runtimes[n]/NRuns;
    }

    printf("average runtime matrix by vector  %lf seconds\n", average_runtime);
    printf("---------------------------------\n");


// ijk ordering
    average_runtime = 0.0;
    for(int n=0; n<NRuns; n++)
    {
        runtimes[n]=CalcMatMulTime(&A[0], &B[0], &C[0], N);
        printf("runtime %lf seconds\n", runtimes[n]);
        average_runtime += runtimes[n]/NRuns;
    }

    printf("average runtime matrix by matrix %lf seconds\n", average_runtime);
    printf("---------------------------------\n");

 
    free(A); 
    free(B);
    free(C);
    return 0;
}

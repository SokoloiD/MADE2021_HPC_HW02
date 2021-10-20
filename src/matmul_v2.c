#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

const size_t N = 1024;



void ZeroMatrix(double * A, size_t N)
{
    for(size_t i=0; i<N; i++)
    {
        for(size_t j=0; j<N; j++)
        {
            A[i * N + j] = 0.0;
        }
    }
}

void RandomMatrix(double * A, size_t N)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i * N + j] = rand() / RAND_MAX;
        }
    }
}

double CalcMatMulTime_ijk(double * A, double * B, double * C, size_t N)
{
    struct timeval start, end;
    double r_time = 0.0;
    size_t i, j, k;

    ZeroMatrix(&C[0], N);

    gettimeofday(&start, NULL);
    
    for (i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            for(k = 0; k < N; k++)
                C[i * N + j] = C[i * N + j] + A[i * N + k] * B[k * N + j];
        }
    gettimeofday(&end, NULL);
    
    r_time = end.tv_sec - start.tv_sec + ((double) (end.tv_usec - start.tv_usec)) / 1000000;
    
    return r_time;
}

void ZeroVector(double * A, size_t N)
{
    for(size_t i=0; i<N; i++)
    {
         
        A[i] = 0.0;
        
    }
}


void RandomVector(double * A, size_t N)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        A[i] = rand() / RAND_MAX;

    }
}

double CalcVecMulTime(double * A, double * B, double * C, size_t N)
{
    struct timeval start, end;
    double r_time = 0.0;
    size_t i, j, k;

    ZeroMatrix(&C[0], N);

    gettimeofday(&start, NULL);
    
    for (i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {            
            C[i * N + j] =  A[i * N + j] * B[j];
        }
    gettimeofday(&end, NULL);
    
    r_time = end.tv_sec - start.tv_sec + ((double) (end.tv_usec - start.tv_usec)) / 1000000;
    
    return r_time;
}


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
        runtimes[n]=CalcMatMulTime_ijk(&A[0], &B[0], &C[0], N);
        printf("runtime %lf seconds\n", runtimes[n]);
        average_runtime += runtimes[n]/NRuns;
    }

    printf("average runtime ijk %lf seconds\n", average_runtime);
    printf("---------------------------------\n");

 
    free(A); 
    free(B);
    free(C);
    return 0;
}

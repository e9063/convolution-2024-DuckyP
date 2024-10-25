#include<stdio.h>
#include<stdlib.h>
#include <omp.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    // implement here
    int sum[NA-NF+1];
    int num_threads = 4;
    omp_set_num_threads(num_threads);
    #pragma omp parallel for
    for(int i = 0; i < (NA-NF+1); i++){
        int tmp = 0;
        for(int j = 0; j < NF; j++){
            tmp += (A[i+j] * F[NF-1-j]);
        }
        sum[i] = tmp; 
    }

    for(int i = 0; i < (NA-NF+1); i++){
        printf("%d\n", sum[i]);
    }

    // ---- free memory ----
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}


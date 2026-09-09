#include <stdio.h>

int main()
{
    int A[100], N;
    int K, J, MIN, LOC, TEMP;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    printf("Enter %d elements:\n", N);
    for (J = 0; J < N; J++)
    {
        scanf("%d", &A[J]);
    }

    
    for (K = 0; K < N - 1; K++)
    {
        MIN = A[K];
        LOC = K;

        
        for (J = K + 1; J < N; J++)
        {
            if (MIN > A[J])
            {
                MIN = A[J];
                LOC = J;
            }
        }

        TEMP = A[K];
        A[K] = A[LOC];
        A[LOC] = TEMP;
    }

    printf("Sorted array:\n");
    for (J = 0; J < N; J++)
    {
        printf("%d ", A[J]);
    }

    return 0;
}
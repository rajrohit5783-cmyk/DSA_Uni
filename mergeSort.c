#include <stdio.h>

void merge(int A[], int B[], int C[], int R, int S)
{
    int i = 0, j = 0, k = 0;

    while (i < R && j < S)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++;
        }
        else
        {
            C[k] = B[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of A
    while (i < R)
    {
        C[k] = A[i];
        i++;
        k++;
    }

    // Copy remaining elements of B
    while (j < S)
    {
        C[k] = B[j];
        j++;
        k++;
    }
}

int main()
{
    int A[5] = {1, 4, 7, 10, 15};
    int B[4] = {2, 3, 8, 12};
    int C[9];

    merge(A, B, C, 5, 4);

    printf("Merged array: ");

    for (int i = 0; i < 9; i++)
    {
        printf("%d ", C[i]);
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int a[3][3], b[3][3], c[3][3];
    int i, j, k;

    printf("Enter elements of Matrix A:\n");
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of Matrix B:\n");
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            scanf("%d", &b[i][j]);

    printf("\nAddition:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            printf("%d\t", a[i][j] + b[i][j]);
        printf("\n");
    }

    printf("\nSubtraction:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            printf("%d\t", a[i][j] - b[i][j]);
        printf("\n");
    }

    printf("\nMultiplication:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            c[i][j] = 0;
            for(k=0; k<3; k++)
                c[i][j] += a[i][k] * b[k][j];
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose of Matrix A:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            printf("%d\t", a[j][i]);
        printf("\n");
    }

    return 0;
}
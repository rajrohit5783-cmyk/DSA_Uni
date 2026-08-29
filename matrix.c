#include<stdio.h>

int main(){
    int A[2][2];
    int B[2][2];
    int Addition[2][2];

    int row,column;

    printf("Enter the Matrix A: ");
    for(row=0;row<2;row++)
        for(column=0;column<2;column++)
            scanf("%d",&A[row][column]);

    printf("Enter the Matrix B: ");
    for(row=0;row<2;row++)
        for(column=0;column<2;column++)
            scanf("%d",&B[row][column]);  
            
    for(row=0;row<2;row++)
        for(column=0;column<2;column++)
            Addition[row][column] = A[row][column] + B[row][column];
   
   printf("The Addition is: ");
   for(row=0;row<2;row++){
        for(column=0;column<2;column++)
        printf("%d ", Addition[row][column]);
    printf("\n");     
   }

   int Subtract [2][2];

   for(row=0;row<2;row++)
        for(column=0;column<2;column++)
            Subtract[row][column] = A[row][column] - B[row][column];
   
   printf("The Substraction is: ");
   for(row=0;row<2;row++){
        for(column=0;column<2;column++)
        printf("%d ", Subtract[row][column]);
    printf("\n");     
   }
  
   
   return 0;


}   
#include<stdio.h>
#include <stdlib.h>

#define MOD_VAL 1000000007

int main(){
   long long int i,j;
   int N,M;
   int **A;
   long long int columnSum=0, product=1;
   long long int validInput = 0;
   while(!validInput){
       scanf("%d %d", &N, &M);
       if(N<1 || M<1 || N>100 || M>100){
           printf("M and N must lie between 1 nad 100. Enter again\n");
           validInput = 0;
       }else{
           validInput = 1;
       }
   }
   	A = (int **)malloc(N * sizeof(int *));
	for (i=0; i<N; i++)
	A[i] = (int *)malloc(M * sizeof(int));
   	for(i=0; i<N;i++){
       for(j=0;j<M;j++){
           validInput = 0;
           while(!validInput){
               scanf("%d",&A[i][j]);
               if(A[i][j]>1000000000 || A[i][j]<0){
                   printf("Value must be greater or equal to 0 and less or equal to 10^9. Enter again\n");
                   validInput = 0;
               }else{
                   validInput = 1;
               }
           }
          
       }
   }
   for(j=0; j<M;j++){
       columnSum = 0;
       for(i=0;i<N;i++){
           columnSum += A[i][j];
       }  
       product = (product * (columnSum % MOD_VAL)) % MOD_VAL;
   }
   printf("%d\n",product);
}

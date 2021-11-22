#define TEN 10
#define INF 99998
#include <stdio.h>
#include <stdlib.h>
int matrix[TEN][TEN];

void func1() 
 { 
   for(int temp=0; temp<TEN; temp++) {
      for(int temp2=0;temp2<TEN;temp2++) {
         int val;
         scanf("%d", &val);
           matrix[temp][temp2] = val;
      }
     }
   }

int func3() {
   int finallMatrix [TEN][TEN];
   for (int i = 0 ; i<TEN ; i++) {
      for (int j = 0 ; j<TEN ; j++) {
         if (i == j)
            finallMatrix [i][j] = 0 ;
         else if (matrix[i][j] == 0)
            finallMatrix [i][j] = INF ;
         else 
            finallMatrix[i][j] = matrix[i][j];
      }
   }
   for (int k = 0; k < TEN; k++){
      for (int i = 0; i < TEN; i++){
         for (int j = 0; j < TEN; j++){
            int sum = finallMatrix[i][k] + finallMatrix[k][j];
            int current = finallMatrix[i][j];
            int finall;
            if (sum<current){
               finall =  sum;
            }
            else {
               finall = current;
            }
            finallMatrix[i][j] = finall;
         }
      }
   }
   int i,j;
   scanf("%d", &i);
   scanf("%d", &j);
   int ans = finallMatrix [i][j];
   if (ans == 0 || ans >= INF)
      ans = -1;
return ans;
}

void func2(){
int a = func3();
if (a == -1)
printf("False");
else printf("True");}

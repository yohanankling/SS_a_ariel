#include <stdio.h>
#include "NumClass.h"
int main (){
int max;
scanf("%d", &max);
int min;
scanf("%d", &min);
int temp=0;
if(max<min){
temp=max;
max=min;
min=temp;}
int ans=0;
printf("The Armstrong numbers are:");
for (int i=min;i<=max;i++){
ans = isArmstrong(i);
  if  (ans==1){
    printf(" %d",i);}
}
printf("\n");

printf("The Palindromes are:");
for (int i=min;i<=max;i++){
ans = isPalindrome(i);
  if  (ans==1){
    printf(" %d",i);}
}
printf("\n");

printf("The Prime numbers are:");
for (int i=min;i<=max;i++){
ans = isPrime(i);
  if  (ans==1){
    printf(" %d",i);}
}
printf("\n");

printf("The Strong numbers are:");
for (int i=min;i<=max;i++){
ans = isStrong(i);
  if  (ans==1){
    printf(" %d",i);}
}
printf("\n");

    return 0;
}

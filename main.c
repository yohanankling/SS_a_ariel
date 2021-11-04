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
printf("The Armstrong numbers are: ");
for (int i=min;i<max;i++){
ans = isArmstrong(i);
  if  (ans==1){
    printf("%d ",i);}
}
ans = isArmstrong(max);
if (ans==1)
    printf("%d",max);
printf("\n");

printf("The Palindrome are: ");
for (int i=min;i<max;i++){
ans = isPalindrome(i);
  if  (ans==1){
    printf("%d ",i);}
}
ans= isPalindrome(max);
if (ans==1)
    printf("%d",max);
printf("\n");

printf("The Prime numbers are: ");
for (int i=min;i<max;i++){
ans = isPrime(i);
  if  (ans==1){
    printf("%d ",i);}
}
ans = isPrime(max);
if (ans==1)
    printf("%d",max);
printf("\n");

printf("The Strong numbers are: ");
for (int i=min;i<max;i++){
ans = isStrong(i);
  if  (ans==1){
    printf("%d ",i);}
}
ans = isStrong(max);
if (ans==1){
    printf("%d",max);}

    return 0;
}
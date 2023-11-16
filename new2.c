#include <stdio.h>
int main(){
 int n,num,prime = 0,composite = 0,i,j,temp;
 scanf("%d",&n);
 int array1[20],array2[20];
 for (i = 0; i <= n-1; i ++){
  if (i < n-1){
   scanf("%d ",&num);
  }else{
      scanf("%d",&num);
  }
        array1[i] = num;
 }
 for (i = 0; i <= n-1; i ++){
  for (j = 2; j <= array1[i] - 1; j ++){
      if (array1[i] % j == 0){
       composite = composite + 1;
       break;
   }else{
    if (j == array1[i] - 1){
     array2[prime] = array1[i];
     prime = prime + 1;
    }else{
     continue;
    }
   }
     }
 }
 
 for (i = 1; i <= prime-1; i ++){
  if (array2[i-1] > array2[i]){
   temp = array2[i-1];
   array2[i-1] = array2[i];
   array2[i] = temp;
  }
    }
    if (composite != 0 && prime == 0){
     printf("no prime");
 }else{
  for (i = 0; i <= prime-1; i ++){
   printf("%d ",array2[i]);
     }
 }
 return 0;
}
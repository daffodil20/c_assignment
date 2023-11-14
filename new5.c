#include <stdio.h>
int transfer(int h[1000], int end){
 int d_array[1000];
 int i,j;
 for (i = end - 1; i >= 0; i --){
  for (j = 1; j < end - i; j ++){
      d_array[i] = h[i] * 16;
     }
 }
 return d_array;
}

int main(){
 int h_array[1000];
 int element;
 int counter, *result,length = 0;
 for (counter = 0; counter <= 999; counter ++){
  scanf("%x",&element);
  if (element != '\n'){
   h_array[counter] = element;
      printf("%x\n",h_array[counter]);
      length ++;
  }
  if (element == '\n'){
   break;
  }
 }
 result = transfer(h_array,counter);
 for (counter = 0; counter <= length-1; counter ++){
     printf("%d",result[counter]);
 }
 return 0;
}
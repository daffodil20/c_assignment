#include <stdio.h>
int main(){
 int array1[3],array3[3],array4[3],array5[3],total[3];
 int id,maths,English,computer;
 char name[20],array2[3][20];
 int row,max,first,second,third;
 for (row = 0; row <= 2; row ++){
  scanf("%d    %s    %d    %d    %d",&id,name,&maths,&English,&computer);
  array1[row] = id;
  *array2[row] = *name;
  array3[row] = maths;
  array4[row] = English;
  array5[row] = computer;
  total[row] = array3[row] + array4[row] + array5[row];
  printf("\ntotal[%d]:%d\n", row, total[row]);
 }
 printf("\ntotal[1]:%d\n",total[1]);
 max = total[0];
 for (row = 0; row <= 2; row ++){
  if (total[row] > max){
      max = total[row];
      first = row;
  }else{
   first = 0;
  }
 }
 printf("%d    %s    %d    %d    %d    %d\n",array1[first],array2[first],array3[first],array4[first],array5[first],total[first]);
 total[first] = 0;
 max = total[1];
 for (row = 0; row <= 2; row ++ ){
  if (total[row] > max){
      max = total[row];
      second = row;
      third = 1;
  }else{
   second = 1;
   third = 2;
  }
 }
 printf("%d    %s    %d    %d    %d    %d\n",array1[second],array2[second],array3[second],array4[second],array5[second],total[second]);
 printf("%d    %s    %d    %d    %d    %d\n",array1[third],array2[third],array3[third],array4[third],array5[third],total[third]);
 return 0;

}
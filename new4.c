#include <stdio.h>
#include <math.h>
#include <complex.h>
double * func1(double a1,double b1,double c1){
 double x1,x2,array1[2];
 x1 = (-b1 + pow((b1*b1 - 4*a1*c1),0.5))/(2*a1);
 x2 = (-b1 - pow((b1*b1 - 4*a1*c1), 0.5))/(2*a1);
 array1[0] = x1;
 array1[1] = x2;
 return array1;
}
double func2(double a2,double b2,double c2){
 double y1;
 y1 = (-b2 + pow((b2*b2 - 4*a2*c2), 0.5))/(2*a2);
 return y1;
}
double complex * func3(double a3,double b3,double c3){
 double complex z1,z2,array2[2];
 z1 = (- b3 + I * pow((- b3*b3 + 4*a3*c3), 0.5))/(2*a3);
 z2 = (- b3 - I * pow((- b3*b3 + 4*a3*c3), 0.5))/(2*a3);
 array2[0] = z1;
 array2[1] = z2;
 return array2;
}
int main(){
 int counter;
 double a,b,c,result2,result4;
 double * result1;
 double complex * result3;
 scanf("%lf %lf %lf",&a,&b,&c);
 printf("abc: %lf %lf %lf\n", a, b, c);
 if (a != 0){
  if (b*b - 4*a*c > 0){
      result1 = func1(a,b,c);
      for (counter = 0; counter <= 1; counter ++){
       printf("func1\n");
          printf("%.2f ",result1[counter]);
      }
      }
     else if (b*b - 4*a*c == 0){
      result2 = func2(a,b,c);
      printf("func2\n");
      printf("%.2f",result2);
     }else{
      result3 = func3(a,b,c);
      printf("func3\n");
      printf("%.2f+i%.2f ",creal(result3[0]),cimag(result3[0]));
      printf("%.2f-i%.2f",creal(result3[1]),cimag(result3[1]));
     }
 }
 if (a == 0){
  if (b != 0){
   result4 = -c/b;
  }
 }
 return 0;
}
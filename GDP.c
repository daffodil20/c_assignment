#include <stdio.h>
#include <math.h>
int main()
{   float r,p,n;
    // int n;
    printf("请输入GDP年增长率r和年数n:");
    scanf("%f %f",&r,&n);
    p = pow(1+r,n);
    printf("%.2f",p);
    return 0;
}
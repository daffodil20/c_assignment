#include <stdio.h>
int main()
{
    float r,c,s,v;
    printf("请输入一个圆的半径:");
    scanf("%f",&r);
    c=3.14*2*r;
    s=3.14*r*r;
    v=(4.0/3)*3.14*r*r*r;
    printf("%.2f\n%.2f\n%.2f",c,s,v);
    return 0;
}
#include <stdio.h>
int main()
{
    int num,num1,num2,num3,num4,num5;
    printf("请输入一个五位数：");
    scanf("%5d",&num);
    num1 = num%10;
    num2 = ((num-num1)%100)/10;
    num3 = ((num-num1-num2*10)%1000)/100;
    num4 = ((num-num1-num2*10-num3*100)%10000)/1000;
    num5 = ((num-num1-num2*10-num3*100-num4*1000)%100000)/10000;
    printf("%d %d %d %d %d",num5,num4,num3,num2,num1);
    return 0;

}
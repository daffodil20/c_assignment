#include <stdio.h>
int main()
{
    int num,num1,num2,num3,num4,num5;
    printf("请输入一个五位数：");
    scanf("%5d",&num);
    num1 = num/10000;
    num2 = (num/1000)%10;
    num3 = (num/100)%10;
    num4 = (num/10)%10;
    num5 = num%10;
    printf("%d %d %d %d %d",num1,num2,num3,num4,num5);
    return 0;

}
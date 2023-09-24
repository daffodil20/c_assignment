#include <stdio.h>
int main()
{
    int num,i,digit,t;
    int a[5];
    printf("请输入一个五位数：");
    scanf("%5d",&num);
    for (i = 4;i >= 0;i--)
    {
        digit = num%10;
        num = num/10;
        a[i] = digit;
    }
    for (t=0;t<5;t++)
    {
        printf("%d ",a[t]);
    }
    return 0;
}
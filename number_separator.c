#include <stdio.h>
int main()
{
    int num,i,digit;
    int a[5];
    printf("请输入一个五位数：");
    scanf("%5d",&num);
    for (i = 4;i >= 0;i--)
    {
        digit = num%10;
        num = num/10;
        a[i] = digit;
    }
    for (i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
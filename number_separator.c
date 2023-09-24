#include <stdio.h>
// #include <math.h>
int main()
{
    int num,i,temp,digit;
    int a[5];
    // double i,temp;
    printf("请输入一个五位数：");
    scanf("%5d",&num);
    for (i = 4;i--;i >= 0)
    {
        if (i==4)
        {
            digit = num%10;
            temp = num/10;
            a[i] = digit;
            // display = (temp-display)/10;
            printf("%d ",a[i]);
        }
        if (i<4)
        {
            digit = temp%10;
            temp = temp/10;
            a[i] = digit;
            // display = (temp-display)/10;
            printf("%d ",a[i]);
        }
    }
        
        // temp = 1.0*(num/pow(10.0,i))%10;
        
        // num2 = (num/1000)%10;
        // num3 = (num/100)%10;
        // num4 = (num/10)%10;
        // num5 = num%10;
    // printf("%d %d %d %d %d",num1,num2,num3,num4,num5);
    return 0;

}
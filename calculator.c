#include <stdio.h>
int main()
{
    int i1,i2,sum,product,substraction_result,quotient,remainder;
    printf("Please enter 2 integers with a space between them:");
    scanf("%d %d",&i1,&i2);
    sum = i1+i2;
    product = i1*i2;
    substraction_result = i1-i2;
    quotient = i1/i2;
    remainder = i1%i2;
    printf("%d %d %d %d %d",sum,product,substraction_result,quotient,remainder);
    return 0;
}

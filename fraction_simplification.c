#include <stdio.h>
int main(){
    int num1,num2,factor;
    printf("请依次输入一个分子和分母（分子小于分母）:");
    scanf("%d %d",&num1,&num2);
    for (factor = 2;factor <= num1;factor++){
        if (num1%factor == 0 && num2%factor == 0){
            num1 = num1/factor;
            num2 = num2/factor;
        } 
    }
    printf("%d %d",num1,num2);
return 0;
}
#include<stdio.h>
int main(){
    int num,total_digits,i,sum = 0,digit,temp;
    printf("Please enter an integer smaller than 10000:");
    scanf("%d",&num);
    if (0 <= num && num < 10){
        total_digits = 1;
    }
    if (10 <= num && num < 100){
        total_digits = 2;
    }
    if (100 <= num && num < 1000){
        total_digits = 3;
    }
    if (1000 <= num && num < 10000){
        total_digits = 4;
    }
    for (i = 1;i <= total_digits;i = i + 1){
        if (i == 1){
            sum = sum + num % 10;
        }else{
            temp = num;
            temp = temp / 10;
            digit = temp % 10;
            sum = sum + digit;
        }
    }
    if (num % sum == 0){
        printf("TRUE");
    }else{
        printf("FALSE");
    }
    return 0;
}
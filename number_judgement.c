#include <stdio.h>
int main(){
    int num,digit1,digit2,digit4,digit5;
    printf("Please enter a 5 digits number:");
    scanf("%5d",&num);
    digit1 = num%10;
    digit2 = (num%100)/10;
    digit4 = (num/1000)%10;
    digit5 = (num/1000)/10;
    if (num/10000 != 0){
        if (digit1 == digit5 && digit2 == digit4){
            printf("YES");
        }
        if (digit1 != digit5 || digit2 != digit4){
            printf("NO");
        }
    }
    if (num/10000 == 0){
        printf("error");
    }
    // if (digit1 != digit5 || digit2 != digit4){
    //     printf("NO");
    // }
    return 0;
}
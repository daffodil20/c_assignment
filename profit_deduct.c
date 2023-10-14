#include<stdio.h>
int main(){
    // int profit;
    double bonus,profit;
    // float temp;
    printf("Please enter a monthly profit:");
    scanf("%le",&profit);
    profit = 0.0001*profit;
    // printf("%le",profit);
    if (profit <= 10){
        bonus = 0.1*profit;
        printf("%.2f",bonus*10000);
    }
    if (10 < profit && profit < 20){
        bonus = 0.1*10+0.075*(profit-10);
        printf("%.2f",bonus*10000);
    }
    if (20 <= profit && profit <= 40){
        bonus = 0.1*10+0.075*10+0.05*(profit-20);
        printf("%.2f",bonus*10000);
    }
    if (40 < profit && profit <= 60){
        bonus = 0.1*10+0.075*10+0.05*20+0.03*(profit-40);
        printf("%.2f",bonus*10000);
    }
    if (60 < profit && profit <= 100){
        bonus = 0.1*10+0.075*10+0.05*20+0.03*20+0.015*(profit-60);
        printf("%.2f",bonus*10000);
    }
    if (profit > 100){
        bonus = 0.1*10+0.075*10+0.05*20+0.03*20+0.015*40+0.01*(profit-100);
        printf("%.2f",bonus*10000);
    }
    // bonus = bonus*10000;
    // printf("%.2f",bonus);
    return 0;
}
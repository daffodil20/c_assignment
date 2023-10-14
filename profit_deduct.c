#include<stdio.h>
int main(){
    int profit;
    double bonus;
    printf("Please enter a monthly profit:");
    scanf("%d",&profit);
    profit = 0.0001*profit;
    printf("%d",profit);
    if (profit <= 10){
        bonus = 0.1*profit;
    }
    if (10 < profit < 20){
        bonus = 0.075*(profit-10);
    }
    if (20 <= profit <= 40){
        bonus = 0.05*(profit-20);
    }
    if (40 < profit <= 60){
        bonus = 0.03*(profit-40);
    }
    if (60 < profit <= 100){
        bonus = 0.015*(profit-60);
    }
    if (profit > 100){
        bonus = 0.01*(profit-100);
    }
    bonus = bonus*10000;
    printf("%.2f",bonus);
    return 0;
}
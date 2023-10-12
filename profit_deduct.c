#include<stdio.h>
int main(){
    int profit;
    double bonus;
    printf("Please enter a monthly profit:");
    scanf("%d",&profit);
    profit = profit/10000;
    if (profit <= 10){
        bonus = profit*0.1;
    }
    if (10 < profit <= 20){
        bonus = 10*0.1+(profit-10)*0.075;
    }
    if (20 < profit <= 40){
        bonus = 10*0.1+10*0.075+(profit-20)*0.05;
    }
    if (40 < profit <= 60){
        bonus = 10*0.1+10*0.075+20*0.05+(profit-40)*0.03;
    }
    if (60 < profit <= 100){
        bonus = 10*0.1+10*0.075+20*0.05+20*0.03+(profit-60)*0.015;
    }
    if (profit > 100){
        bonus = 10*0.1+10*0.075+20*0.05+20*0.03+40*0.015+(profit-100)*0.01;
    }
    bonus = bonus*10000;
    printf("%.2f",bonus);
    return 0;
}
#include <stdio.h>
int main(){
    int total;
    int year,month,day;
    int days_leap[12] ={31,29,31,30,31,30,31,31,30,31,30,31};
    int days_normal[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("\n\nEnter 3 integers representing year,month and day seperated with space: ");
    scanf("%d %d %d",&year,&month,&day);
    total = 0;
    if (year % 4 == 0 && year % 100 !=0){
        while (month-2>=0){
            total = total + days_leap[month-2];
            month--;
        }
    }
    // if (year % 400 == 0){
    //     while (month-2>=0){
    //         total = total + days_leap[month-2];
    //         month--;
    //     }
    // }
    else{
        if (year % 400 == 0){
            while (month-2>=0){
                total = total + days_leap[month-2];
                month--;
            }
        }
        else{
            while (month-2>=0){
                total = total + days_normal[month-2];
                month--;
            }
        }
    }
    total=total+day;
    printf("%d",total);
    return 0;
}
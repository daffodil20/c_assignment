#include <stdio.h>
int main()
{
    int d1, d2;
    int year,month,day;
    int days_leap[12] ={31,29,31,30,31,30,31,31,30,31,30,31};
    int days_normal[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("\n\nEnter 3 integers representing year,month and day seperated with space: ");
    scanf("%d %d %d",&year,&month,&day);
    d1=0;
    if (year % 4 == 0 && year % 100 !=0)
    {
        while (month-2>=0)
        {
            d1 = d1 + days_leap[month-2];
            month--;
        }
        d2 = d1 + day;
    }
    if (year % 400 == 0)
    {
        while (month-2>=0)
        {
            d1 = d1 + days_leap[month-2];
            month--;
        }
        d2 = d1 + day;
    }
    else
    {
        while (month-2>=0)
        {
            d1 = d1 + days_normal[month-2];
            month--;
        }
        d2 = d1 + day;
    }
    printf("%d",d2);
    return 0;
}
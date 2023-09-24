#include <stdio.h>
int main()
{
    int d1, d2, i;
    int days_leap[12] ={30,29,31,30,31,30,31,31,30,31,30,31};
    int days_normal[12]={30,28,31,30,31,30,31,31,30,31,30,31};
    printf("\n\nEnter 3 integers representing year,month and day seperated with space: ");
    int year,month,day;
    // year=0
    // month=0
    // day=0
    scanf("%d %d %d",&year,&month,&day);
    if (year % 4 == 0 && year % 100 !=0)
    {
        // int days_leap[12], d1, d2, i;
        // days_leap ={30,29,31,30,31,30,31,31,30,31,30,31};
        // m = days[month-1]
        d1=0;
        for (i=1;i<13;i++)
        {
            d1=d1+days_leap[i-1];
        }
        d2=d1+day;
    }
    if (year % 400 == 0)
    {
        // int days_leap[12], d1, d2, i;
        // days_leap ={30,29,31,30,31,30,31,31,30,31,30,31};
        // m = days[month-1]
        d1=0;
        for (i=1;i<13;i++)
        {
            d1=d1+days_leap[i-1];
        }
        d2=d1+day;
    }
    else
    {
        // int days_normal[12], d1, d2, i;
        // days_normal={30,28,31,30,31,30,31,31,30,31,30,31};
        // m = days[month-1]
        d1=0;
        for (i=1;i<13;i++)
        {
            d1=d1+days_normal[i-1];
        }
        d2=d1+day;
    }
    printf("%d",d2);
    return 0;
}